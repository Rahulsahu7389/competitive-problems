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
// ll dp[1003][1003];//dp[i] = min operation required to reduce to 1
// ll reduce(ll n , ll tar){
//     if(n >tar){
//         return 1e15;
//     }
//     if(n == tar) return 0;
//     if(dp[n][tar]!=-1){
//         return dp[n][tar];
//     }
//     ll val = 1e15;
//     for (ll i = 1; i <=n; i++)
//     {
//         val = min(val,1 +reduce(n+(n/i),tar));
//     }
//     return dp[n][tar]=val;
    

// }

ll dist[1003];
void precompute() {
    // Initialize with a large value
    for (int i = 0; i <= 1000; i++) {
        dist[i] = 1e15;
    }
    dist[1] = 0; // It takes 0 operations to reach 1 from 1

    // Push DP: Propagate the minimum moves forward
    for (int i = 1; i <= 1000; i++) {
        for (int x = 1; x <= i; x++) {
            int next_val = i + (i / x);
            if (next_val <= 1000) {
                dist[next_val] = min(dist[next_val], dist[i] + 1);
            }
        }
    }
}

ll dpks[1003][12*1002];
void solve(){
   //your code starts from here
   ll n,k;
   cin>>n>>k;

   vector<ll> v(n),cost(n);

   for (ll i = 0; i < n; i++)
   {
    cin>>v[i];
   }
   for (ll i = 0; i < n; i++)
   {
    cin>>cost[i];
   }
   
   vector<ll> minops;
//    ll t = reduce(1LL,3LL);
//    dbg(t)
   for (ll i = 0; i < n; i++)
   {
    ll val = dist[v[i]];
    minops.push_back(val);
   }
   dbg(minops)
   memset(dpks,0,sizeof(dpks));
   k = min(k,12LL*n);//because min ops cannot be greater than 12
   for (ll i = 0; i <=k; i++)
   {
    if(minops[0]<=i){
        dpks[0][i] = cost[0];
    }
   }
   
   for (ll i = 1; i <n; i++)
   {
    for (ll j = 0; j <=k; j++)
    {
        ll take = 0;
        ll nottake = dpks[i-1][j];
        if(minops[i]<=j){
            take = max(take,cost[i] + dpks[i-1][j-minops[i]]);
        }
        dpks[i][j] = max(take,nottake);
    }

    
   }
   cout<<dpks[n-1][k]<<endl;

   

}

int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    // memset(dp,-1,sizeof(dp));
    precompute();
    ll T; 
    cin >> T; 
    while (T--) { 
        solve(); 
    } 
    return 0; 
}
