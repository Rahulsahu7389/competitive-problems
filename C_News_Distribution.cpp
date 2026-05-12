// #include <bits/stdc++.h>
// using namespace std;

// #define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++) 
// #define FORLL(a, c) for (long long(a) = 0; (a) < (c); (a)++) 
// #define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--) 
// typedef long long int ll; 
// typedef vector<int> vi; 
// typedef pair<int, int> pi; 
// #define all(a) a.begin(),a.end()
// #define F first 
// #define S second 
// #define pb push_back 
// #define pob pop_back 
// ll MOD = 1e9 + 7;

// // ======== DEBUG SYSTEM ========
// bool DEBUG_MODE = true;  // toggle before submission

// template<typename T> void _print(const T &x) { cerr << x; }
// template<typename T1, typename T2> void _print(const pair<T1, T2> &p) { cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}"; }
// template<typename T> void _print(const vector<T> &v) { cerr << "["; for (auto &i : v) { _print(i); cerr << " "; } cerr << "]"; }
// template<typename T> void _print(const set<T> &s) { cerr << "{"; for (auto &i : s) { _print(i); cerr << " "; } cerr << "}"; }
// template<typename T> void _print(const multiset<T> &s) { cerr << "{"; for (auto &i : s) { _print(i); cerr << " "; } cerr << "}"; }
// template<typename K, typename V> void _print(const map<K, V> &m) { cerr << "{"; for (auto &p : m) { _print(p.first); cerr << "->"; _print(p.second); cerr << " "; } cerr << "}"; }

// // Variadic template for multiple args
// void dbg_out() { cerr << "\n"; }
// template<typename Head, typename... Tail>
// void dbg_out(Head H, Tail... T) { _print(H); if(sizeof...(T)) cerr << " | "; dbg_out(T...); }

// #define dbg(...) if(DEBUG_MODE){ cerr << "[" << __LINE__ << "] " << #__VA_ARGS__ << " = "; dbg_out(__VA_ARGS__); }

// // ======== UTILITY FUNCTIONS ========
// template<typename T>
// T mod(T a){ return (a<0)? -a : a; }

// template<typename T>
// T power(T x,T n){
//   T pro = 1;
//   while(n!=0){
//     if(n%2==1) pro *= x;
//     x *= x;
//     n /= 2;
//   }
//   return pro;
// }

// void fun(ll i, vector<ll> &vis, vector<vector<ll>> &adj, vector<ll> &ans) {
//     vector<ll> temp;
//     queue<ll> q;
    
//     q.push(i);
//     vis[i] = 1; // Mark visited IMMEDIATELY on push
    
//     while (!q.empty()) {
//         auto it = q.front();
//         q.pop();
//         temp.push_back(it);

//         for(auto neighbor : adj[it]) {
//             if(vis[neighbor] == 0) {
//                 vis[neighbor] = 1; // Mark visited IMMEDIATELY on push
//                 q.push(neighbor);
//             }
//         }
//     }

//     ll component_size = temp.size();
//     for(auto node : temp) {
//         ans[node] = component_size;
//     }
// }



// void solve(){
//    //your code starts from here
//    ll n,m;
//    cin>>n>>m;
//    vector<vector<ll>> adj(n);
//    for (ll i = 0; i < m; i++)
//    {
//     ll q;
//     cin>>q;
//     if(q == 0) continue;
//     ll a;
//     cin>>a;
//     a--;
//     for (ll j = 0; j <q-1; j++)
//     {
//         ll b;
//         cin>>b;
//         b--;
//         adj[a].push_back(b);
//         adj[b].push_back(a);
//     }
    
//    }
//    vector<ll> ans(n);
//    vector<ll> vis(n);
//    for (ll i = 0; i < n; i++)
//    {
//     if(vis[i]==1) continue;
    
//     fun(i,vis,adj,ans);
    
//    }
//    for(auto val:ans){
//     cout<<val<<" ";
//    }
//    cout<<endl;
   
   

// }

// int main() 
// { 
//     ios::sync_with_stdio(0); 
//     cin.tie(0); 
//     // ll T; 
//     // cin >> T; 
//     // while (T--) { 
//         solve(); 
//     // } 
//     return 0; 
// }


// using dsu 
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

ll findpar(ll u,vector<ll> &par){
    if(u == par[u]){
        return u;
    }
    return par[u] = findpar(par[u],par);
}

void unionBySize(ll u , ll v , vector<ll> &par,vector<ll> &size){
    ll ultiparu = findpar(u,par);
    ll ultiparv = findpar(v,par);
    if(ultiparu == ultiparv) return;
    if(size[ultiparu]<size[ultiparv]){
        par[ultiparu] = ultiparv;
        size[ultiparv] +=  size[ultiparu];
    }
    else{
        par[ultiparv] = ultiparu;
        size[ultiparu] += size[ultiparv];
    }
}

void solve(){
   //your code starts from here

   ll n,m;
   cin>>n>>m;
   vector<ll> size(n,1);
   vector<ll> par(n);
   for (ll i = 0; i < n; i++)
   {
    par[i] = i;
   }
   for (ll i = 0; i < m; i++)
   {
    ll q;
    cin>>q;
    if(q == 0) continue;
    ll a;
    cin>>a;
    a--;
    for (ll j = 0; j <q-1; j++)
    {
        ll b;
        cin>>b;
        b--;
        unionBySize(a,b,par,size);
    }
    
   }
   
   for (ll i = 0; i < n; i++)
   {
    ll val = size[findpar(i,par)];
    cout<<val<<" ";
   }
   cout<<endl;
   

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
