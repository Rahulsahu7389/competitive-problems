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

ll Mod = 1e9 + 7;
vector<ll> fact(1e6+2);
// Clean, non-templated modular exponentiation
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
    ll val = power(a,mod-2*1LL,mod);
    return val;
}


void solve(){
   //your code starts from here
   ll a,b;
   cin>>a>>b;
//    cout<<fact[1]<<endl;
   ll num = fact[a];
   ll A = inverse(fact[a-b],Mod);
   ll B = inverse(fact[b],Mod);
   ll ans = ((num*A)%Mod*B)%Mod;
   cout<<ans<<endl;
}

int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    fact[0] = 1;
    for (ll i = 1; i <=1e6; i++)
    {
        fact[i] = (i*fact[i-1])%Mod;
    }
    // dbg(fact)
    
    ll T; 
    cin >> T; 
    while (T--) { 
        solve(); 
    } 
    return 0; 
}
