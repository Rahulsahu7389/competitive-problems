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

ll primeFactorisation(ll n){
    ll mini = 1e15;
    for (ll i = 2; i*i <=n; i++)
    {
        while(n%i == 0){
            mini = min(mini,i);
            n /= i;
        }
    }
    
    if(n!=1){
        mini = min(mini,n);
    }
    return mini;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Step 1: Sort and remove duplicates to form our clean set A
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    
    n = a.size(); // Update n to the unique size
    vector<bool> covered(n, false);
    vector<ll> b;

    // Step 2: Sweep through the array
    for (int i = 0; i < n; i++) {
        if (covered[i]) continue; // Already covered by a smaller valid divisor

        ll x = a[i];
        b.push_back(x);

        // Phase 3: The Pigeonhole Defense (O(1) TLE prevention)
        if (k / x > n) {
            cout << -1 << "\n";
            return;
        }

        // Verify all multiples and mark them as covered
        for (ll m = x; m <= k; m += x) {
            auto it = lower_bound(a.begin(), a.end(), m);
            
            // If the multiple is missing, x is an invalid generator
            if (it == a.end() || *it != m) {
                cout << -1 << "\n";
                return;
            }
            
            // Mark the found multiple as covered
            int idx = distance(a.begin(), it);
            covered[idx] = true;
        }
    }

    // If we survived the loop, we found our minimal set!
    cout << b.size() << "\n";
    for (ll val : b) {
        cout << val << " ";
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
