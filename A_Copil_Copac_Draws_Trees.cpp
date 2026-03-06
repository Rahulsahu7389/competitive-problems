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

vector<ll> vis;

void dfs(ll i , vector<vector<ll>> & adj,map<pair<ll,ll>,ll>& idx,vector<ll> &dp ,ll par){
    vis[i] = 1;

    for(auto val:adj[i]){

        if(val == par) continue;   // FIX

        if(vis[val] == 0){

            if(idx[{par,i}] < idx[{i,val}]){
                dp[val] = dp[i];
            }
            else{
                dp[val] = dp[i] + 1;
            }

            dfs(val,adj,idx,dp,i);
        }
    }
}

void solve(){
    ll n;
    cin>>n;

    vector<vector<ll>> adj(n+1);
    map<pair<ll,ll>,ll> idx;

    vis.assign(n+1,0);

    for (ll i = 0; i < n-1; i++){
        ll a,b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);

        idx[{a,b}] = i;
        idx[{b,a}] = i;
    }

    vector<ll> dp(n+1,0);

    dp[1] = 1;
    idx[{0,1}] = -1;

    dfs(1,adj,idx,dp,0);

    ll ans = *max_element(dp.begin(),dp.end());

    cout<<ans<<endl;
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



////solution alternative 

//without vis

void dfs(ll i , vector<vector<ll>> & adj,map<pair<ll,ll>,ll>& idx,vector<ll> &dp ,ll par){
    
    for(auto val:adj[i]){
        if(val == par) continue;
       

        if(idx[{par,i}]<idx[{i,val}]){
            dp[val] = dp[i];
        }
        else{
            dp[val] = dp[i]  +1;
        }
        // dbg(i,dp[i])
        dfs(val,adj,idx,dp,i);
        
    }
}

void solve(){
   //your code starts from here
   ll n;
   cin>>n;
   vector<vector<ll>> adj(n);
   map<pair<ll,ll>,ll> idx;
 
   
   for (ll i = 0; i < n-1; i++)
   {
    ll a,b;
    cin>>a>>b;
    a--;b--;
    adj[a].push_back(b);
    adj[b].push_back(a);

    idx[{a,b}] = i;
    idx[{b,a}] = i;
   }
   vector<ll> dp(n,0);//number of iteration required to activate the node i
   dp[0] = 1;
   idx[{-1,0}] = -1;

//    dbg(idx)
   dfs(0,adj,idx,dp,-1);
   ll ans = *max_element(all(dp));
//    dbg(adj)
//    dbg(dp)
   cout<<ans<<endl;
   

   


   
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
