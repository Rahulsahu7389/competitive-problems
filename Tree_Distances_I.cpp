#include <bits/stdc++.h>
using namespace std;

#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++) 
#define FORLL(a, c) for (long long(a) = 0; (a) < (c); (a)++) 
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--) 
typedef long long int ll; 
typedef vector<int> vi; 
typedef pair<int, int> pi; 
#define all(a) a.begin(),a.end()
#define F first 
#define S second 
#define pb push_back 
#define pob pop_back 
ll MOD = 1e9 + 7;

// ======== DEBUG SYSTEM ========
bool DEBUG_MODE = true;  // toggle before submission

template<typename T> void _print(const T &x) { cerr << x; }
template<typename T1, typename T2> void _print(const pair<T1, T2> &p) { cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}"; }
template<typename T> void _print(const vector<T> &v) { cerr << "["; for (auto &i : v) { _print(i); cerr << " "; } cerr << "]"; }
template<typename T> void _print(const set<T> &s) { cerr << "{"; for (auto &i : s) { _print(i); cerr << " "; } cerr << "}"; }
template<typename T> void _print(const multiset<T> &s) { cerr << "{"; for (auto &i : s) { _print(i); cerr << " "; } cerr << "}"; }
template<typename K, typename V> void _print(const map<K, V> &m) { cerr << "{"; for (auto &p : m) { _print(p.first); cerr << "->"; _print(p.second); cerr << " "; } cerr << "}"; }

// Variadic template for multiple args
void dbg_out() { cerr << "\n"; }
template<typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) { _print(H); if(sizeof...(T)) cerr << " | "; dbg_out(T...); }

#define dbg(...) if(DEBUG_MODE){ cerr << "[" << __LINE__ << "] " << #__VA_ARGS__ << " = "; dbg_out(__VA_ARGS__); }

// ======== UTILITY FUNCTIONS ========
template<typename T>
T mod(T a){ return (a<0)? -a : a; }

template<typename T>
T power(T x,T n){
  T pro = 1;
  while(n!=0){
    if(n%2==1) pro *= x;
    x *= x;
    n /= 2;
  }
  return pro;
}

vector<ll> indp,outdp,parent;
void dfs1(int node ,int par, vector<vector<int>> &adj){
    int sm = 0;
    parent[node] = par;
    for(auto val:adj[node]){
        if(par == val) continue;
        dfs1(val,node,adj);
        sm = max(1+indp[val],(ll)sm);
    }
    indp[node] =sm;
}

// void dfs2(int node,int par ,vector<vector<int>> &adj){

//     ll maxi = 0,secmaxi = 0;
//     int e1 = -1,e2 =-1;
//     if(par != -1){
//         for(auto val:adj[par]){
//             if(val == parent[par]) continue;
//             ll t = 1+indp[val];
//             if(t>=maxi){
//                 e2 =e1;
//                 e1 = val;
//                 secmaxi = maxi;
//                 maxi =t;

//             }
//             else if(t>secmaxi){
//                 secmaxi =t;
//                 e2 = val;
//             }
//         }
//         // dbg(node,e1,e2,maxi,secmaxi)
//         if(e1 == node){
//             outdp[node] = max(1+outdp[par],1+secmaxi);
//         }
//         else{
//             outdp[node] = max(1+outdp[par],1+maxi);

//         }
//     }
//     else{
//         outdp[node] =0;
//     }
//     for(auto val:adj[node]){
//         if(val == par) continue;
//         dfs2(val,node,adj);
//     }
// }
void dfs2(int node, int par, vector<vector<int>> &adj) {
    ll maxi = 0, secmaxi = 0;
    
    // 1. Find the top 2 in-DP values among the CURRENT node's children
    for (auto val : adj[node]) {
        if (val == par) continue;
        ll t = 1 + indp[val];
        if (t >= maxi) {
            secmaxi = maxi;
            maxi = t;
        } else if (t > secmaxi) {
            secmaxi = t;
        }
    }

    // 2. Push the calculated out-DP down to the children, then recurse
    for (auto val : adj[node]) {
        if (val == par) continue;
        
        // If this child provided the maximum path, it must use the second maximum
        if (1 + indp[val] == maxi) {
            outdp[val] = max(1 + outdp[node], 1 + secmaxi);
        } else {
            outdp[val] = max(1 + outdp[node], 1 + maxi);
        }
        
        dfs2(val, node, adj);
    }
}

void solve(){
   //your code starts from here
   ll n;
   cin>>n;
   vector<vector<int>> adj(n+1);
   indp.assign(n+1,0);
   outdp.assign(n+1,0);
   parent.assign(n+1,0);
   for (ll  i = 0; i < n-1 ; i++)
   {
    ll a,b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
   }
   dfs1(1,-1,adj);
   dfs2(1,-1,adj);
//    dbg(indp);
//    dbg(outdp)
   for (ll  i = 1; i <=n ; i++)
   {
    cout<<max(indp[i],outdp[i])<<" ";
   }
   cout<<endl;
   

   
}

int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    // ll T; 
    // cin >> T; 
    // while (T--) { 
        solve(); 
    // } 
    return 0; 
}
