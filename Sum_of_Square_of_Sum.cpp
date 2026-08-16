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
const ll MOD = 998244353;

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
ll power(ll x, ll n, ll mod) {
    ll pro = 1;
    x %= mod; // Ensure base is within mod bounds
    if (x < 0) x += mod; // Correct negative bases
    
    while (n > 0) {
        if (n % 2 == 1) {
            pro = (pro * x) % mod;
        } 
        x = (x * x) % mod;
        n /= 2;
    }
    return pro;
}


ll inverse(ll a, ll mod){
    return power(a,mod-2*1LL,mod);
}

ll nCr(ll n,ll r, ll mod){
    if(r<0 || r>n) return 0;
    if(r==0 || r == n) return 1;
    if(r> n -r) r = n-r;
    ll num = 1;
    ll den = 1;
    for (ll i = 0; i < r; i++)
    {
        num = (num*(n-i))%mod;
        den = (den*(i+1))%mod;
    }
    // dbg(num,den)
    ll inv = inverse(den,mod);
    return (num*inv)%mod;
}
ll add(ll a,ll b){
  return (a+b)%MOD;
}
ll mul(ll a ,ll b){
  return (a*b)%MOD;
}
void solve(){
   //your code starts from here
   ll n,k;
   cin>>n>>k;
   vector<ll> v(n);
   for (ll i = 0; i < n; i++)
   {
    cin>>v[i];
   }

   ll n1ck1 = nCr(n-1,k-1,MOD);
   ll n2ck2 = nCr(n-2,k-2,MOD);

   ll squsum = 0;
   ll presum = v[0];
   ll absum = 0;
   squsum = add(squsum,mul(v[0],v[0]));
   for (ll i = 1; i < n; i++)
   {
    squsum = add(squsum,mul(v[i],v[i]));
    ll sm = mul(presum,v[i]);
    absum = add(absum,sm);
    presum = add(presum,v[i]);

   }

   ll ans = mul(n1ck1,squsum);
   ans = add(ans,mul(2,mul(n2ck2,absum)));
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
