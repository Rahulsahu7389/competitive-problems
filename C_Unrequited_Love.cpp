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
   ll n;
   cin>>n;
   vector<ll> v(n);
   for (ll  i = 0; i < n ; i++)
   {
    cin>>v[i];
   }
   unordered_map<ll,vector<ll>> odd,even;
   for (ll  i = 0; i < n ; i++)
   {
    if(i+4>=n) continue;
    ll sum = v[i] + v[i+2] - v[i+4];
    if(i & 1){
        odd[sum].push_back(i);
    }
    else{
        even[sum].push_back(i);
    }
   }
//    dbg(odd)
//    dbg(even)
   ll ans = 0;
   
   for(auto &val : odd) {
       ll sz = val.second.size();
       if(even.count(val.first) > 0) {
           ll sz2 = even[val.first].size();
           ans += sz * sz2;
       }
       if(sz>1) {
           for(auto t : val.second) {
               ll limit = t + 5; 
               auto idx = lower_bound(all(val.second), limit);
               if(idx != val.second.end()) {
                   ans += sz - (idx - val.second.begin());
               }
           }
       }
   }


   for(auto &val : even) {
       ll sz2 = val.second.size();
       if(sz2 > 1) {
           for(auto t :val.second) {
               ll limit = t+5;
               auto idx = lower_bound(all(val.second), limit);
               if(idx != val.second.end()) {
                   ans += sz2 -(idx -val.second.begin());
               }
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
