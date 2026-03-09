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
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> v(n);
    
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    x--; y--;
    ll l = x + 1;
    ll r = y;
    
    ll mini = 1e18;
    ll idx = -1;
    for (ll i = l; i <= r; i++) {
        if(mini > v[i]){
            mini = v[i];
            idx = i;
        }
    }
    
    
    
    ll d = (r - l + 1) - (idx - l);
    vector<ll> cent(r - l + 1, 0);
    ll tx = 0;
    for (ll i = l; i <= r; i++) {
        ll ind = (tx + d) % (r - l + 1);
        tx++;
        cent[ind] = v[i];
    }
    
   
    
    // 1. We combine the left prefix (before the 1st portal) and the right suffix 
    // (after the 2nd portal) into a single contiguous array D.
    // Because elements just pass between the ends of these two sections, 
    // their relative order to each other NEVER changes.
    vector<ll> D;
    for (ll i = 0; i < l; i++) {
        D.push_back(v[i]);
    }
    for (ll i = r + 1; i < n; i++) {
        D.push_back(v[i]);
    }

    // 2. Find the best place to insert `cent` into D.
    // We scan D from left to right to find the FIRST element strictly greater than cent[0].
    ll insert_idx = D.size(); // Default to the very end if nothing is greater
    for (ll i = 0; i < D.size(); i++) {
        if (cent[0] < D[i]) {
            insert_idx = i;
            break;
        }
    }

    // 3. Print the final answer in three parts:
    // Part A: Print D up to the insertion index
    for (ll i = 0; i < insert_idx; i++) {
        cout << D[i] << " ";
    }
    
    // Part B: Print the optimally rotated middle section
    for (auto val : cent) {
        cout << val << " ";
    }
    
    // Part C: Print the rest of D
    for (ll i = insert_idx; i < D.size(); i++) {
        cout << D[i] << " ";
    }
    cout << endl;
    
    
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
