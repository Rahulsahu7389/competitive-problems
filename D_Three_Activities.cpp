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

bool custom(pair<ll,ll> a, pair<ll,ll> b){
    
    return (a.first>b.first);
}
bool custom2(vector<ll> a, vector<ll> b){
    
    return (a[0]>b[0]);
}

void solve(){
   //your code starts from here
   ll n;
   cin>>n;
   vector<pair<ll,ll>> a(n);
   vector<pair<ll,ll>> b(n);
   vector<pair<ll,ll>> c(n);
   for (ll i = 0; i < n; i++)
   {
    ll t;
    cin>>t;
    a[i] = {t,i};
   }
   for (ll i = 0; i < n; i++)
   {
    ll t;
    cin>>t;
    b[i] ={t,i};
   }
   for (ll i = 0; i < n; i++)
   {
    ll t;
    cin>>t;
    c[i] = {t,i};
   }
   sort(all(a),custom);
   sort(all(b),custom);
   sort(all(c),custom);
//    dbg(a);
   vector<vector<ll>> v;
   for (ll i = 0; i < 3; i++)
   {
    v.pb({a[i].first,a[i].second,0});
    
   }
   for (ll i = 0; i < 3; i++)
   {
    v.pb({b[i].first,b[i].second,1});
    
   }
   for (ll i = 0; i < 3; i++)
   {
    v.pb({c[i].first,c[i].second,2});
    
   }
   sort(all(v),custom2);
   ll x = v[0][0];
   vector<ll>vis(n);
   vector<ll>visrow(3);
   vis[v[0][1]] = 1;
   visrow[v[0][2]] = 1;
//    dbg(v)

   for (ll i = 1; i < 9; i++)
   {
    if(vis[v[i][1]]==0 && visrow[v[i][2]]==0){
        x += v[i][0];
        vis[v[i][1]] = 1;
        visrow[v[i][2]] = 1;
    }
   }
   cout<<x<<endl;
   
   

   
   
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
