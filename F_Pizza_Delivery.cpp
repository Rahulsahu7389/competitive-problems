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
ll dist(pair<ll,ll> a, pair<ll,ll> b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void solve(){
   //your code starts from here
   ll n,a1,a2,b1,b2;
   cin>>n>>a1>>a2>>b1>>b2;
   map<ll,ll> top,bot;
   top[a1] = bot[a1] = a2;
   top[b1] = bot[b1] = b2;

   vector<ll> xc(n),yc(n);
   for (ll i = 0; i < n; i++)
   {
    cin>>xc[i];
   }
   for (ll i = 0; i < n; i++)
   {
    cin>>yc[i];
   }

   //we only need the top and bottom of the cordinates as manhatan distance is same tum khi se enter kro to hm top and bottom le rhe

   for (ll i = 0; i < n; i++)
   {
    if(!top.count(xc[i])){
        top[xc[i]] = bot[xc[i]] = yc[i];
        continue;
    }
    top[xc[i]] = max(top[xc[i]],yc[i]);
    bot[xc[i]] = min(bot[xc[i]],yc[i]);

   }

   vector<pair<ll,ll>> top_pts, bot_pts;
   for(auto val:top){
    top_pts.push_back({val.first,val.second});
   }

   for(auto val:bot){
    bot_pts.push_back({val.first,val.second});
   }

   n = top_pts.size();
   vector<vector<ll>> dp(n,vector<ll> (2,LLONG_MAX));

   dp[0][0] = dp[0][1] = 0;
   for (ll i = 1; i < n; i++)
   {
    for (ll j = 0; j < 2; j++)//0 or 1 - prev state
    {
        for (ll k = 0; k < 2; k++)//current state as 2*2 = 4 possibilities hai na
        {
            auto prev_pts = (k?top_pts[i-1]:bot_pts[i-1]);
            auto cur_pt = (j?bot_pts[i]:top_pts[i]);
            dp[i][j] = min(dp[i][j],(dp[i-1][k] + dist(prev_pts,cur_pt) + (top_pts[i].second - bot_pts[i].second)));
        }
        
    }
    
   }
   cout<<dp[n-1][0]<<endl;
   

   

   

   
   
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
