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

void dijasktra(vector<vector<vector<ll>>> &adj,vector<ll> &dis){
    priority_queue<pair<ll,ll> ,vector<pair<ll,ll>> , greater<pair<ll,ll>>> q;//dist,node
    dis[1] = 0;
    q.push({0LL,1});
    
    while (!q.empty())
    {
        auto it = q.top();
        ll dist = it.first;
        ll node = it.second;
        q.pop();

        for(auto val:adj[node]){
            if(dis[val[0]]>dist + val[1]){
                dis[val[0]] = dist + val[1];
                q.push({dis[val[0]],val[0]});
            }
        }

    }


}


void solve(){
   //your code starts from here
   ll n,m,y;
   cin>>n>>m>>y;
   vector<vector<vector<ll>>> adj(n+1);//1 based
   for (ll i = 0; i < m; i++)
   {
    ll a,b,c;
    cin>>a>>b>>c;
    adj[a].push_back({b,c});
    adj[b].push_back({a,c});
   }
   vector<ll> v(n+1);
   for (ll i = 1; i <=n; i++)
   {
    cin>>v[i];
   }
   vector<ll> dis(n+1,1e15);
   dijasktra(adj,dis);
   dbg(dis)
   vector<ll> dp(n+1);
   dp[1] = dis[1];
   deque<ll> dq;
   for (ll i = 2; i <=n; i++)
   {
    
   }
   
   
   
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
