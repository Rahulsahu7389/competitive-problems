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

void dfs(int node , int par , vector<int>&r , vector<int>&b ,vector<int>&vis,int col,vector<vector<int>>&adj){
    vis[node] =1;
    if(col) r.push_back(node);
    else b.push_back(node);
    for(auto val:adj[node]){
        if(par == val) continue;
        if(vis[val]==0){
            dfs(val,node,r,b,vis,1-col,adj);
        }
    }

}

void solve(){
   ll k;
   cin>>k;
   
   vector<int> sizes(k + 1);
   vector<vector<vector<int>>> adj(k + 1);
   
   // 1. Read ALL trees first
   for (ll i = 1; i <= k ; i++) {
       cin >> sizes[i];
       adj[i].resize(sizes[i] + 1);
       for (int j = 0; j < sizes[i] - 1 ; j++) {
           ll a, b;
           cin >> a >> b;
           adj[i][a].push_back(b);
           adj[i][b].push_back(a);
       }
   }
   
   // 2. Find a valid hub (a tree with at least 1 edge)
   ll t1 = 1, v1 = 1; // Default fallback if ALL trees are just n=1
   for (ll i = 1; i <= k; i++) {
       if (sizes[i] > 1) {
           t1 = i;
           // Find a leaf and pick its parent
           for(int j = 1; j <= sizes[i]; j++) {
               if(adj[i][j].size() == 1) {
                   v1 = adj[i][j][0]; // parent of the leaf
                   break;
               }
           }
           break; // We found our sacrificial hub, stop looking!
       }
   }
   
   // 3. Connect all other trees to the hub
   for (ll i = 1; i <= k; i++) {
       if (i != t1) {
           // Connect node 1 of the other trees to the sacrificial node
           cout << t1 << " " << v1 << " " << i << " " << 1 << "\n";
       }
   }
}

int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    ll T; 
    cin >> T; 
    while (T--) { 
        solve(); 
    } 
    return 0; 
}
