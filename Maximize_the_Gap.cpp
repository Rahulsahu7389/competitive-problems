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

ll getidx(ll end,vector<pair<ll,ll>>&p,ll val){
    ll st = 0;
    ll ans = -1;
    while(st<=end){
        ll m = (st  + end)/2;
        if(p[m].second<=val){
            ans = m;
            st = m + 1;
        }
        else{
            end = m -1;
        }
    }
    return ans;
}

bool valid(ll mid , vector<pair<ll,ll>>&p,ll k){
    ll n = p.size();
    vector<ll> dp(n+1);
    dp[0] = 1;
    for (ll i = 1; i < n; i++)
    {
        ll valididx = getidx(i-1,p,p[i].first - mid);
        ll take = 1;
        if(valididx!=-1){
            take = max(take,1 +dp[valididx]);
        }
        ll nottake = dp[i-1];
        dp[i] = max(take,nottake);
    }
    return (dp[n-1]>=k);
    
}
bool cust(pair<ll,ll>&a , pair<ll,ll>&b){
    return a.second<b.second;
}
void solve(){
   //your code starts from here
   ll n,k;
   cin>>n>>k;
   vector<pair<ll,ll>> p(n);
   for (ll i = 0; i < n; i++)
   {
    cin>>p[i].first>>p[i].second;
   }
   sort(all(p),cust);
   ll st = 0;
   ll end = 1e15;
   ll ans = -1;
   while(st<=end){
    ll mid = (st + end)/2;
    if(valid(mid,p,k)){
        ans = mid;
        st = mid + 1;
    }
    else{
        end = mid -1;
    }
   }
   if(ans == 0){
    cout<<-1<<endl;
    return;
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
