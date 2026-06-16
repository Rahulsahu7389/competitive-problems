#include <bits/stdc++.h>
using namespace std;

#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++) 
#define FORLL(a, c) for (long long(a) = 0; (a) < (c); (a)++) 
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--) 
typedef long long int ll; 
typedef long double ld;
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


bool valid(ld mid, const vector<ll>& pos, const vector<ll>& dress, ld& best_pos) {
    ld l = 0;
    ld r = 2e8; // Maximum possible coordinate boundary
    
    for (ll i = 0; i < pos.size(); i++) {
        // If the allowed time 'mid' is less than the dress time, they can't even get dressed!
        if (mid < dress[i]) return false; 
        
        ld rem = mid - dress[i];
        ld L = pos[i] - rem;
        ld R = pos[i] + rem;
        
        l = max(L, l);
        r = min(R, r);
        
        if (l > r) return false;
    }
    
    // If it's valid, any meeting point within the overlapping range [l, r] works
    best_pos = l + (r - l) / 2.0; 
    return true;
}

void solve(){
   //your code starts from here
   ll n;
   cin>>n;
   vector<ll> time(n);
   vector<ll> dress(n);
  //  ans = 2e8;
   for (ll i = 0; i < n; i++)
   {
    cin>>time[i];
   
   }
   for (ll i = 0; i < n; i++)
   {
    cin>>dress[i];
   }
   ld best_pos = 0;
   ld stime = 0;
   ld endtime = 2e8;

   while(fabsl(stime - endtime)>1e-6){
    ld mid = stime + (endtime - stime) / 2.0;
    if(valid(mid,time,dress,best_pos)){
      endtime = mid;
    }
    else{
      stime = mid;
    }
   }
   cout<<fixed<<setprecision(6)<<best_pos<<"\n";

   
   
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
