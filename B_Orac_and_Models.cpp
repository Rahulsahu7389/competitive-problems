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

ll fun(ll i,vector<ll> & v,vector<ll>& dp){

    if(dp[i] !=-1){
        return dp[i];
    }
    ll ans = 1;
    for(int j=1;j*j<=i;j++){
        if(i%j!=0) continue;
        if(v[i]>v[j]){
            ans = max(ans, 1 + fun((j),v,dp));
        }
        if(v[i]>v[i/j]){
            ans = max(ans, 1 + fun((i/j),v,dp));
        }
    }
    return dp[i] = ans;

}

void solve(){
   //your code starts from here
   ll n;
   cin>>n;
   vector<ll> v(n+1);
   for (ll i = 1; i <=n; i++)
   {
    cin>>v[i];
   }
   vector<ll> dp(n+1,-1);
   ll best = 0;
   for(int i = 1;i<=n;i++){// there could be multiple value possible so iterate to find
    best = max(best , fun(i,v,dp));
   }

    cout<<best<<endl;
   
   
   

}

void solve2(){
    //tabulation
    ll n;
   cin>>n;
   vector<ll> v(n+1);
   for (ll i = 1; i <=n; i++)
   {
    cin>>v[i];
   }
   vector<ll> dp(n+1,1);
   ll best = 0;
   for(int i = 1;i<=n;i++){// there could be multiple value possible so iterate to find
    ll ans = 1;
    for(int j=1;j*j<=i;j++){
        if(i%j!=0) continue;
        if(v[i]>v[j]){
            ans = max(ans, 1 + dp[j]);
        }
        if(v[i]>v[i/j]){
            ans = max(ans, 1 + dp[i/j]);
        }
        dp[i] = max(ans,dp[i]);
    }
    best = max(best,ans);
   }

    cout<<best<<endl;
}

int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    ll T; 
    cin >> T; 
    while (T--) { 
        solve2(); 
    } 
    return 0; 
}
