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

vector<ll> depth;
ll ans;
void dfs(ll u , vector<vector<ll>> &adj,vector<ll>&vis){
    vis[u] = 1;
    int childs = 0;
    ll maxi = -1e9;
    ll max2 = -1e9;
    for(auto val:adj[u]){
        if(vis[val]==0){
            childs++;
            dfs(val,adj,vis);
            if(maxi<depth[val]){
                max2 = maxi;
                maxi = depth[val];
            }
            else if(max2<depth[val]){
                max2 = depth[val];
            }
        }
    }
    if(childs>1){
        ans += max2;
        // dbg(u,ans)
        depth[u] = maxi + 1;
    }
    else if(childs==1){
        depth[u] = maxi+1;
    }
    else{
        depth[u] = 1;
    }
}

void solve(){
   //your code starts from here
   ll n;
   cin>>n;
   vector<vector<ll>> adj(n+1);
   for (ll i = 2; i <=n; i++)
   {
    ll a;
    cin>>a;
    adj[i].push_back(a);
    adj[a].push_back(i);
   }
   depth.assign(n+1,0);
   ans = n;
   vector<ll> vis(n+1);
   dfs(1,adj,vis);
   cout<<ans<<endl;
//    for (ll i = 1; i <=n; i++)
//    {
//     cout<<i<<" "<<depth[i]<<endl;
//    }
   
   

   
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
