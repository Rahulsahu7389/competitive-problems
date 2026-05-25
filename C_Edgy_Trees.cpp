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
ll Mod = 1000000007;

void bfs(ll i , vector<ll> &vis, vector<ll> & elem ,vector<vector<vector<ll>>> &adj){
    queue<ll> q;
    q.push(i);
    vis[i] = 1;
    ll cnt = 0;
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        vis[it] = 1;
        cnt++;
        for(auto val:adj[it]){
            if(vis[val[0]]==0){
                q.push(val[0]);
                vis[val[0]] = 1;
            }
        }
    }
    // dbg(cnt)
    if(cnt>1){

        elem.push_back(cnt);
    }
}

void solve(){
   //your code starts from here
   ll n , k;
   cin>>n>>k;
   ll total = 1;
   //get total
   for (ll i = 0; i < k; i++)
   {
    total = (total*n)%Mod;
   }
   vector<vector<ll>> p;
   vector<vector<vector<ll>>> adj(n);
   ll cnter = 0;
   for (ll i = 0; i < n-1; i++)
   {
    ll a,b,c;
    cin>>a>>b>>c;
    a--;b--;
    p.pb({a,b,c});
    if(c == 0){
        cnter++;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
   }
//    if(cnter==n-1){
//     cout<<0<<endl;//no black edge
//     return;
//    }
   vector<ll> vis(n);
   vector<ll> elem;
   for (ll i = 0; i < n; i++)
   {
    if(vis[i]==0){

        bfs(i, vis,elem,adj);
    }
   }
   total = (total - n + Mod)%Mod;
//    dbg(total)

   for(auto val:elem){
    ll pwr = power(val,k,Mod);
    pwr = (pwr - val + Mod)%Mod;
    // dbg(pwr)
    total = (total - pwr + Mod)%Mod;
    
   }

   cout<<total<<endl;
   
   

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
