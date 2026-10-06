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
template<typename T> void _print(const unordered_set<T> &s) { cerr << "{"; for (auto &i : s) { _print(i); cerr << " "; } cerr << "}"; }
template<typename T> void _print(const multiset<T> &s) { cerr << "{"; for (auto &i : s) { _print(i); cerr << " "; } cerr << "}"; }
template<typename K, typename V> void _print(const map<K, V> &m) { cerr << "{"; for (auto &p : m) { _print(p.first); cerr << "->"; _print(p.second); cerr << " "; } cerr << "}"; }
template<typename K, typename V> void _print(const unordered_map<K, V> &m) { cerr << "{"; for (auto &p : m) { _print(p.first); cerr << "->"; _print(p.second); cerr << " "; } cerr << "}"; }

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
   ll n,k;
   cin>>n>>k;
    vector<ll> p(n+1),q(n+1);
    for (ll i = 1; i <=n; i++)
    {
        cin>>p[i];
    }
    for (ll i = 1; i <=n; i++)
    {
        cin>>q[i];
    }
    vector<ll> cycle_id(n+1,0),pos(n+1,0);
    ll cid = 0;
    vector<ll> seen(n+1);
    
    vector<vector<ll>> cnt(n+1);//length,p,value - cycle of len and can reach desired value at p steps have cnt value
    vector<ll> active;
    for (ll i = 1; i<=n; i++)
    {
        if(seen[i] == 1) continue;
        vector<ll> vis;
        ll curr = i;
        ll idx = 0;
        cid++;
        // Find the cycle
        while(!seen[curr]) {
            vis.push_back(curr);
            seen[curr] = 1;
            pos[curr] = idx++;
            cycle_id[curr] = cid;
            curr = p[curr];
        }

        ll cycle_length = vis.size();

        if (cnt[cycle_length].empty()) {
            cnt[cycle_length].assign(cycle_length, 0);
            active.push_back(cycle_length);
        }

        // Calculate distances
        for (auto val : vis) {
            ll b = q[val];
            // Check if desired computer 'b' is in the SAME cycle
            if (cycle_id[val]==cycle_id[b]) {
                // Calculate distance mathematically
                ll dist = (pos[b] - pos[val] + cycle_length) % cycle_length;
                cnt[cycle_length][dist]++;
            }
        }

    }
    
    ll ans = 0;

    for (ll i = 1; i <=k; i++)
    {
        ll value =0;
        for(auto val:active){
            ll offset = i%val;

            value += cnt[val][offset];
            
        }
        ans = max(ans,value);
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
