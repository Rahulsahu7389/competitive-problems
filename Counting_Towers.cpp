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
const ll MOD = 1e9 + 7;

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

int dp[1000005][2];
//0 means extend the two vertical pillars 
//1 measn extend the horizontal bar
ll fun(ll i , ll type , ll n){
    if(i == n){
        return 1;//only closing option you have here
    }
    if(dp[i][type]!=-1){
        return dp[i][type];
    }
    ll val = 0;
    if(type == 0){
        val = (val + 4*fun(i+1,0,n))%MOD;
        val = (val + fun(i+1,1,n))%MOD;
        // dp[i][0] = val;
    }
    else{
        val = (val + 2*fun(i+1,1,n))%MOD;
        val = (val + fun(i+1,0,n))%MOD;
        // dp[i][1] = val;
    }
    return dp[i][type]=val;
}

void precompute(ll n){
    memset(dp,0,sizeof(dp));
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (ll i = 2;i<=n;i++)
    {
        ll val = 0;
        val = (val + 4LL*dp[i-1][0])%MOD;
        val = (val + dp[i-1][1])%MOD;
        dp[i][0] += val;
        val = 0;
        val = (val + 2LL*dp[i-1][1])%MOD;
        val = (val + dp[i-1][0])%MOD;
        dp[i][1] += val;
    }
}

void solve(){
   //your code starts from here
   ll n;
   cin>>n;
   
//    ll ans = (fun(1,0,n) + fun(1,1,n))%MOD;
//    cout<<ans<<endl;
    ll ans = 0;
    
    cout<<(dp[n][1] + dp[n][0])%MOD<<endl;
    
}

int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    precompute(1000001);
    ll T; 
    cin >> T; 
    while (T--) { 
        solve(); 
    } 
    return 0; 
}
