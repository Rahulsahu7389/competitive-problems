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
bool DEBUG_MODE = false;  // toggle before submission

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

ll fun(ll i , vector<ll> & pref , ll x){
    ll n = pref.size();
    ll s = 0;
    ll end = n-1;
    ll idx = n;
    while(s<=end){
        ll mid = s  + (end - s)/2;
        ll val = pref[mid] + i*(mid + 1);
        if(val>x){
            idx = mid;
            end = mid - 1;
        }
        else{
            s = mid + 1;
        }

    }
    return idx;
}

void solve(){
   //your code starts from here
   ll n,x;
   cin>>n>>x;
   vector<ll> v(n);
   ll mini = 1e18;
   for (ll i = 0; i < n; i++)
   {
    cin>>v[i];
    mini = min(mini,v[i]);
   }
   sort(all(v));
   vector<ll> pref(n);
   pref[0] = v[0];
   for (ll i = 1; i < n; i++)
   {
    pref[i] = pref[i-1] + v[i];
   }
   ll range = abs(mini - x);
   ll ans = 0;
   
   for (int k = 0; k < n; k++) {
        if (pref[k] > x) break;

        ll maxDays = (x - pref[k]) / (k + 1);
        ans += maxDays + 1;
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
