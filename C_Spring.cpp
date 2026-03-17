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

ll noofday(ll a , ll m , ll d){
    return m/d;
}

ll lcm(ll a, ll b){
    ll val = __gcd(a,b);
    return ((a*b)/val);
}

void solve(){
   ll x,y,z,m;
   cin>>x>>y>>z>>m;

   ll aday = (x<=m)?noofday(x,m,x):0;
   ll bday = (y<=m)?noofday(y,m,y):0;
   ll cday = (z<=m)?noofday(z,m,z):0;

   ll lcmab = lcm(x,y);
   ll lcmbc = lcm(z,y);
   ll lcmac = lcm(x,z);
   

   ll aib = (lcmab<=m)?noofday(lcmab,m,lcmab):0;
   ll bic = (lcmbc<=m)?noofday(lcmbc,m,lcmbc):0;
   ll aic = (lcmac<=m)?noofday(lcmac,m,lcmac):0;

   ll val1 = lcm(x,y);
   ll val2 = lcm(z,val1);

   ll g = (val2<=m)?noofday(val2,m,val2):0;

   ll d = aib - g;
   ll e = aic - g;
   ll f = bic - g;

   ll a = aday - e - g - d;
   ll b = bday - d - g - f;
   ll c = cday - g - e - f;

   ll ans1 = a*6 + (d + e)*3 + g*2;
   ll ans2 = b*6 + (d + f)*3 + g*2;
   ll ans3 = c*6 + (e + f)*3 + g*2;

   cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;
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
