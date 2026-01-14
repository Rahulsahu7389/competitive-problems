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
   ll a,b;
   if(!(cin>>a>>b)) return;
   vector<ll> len = {a, a, b, b};
   vector<ll> rgb(3);
   for (ll i = 0; i < 3; i++) cin>>rgb[i];

   sort(len.rbegin(), len.rend());
   sort(rgb.rbegin(), rgb.rend());

   ll cnt = 0;
   vector<bool> vis(4, false);

   for (ll i = 0; i < 4; i++) {
      for (ll j = 0; j < 3; j++) {
         if (rgb[j] >= len[i]) {
            rgb[j] -= len[i];
            vis[i] = true;
            cnt += 1;
            break;
         }
      }
   }

   for (ll i = 0; i < 4; i++) {
      if (vis[i]) continue;
      sort(rgb.rbegin(), rgb.rend());
      if (rgb[0] + rgb[1] >= len[i]) {
         ll req = len[i];
         ll take = min(req, rgb[0]);
         rgb[0] -= take;
         req -= take;
         rgb[1] -= req;
         vis[i] = true;
         cnt += 2;
      }
   }

   for (ll i = 0; i < 4; i++) {
      if (vis[i]) continue;
      if (rgb[0] + rgb[1] + rgb[2] >= len[i]) {
         cnt += 3;
         vis[i] = true;
      }
   }

   cout << cnt << endl;
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
