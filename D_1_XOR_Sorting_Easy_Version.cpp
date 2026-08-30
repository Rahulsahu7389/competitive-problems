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

vector<ll> par,sizes;
ll findpar(ll u){
    if(u == par[u]) return u;
    return par[u] = findpar(par[u]);
}

void unionBysize(ll u ,ll v){
    ll ultiu = findpar(u);
    ll ultiv = findpar(v);
    if(ultiu == ultiv) return;
    if(sizes[ultiu]<sizes[ultiv]){
        sizes[ultiv] += sizes[ultiu];
        par[ultiu] = ultiv;
    }
    else{
        sizes[ultiu] += sizes[ultiv];
        par[ultiv] = ultiu;
    }
}

void solve() {
    ll n, q;
    cin >> n >> q;
    vector<ll> v(n);
    bool b = 1;
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
        if(i > 0 && v[i] < v[i-1]) b = 0;
    }
    if(b) {
        cout << 0 << "\n";
        return;
    }
    ll anss = 0;
    bool ok = 0;
    for (ll i = 1; i < 21; i++) {
        ll gap = (1LL << i);
        bool ans = 1;
        for (ll j = 0; j + gap < n; j += gap) {
            ll mx = 0;
            for (ll k = j; k < j + gap && k < n; k++) {
                mx = max(mx, v[k]);
            }
            ll mn = LLONG_MAX; 
            for(ll k = j + gap; k < j + 2 * gap && k < n; k++) {
                mn = min(mn, v[k]);
            }
            if(mx > mn) {
                ans = 0;
                break;
            }
        }
        if(ans) {
            ok = 1;
            anss = (1LL << (i - 1));
            break;
        }
    }
    if(ok) cout << anss << "\n";
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
