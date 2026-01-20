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

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> a(n), b(m);
    set<ll> spikes;

    for (ll &x : a) cin >> x;
    for (ll &x : b) {
        cin >> x;
        spikes.insert(x);
    }

    string s;
    cin >> s;

    // (distance, robot_index)
    set<pair<ll,ll>> before;
    set<pair<ll,ll>> after;

    vector<pair<ll,ll>> p(n);

    // -------- PREPROCESS ----------
    for (ll i = 0; i < n; i++) {
        auto it = spikes.upper_bound(a[i]);

        ll bef = LLONG_MAX, aft = LLONG_MAX;

        if (it != spikes.end())
            aft = *it - a[i];

        if (it != spikes.begin()) {
            --it;
            bef = a[i] - *it;
        }

        p[i] = {bef, aft};
        before.insert({bef, i});
        after.insert({aft, i});
    }

    // -------- SIMULATION ----------
    ll val = 0;
    ll ans = n;

    for (ll step = 0; step < k; step++) {
        if (s[step] == 'R') val++;
        else val--;

        if (val > 0) {
            while (!after.empty() && after.begin()->first <= val) {
                ll idx = after.begin()->second;   // robot index
                after.erase(after.begin());

                
                before.erase({p[idx].first, idx});

                ans--;
            }
        } else {
            while (!before.empty() && before.begin()->first <= -val) {
                ll idx = before.begin()->second;  // robot index
                before.erase(before.begin());

                
                after.erase({p[idx].second, idx});

                ans--;
            }
        }

        cout << ans << " ";
    }

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
