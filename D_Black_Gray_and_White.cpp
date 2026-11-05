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
const int MAXN = 300005;
const int LOG = 20; // log2(300000) is about 18.2, 20 is safe

vector<int> adj[MAXN];
int ancestor[MAXN][LOG];
int parent[MAXN]; 
int depth[MAXN];
// int n, cols;
int n,cols;

void dfs(int node,int par, int d){
    depth[node] =d;
    parent[node] = par;
    for(auto val:adj[node]){
        if(par == val) continue;
        dfs(val,node,d+1);
    }
}
void buildancestor(){
    for(int i = 1;i<=n;i++){
        ancestor[i][0] = parent[i];
    }
    for(int i = 1;i<cols;i++){
        for(int node=1;node<=n;node++){
            if(ancestor[node][i-1]==-1) continue;
            ancestor[node][i] = ancestor[ancestor[node][i-1]][i-1];
        }
    }
}
int getkthancestor(int k,int node){
    for(int i = 0;i<cols;i++){
        
        if((k&(1<<i))){
            node = ancestor[node][i];

            // cout<<i<<" "<<node<<endl;
            if(node==-1) return node;
            
        }
    }
    // cout<<"kth "<<node<<endl;
    return node;
}
int lca(int a ,int b){
    if(depth[a]>depth[b]){
        int diff = abs(depth[a]-depth[b]);
        // cout<<"here1\n";
        a= getkthancestor(diff,a);
    }
    else if(depth[a]<depth[b]){
        int diff = abs(depth[a]-depth[b]);
        // cout<<"here2\n";
        b = getkthancestor(diff,b);
    }
    // cout<<"yha\n";
    if(a==b) return a;
    for(int i = cols-1;i>=0;i--){//take bigger jumps first
        if(ancestor[a][i]==-1) continue;
        if(ancestor[a][i]!=ancestor[b][i]){
            a = ancestor[a][i];
            b = ancestor[b][i];
        }
    }
    // cout<<"lca is "<<ancestor[a][0]<<endl;
    return ancestor[a][0];


}

ll dist(int a,int b){
    ll d = depth[a] + depth[b] - 2*depth[lca(a,b)];
    return d;
}

bool check(int k){
    vector<int> vis(n+1,0);
    for (int  i = 1; i <=n; i++)
    {
        int a = k - i;
        if(a>=1 && a<=n && i!=a){
            vis[a] =1;
            vis[i] =1;
        }
    }
    int node =0;
    // dbg(vis)
    for(int i =1;i<=n;i++){
        if(!vis[i]){
            node =i;break;
        }
    }
    if(node ==0) return true;
    // dbg(node,vis)
    for (int  i = 1; i <=n; i++)
    {
        int a = k - i;
        if(a>=1 && a<=n && i!=a){
            int lai = lca(a,i);
            // int lvc = lca(node,lai);
            if (dist(i, a) == dist(i, node) + dist(node, a)){
                // dbg(i,a)
                return true;
            }
        }
    }
    return false;
    
}

void solve(){
   //your code starts from here
   cin >> n;
    cols = log2(n) + 2;
    
    // Fast O(N) cleanup for the current test case instead of vector.assign()
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        parent[i] = -1;
        for (int j = 0; j < cols; j++) {
            ancestor[i][j] = -1;
        }
    }
  
    for (ll  i = 0; i < n-1 ; i++)
    {
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if(n%2==0){
        cout<<n+1<<endl;return;
    }
    dfs(1,-1,0);
    buildancestor();
    // dbg("here")
    for(int i =n;i<=n+2;i++){
        if(check(i)){
            cout<<i<<endl;
            return;
        }
    }
    cout << n + 1 << "\n";

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
