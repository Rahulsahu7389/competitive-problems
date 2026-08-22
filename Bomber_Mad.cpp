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
   //your code starts from here
   ll n,m,k;
   cin>>n>>m>>k;
   vector<string> v(n);
   for (ll i = 0; i < n; i++)
   {
    cin>>v[i];
   }
   vector<ll> row(n),col(m);
   for (ll i = 0; i < n; i++)
   {
    for (ll j = 0; j < m; j++)
    {
      if(v[i][j]=='#'){
        row[i] = 1;
        col[j] = 1;
      }
    }
    
   }
   vector<vector<int>> vis(n,vector<int>(m,1e9));
   queue<vector<ll>> q;//x,y,k
   ll ans = 0;
   for (ll i = 0; i < n; i++)
   {
    for (ll j = 0; j < m; j++)
    {
      if(row[i]==0 && col[j]==0 && v[i][j]=='.'){
        q.push({i,j,k});
        vis[i][j] = 0;
        // dbg(i,j)
        ans++;
      }
    }
    
   }
   int rows[] = {-1,0,1,0};
   int cols[] = {0,1,0,-1};
   while(!q.empty()){
    auto &it = q.front();
    int x = it[0];
    int y = it[1];
    ll sk = it[2];
    q.pop();
    if(sk==0){
      continue;
    }
    for(int i = 0;i<4;i++){
      int r = x + rows[i];
      int c = y + cols[i];
      if(r>=0 && r<n && y>=0 && y<m){
        ll dis = vis[x][y] + 1;
        if(dis<vis[r][c] && v[r][c]=='.'){
          vis[r][c] = dis;
          q.push({r,c,sk-1});
        }
      }
    }

   }

   for (ll i = 0; i < n; i++)
   {
    for (ll j = 0; j < m; j++)
    {
      if(vis[i][j]!=1e9 && vis[i][j]!=0){
        ans++;
      }
    }
    
   }
   cout<<ans<<endl;
   



   
   
   
   
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
