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

vector<ll> values;
ll ans;
ll dfs(int node ,int par, vector<vector<int>>& adj){
    ll maxi= 0,secmaxi = 0;
    if(adj[node].size()==1 && par!=-1){
        // dbg(node)
        values[node]=0;
        return 0;
    }
    for(auto val:adj[node]){
        if(val == par) continue;
        ll sum =1LL+ dfs(val,node,adj);
        if(sum>=maxi){
            secmaxi = maxi;
            maxi = sum;
        }
        else if(sum>secmaxi){
            secmaxi = sum;
        }
    }
    ans =max(maxi+secmaxi,ans);
    values[node] = maxi;
    return maxi;

}

void solve(){
   //your code starts from here
   ll n;
   cin>>n;
   values.assign(n+1,0);
   vector<vector<int>> adj(n+1);
   ans =0;
   for (ll  i = 0; i < n-1; i++)
   {
    ll a,b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
   }
   dfs(1,-1,adj);
//    dbg(values)
   cout<<ans<<endl;

   
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
