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


vector<int> state; // 0 = unvisited, 1 = active, 2 = finished
vector<int> parent;
bool found_target_cycle = false;

void dfs(int u, int p, vector<vector<ll>> &adj,ll &clen) {
    if (found_target_cycle) return; // Stop if we already found what we want

    state[u] = 1; // Mark as currently active (ancestor)
    parent[u] = p;

    for (auto v : adj[u]) {
        if (v == p) continue; // Skip parent

        if (state[v] == 0) {
            dfs(v, u, adj,clen);
        } 
        else if (state[v] == 1) { 
            // AHA! We found a back-edge to an ANCESTOR.
            // Tracing is 100% safe here. No infinite loops.
            
            vector<int> cycle;
            int curr = u;
            while (curr != v) {
                cycle.push_back(curr);
                curr = parent[curr];
            }
            cycle.push_back(v);

            clen = max((ll)cycle.size(),clen);
        }
        // If state[v] == 2, we ignore it completely. It's a descendant.
    }
    
    state[u] = 2; // Mark as completely finished
}
void solve(){
   //your code starts from here
   ll n,m;
   cin>>n>>m;
   vector<vector<ll>> adj(n);
   parent.assign(n,-1);
   state.assign(n,0);
   for (ll  i = 0; i < m ; i++)
   {
    ll a,b;
    cin>>a>>b;
    a--;b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
   }
   ll ans = 0;
   for (ll  i = 0; i < n ; i++)
   {
    if(adj[i].size()==0){
        cout<<"Brain Melt\n";
        return;
    }
   }

   //checking if leaf node
   unordered_set<ll> f;
   for (ll  i = 0; i < n ; i++)
   {
    if(adj[i].size()==1){
        for(auto val:adj[i]){
            f.insert(val);
        }
    }
   }
   if(f.size()>1){
    cout<<"Many\n";
    return;
   }

//    vis.assign(n,0);
//    dbg("hree")

   for (ll  i = 0; i < n ; i++)
   {
    if(state[i]==0){
        ll clen = 0;
        found_target_cycle = false;
        dfs(i,-1,adj,clen);
        // dbg(i,clen);
        if(clen >2){
            cout<<"Many\n";
            return;
        }

    }
   }
   cout<<2<<endl;
   

   


   
   
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
