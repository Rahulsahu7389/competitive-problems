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
int countWaysUnlimited(std::vector<int>& arr, int target) {
    std::vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (int num : arr) {
        // Iterate forward to allow multiple uses of the same number
        for (int j = num; j <= target; j++) {
            dp[j] += dp[j - num];
        }
    }
    return dp[target];
}

const ll Mod = 1000000007;

bool ispalindromic(ll i){
    if(i>=1 && i<=9) return true;
    ll temp = i;
    ll val = 0;
    while(i>0){
        ll rem = i%10;
        val = (val*10 + rem);
        i /= 10;
    }
    return (temp == val);

}

ll fun(ll i ,ll sum,vector<ll> & arr,vector<vector<ll>> &dp){
    if(i == 0){
        if(sum%arr[i]==0){
            return 1;
        }
    }
    if(sum ==0) return 1;
    if(dp[i][sum]!=-1){
        return dp[i][sum];
    }

    ll take = 0;
    ll nottake = fun(i-1,sum,arr,dp);
    if(arr[i]<=sum){
        take += fun(i,sum -arr[i],arr,dp);
    }
    return dp[i][sum] = (take + nottake)%Mod;

}

void solve(vector<vector<ll>>& dp){
   ll n;
   cin>>n;
   
   cout<<(dp[dp.size()-1][n])<<endl;
   
   

   
}

int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    ll n = 4*1e4;
    vector<ll> temp;
    
    for (ll i = 1; i <=n; i++)
    {
        if(ispalindromic(i)){
            temp.pb(i);
        }
    }
    ll m = temp.size();
    vector<vector<ll>> dp(m,vector<ll>(n+1,0));
    // fun(temp.size()-1,n,temp,dp);
    for (ll i = 0; i <m; i++)
    {
        dp[i][0] = 1;
    }
    for (ll i = 1; i <=n; i++)
    {
        dp[0][i] = 1;
    }
    for (ll i = 1; i < m; i++)
    {
        for (ll sum = 0; sum <=n; sum++)
        {
            ll take = 0;
            ll nottake = dp[i-1][sum];
            if(temp[i]<=sum){
                take += dp[i][sum-temp[i]];
            }
            dp[i][sum] = (take + nottake)%Mod;
        }
        
    }

    
    
    ll T; 
    cin >> T; 
    while (T--) { 
        solve(dp); 
    } 
    return 0; 
}
