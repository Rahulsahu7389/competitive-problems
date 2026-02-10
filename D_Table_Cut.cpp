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

void solve(){
    ll n , m;
    cin >> n >> m;

    vector<vector<ll>> v(n, vector<ll>(m));
    ll cnt = 0;

    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin >> v[i][j];
            if(v[i][j] == 1) cnt++;
        }
    }

    ll x = cnt / 2;

    // compute row sums
    vector<ll> row(n, 0);
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            row[i] += v[i][j];
        }
    }

    ll pref = 0;
    ll R = 0;

    // full rows first
    while(R < n && pref + row[R] <= x){
        pref += row[R];
        R++;
    }

    // now R is the partial row (if any)
    ll c = m; // start of suffix
    if(pref < x){
        ll need = x - pref;

        ll got = 0;
        for(ll j = m-1; j >= 0; j--){
            if(v[R][j] == 1) got++;
            if(got == need){
                c = j;
                break;
            }
        }
    }

    ll a = x;
    ll b = cnt - x;

    cout << a * b << "\n";

    // restore path
    // go down R rows
    for(ll i=0;i<R;i++) cout << 'D';

    // go right to column c
    for(ll j=0;j<c;j++) cout << 'R';

    // if there is a partial row
    if(R < n){
        cout << 'D';
    }

    // go right to the end
    for(ll j=c;j<m;j++) cout << 'R';

    // go down to the end
    for(ll i=R+1;i<n;i++) cout << 'D';

    cout << "\n";
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
