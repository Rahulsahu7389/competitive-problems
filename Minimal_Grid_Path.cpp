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
    ll n;
    cin >> n;
    vector<string> v(n);
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    string ans = "";
    vector<vector<ll>> vis(n, vector<ll>(n, 0));
    
    queue<pair<ll,ll>> q;
    q.push({0,0});
    ans.push_back(v[0][0]);
    vis[0][0] = 1;
    
    for (ll j = 0; j < 2 * n - 1 && !q.empty(); j++) {
        ll sz = q.size();
        if (sz == 0) continue;
        
        vector<vector<pair<ll,ll>>> p(26);
        ll mini = 27;
        bool ok = false;
        
        for (ll i = 0; i < sz; i++) {
            auto it = q.front();
            ll x = it.first;
            ll y = it.second;
            q.pop();
            
            if (x == n - 1 && y == n - 1) {
                ok = true;
                break;
            }
            
            if (y + 1 < n) {
                ll t = y + 1;
                mini = min(1LL * (v[x][t] - 'A'), mini);
                p[v[x][t] - 'A'].push_back({x, t});
            }
            if (x + 1 < n) {
                ll t = x + 1;
                mini = min(1LL * (v[t][y] - 'A'), mini);
                p[v[t][y] - 'A'].push_back({t, y});
            }
        }
        
        if (ok) break;
        if (p[mini].size() == 0) continue;
        
        for (auto val : p[mini]) {
            if (vis[val.first][val.second] == 0) {
                vis[val.first][val.second] = 1; 
                q.push(val);
            }
        }
        
        ans.push_back((char)(mini + 'A'));
    }
    
    cout << ans << "\n";
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
