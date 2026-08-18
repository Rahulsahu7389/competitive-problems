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
template<typename T> void _print(const unordered_set<T> &s) { cerr << "{"; for (auto &i : s) { _print(i); cerr << " "; } cerr << "}"; }
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

void dfs(ll u,ll par ,vector<vector<ll>>&adj,unordered_set<ll>&st,vector<ll>&ans){
    for(auto val:adj[u]){
        if(par == val) continue;
        dfs(val,u,adj,st,ans);
        if(st.count(val)){
            ans.push_back(val);
        }
    }
}

void solve(){
   //your code starts from here
   ll n;
   cin>>n;
   vector<vector<ll>> adj(n+1);
   ll cnt = 2;
   for (ll i = 0; i < n-1; i++)
   {
    ll a;
    cin>>a;
    adj[cnt].push_back(a);
    adj[a].push_back(cnt);
    cnt++;
   }
//    dbg(adj)
   ll m;
   cin>>m;
   vector<ll> cam(m);
   unordered_set<ll> st;
   for (ll i = 0; i < m; i++)
   {
    cin>>cam[i];
    // st.insert(cam[i]);
   }
   sort(cam.rbegin(),cam.rend());
   for (ll i = 0; i < m-1; i++)
   {
    st.insert(cam[i]);
   }
//    dbg(st)
//    dbg(cam)
   vector<ll> ans;
   dfs(1,-1,adj,st,ans);
   cout<<ans.size()<<" ";
//    if(ans.size()==0)return;
   for(auto val:ans){
    cout<<val<<" ";
   }
   cout<<endl;


   
   
   
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
