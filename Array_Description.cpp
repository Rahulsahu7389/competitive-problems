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
int dp[102][100004];
ll fun(ll i , ll num , vector<ll> &v ,ll n, ll m){
    if(i == n){
        return 1;
    }
    if(dp[num][i]!=-1){
        return dp[num][i];
    }
    //choices
    ll l = max(1LL,num-1);
    ll r = min(m,num+1);
    ll val =0;
    if(v[i]==0){

        for (ll j = l; j <=r; j++)
        {
            val = (val + fun(i+1,j,v,n,m))%MOD;
            // dbg(i,j,val);
        }
    }
    else{
        if(abs(v[i]-num)<=1){
            val = (val + fun(i+1,v[i],v,n,m))%MOD;
            
        }
    }
    return dp[num][i]= val;
    
}

void solve(){
   //your code starts from here
   ll n,m;
   cin>>n>>m;
   vector<ll> v(n);
   for (ll i = 0; i < n; i++)
   {
    cin>>v[i];
   }
   memset(dp,-1,sizeof(dp));
   ll ans = 0;
   if(v[0]==0){
    ll l = 1;
    ll r = m;
    
    for (ll j = l; j <=r; j++)
    {
        ans = (ans + fun(1,j,v,n,m))%MOD;
        // dbg(j,ans)
    }
    
   }
   else{
    ll l = max(1LL,v[0]-1);
    ll r = min(m,v[0]+1);
    ll val =0;
   
    ans = (ans + fun(1,v[0],v,n,m))%MOD;
    
    
   }
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
