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
bool DEBUG_MODE = false;  // toggle before submission

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

void solve(){
   //your code starts from here
   ll n,a,b;
   cin>>n>>a>>b;
   vector<ll> v(n+1);
   for (ll i = 1; i <=n; i++)
   {
    cin>>v[i];
   }
   vector<ll> dis(n+1);
   dis[1] = v[1];
   for (ll i = 2; i <=n; i++)
   {
    dis[i] = v[i] - v[i-1];
   }
   dbg(dis)
   vector<ll> suff(n+2);
   ll val = 1;
   for (int i = n; i >= 1; i--)
   {
    suff[i] = dis[i]*val*b;//conquering
    val++;
   }
   dbg(suff)
   //build the suff 
   for (int i = n; i >= 1; i--)
   {
    suff[i] = suff[i+1] + suff[i];
   }
   //building prefix
   vector<ll> pre(n+1);
   ll offset = a +b;
   for (ll i = 1; i <= n; i++)
   {
    pre[i] = offset*(dis[i]);
   }
   dbg(pre)
   //build
   for (ll i = 1; i <=n; i++)
   {
    pre[i] = pre[i-1] + pre[i];
   }

   // final
   ll ans = suff[1];
   for (ll i = 1; i <=n; i++)
   {
    ll sum = pre[i] + suff[i+1];
    ans = min(ans,sum);
   }
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
