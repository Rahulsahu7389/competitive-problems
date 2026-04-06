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

bool cust(pair<ll,ll> & a , pair<ll,ll> & b){
    if(a.first == b.first) return a.second<b.second;
    return a.first<b.first;
}
void solve(){
   //your code starts from here
   ll n , m;
   cin>>n>>m;
   multiset<ll> sword;
   for (ll i = 0; i < n; i++)
   {
    ll a;
    cin>>a;
    sword.insert(a);
   }
   vector<ll> vis(m);
   vector<pair<ll,ll>> p(m);
   for (ll i = 0; i < m; i++)
   {
    cin>>p[i].first;
   }
   for (ll i = 0; i < m; i++)
   {
    cin>>p[i].second;
   }

//    sort(all(sword));
   sort(all(p),cust);
   ll ans = 0;
   
   for (ll i = 0; i < m; i++)
   {
    auto val = p[i];
    if(val.second>0){

        auto it = sword.lower_bound(p[i].first);
        if(it!=sword.end()){
            sword.erase(it);
            sword.insert(max(*it,p[i].second));
            vis[i] = 1;
            ans++;
        }
    }

   }
   for (ll i = 0; i < m; i++)
   {
    auto val = p[i];
    if(vis[i]==0){

        auto it = sword.lower_bound(p[i].first);
        if(it!=sword.end()){
            sword.erase(it);
            vis[i] = 1;
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
    ll T; 
    cin >> T; 
    while (T--) { 
        solve(); 
    } 
    return 0; 
}
