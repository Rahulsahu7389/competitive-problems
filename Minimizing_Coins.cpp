#include "bits/stdc++.h"
using namespace std;
 
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORLL(a, c) for (long long(a) = 0; (a) < (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define pb push_back
#define pob pop_back
long long modl(ll a)
{
    if (a < 0)
    {
        return -a;
    }
    return a;
}
 
int modl(int a)
{
    if (a < 0)
    {
        return -a;
    }
    return a;
}
 
// ll fun(ll n, vector<ll> arr, vector<ll> &dp)
// {
//     if (n < 0)
//         return 1e9;
//     if(n == 0){
//         return 0;
//     }
//     if (dp[n] != -1)//error
//     {
//         return dp[n];
//     }
    
 
//     ll mini = 1e9;
//     for (ll i = 0; i < arr.size(); i++)
//     {
       
//         mini = min(fun(n - arr[i], arr, dp) + 1, mini);
        
//     }
    
//     dp[n] = mini ;
//     return dp[n];
// }
ll fun(ll n, vector<ll>& arr, vector<ll>& dp) {
    if (n < 0) return 1e9; 
    if (n == 0) return 0;
    if (n >= dp.size()) return 1e9; // Prevent out-of-bounds access

    if (dp[n] != -1) return dp[n]; //i was using find to make like if present in coin so return it but use it instead

    ll mini = 1e9;
    for (ll coin : arr) {
        if (n - coin >= 0) {//also make sure that it is non negative
            mini = min(fun(n - coin, arr, dp) + 1, mini);
        }
    }

    dp[n] = mini;
    return dp[n];
}

 
void solve()
{
    // your code starts from here
    ll n, x;
    cin >> n >> x;
    vector<ll> v(n);
    vector<ll> dp(x + 1, -1); // dp[i] - min no of coins required to form the value i
    dp[0] = 0;
      for (ll i = 0; i < n; i++)
      {
        cin>>v[i];
      }
      if(fun(x,v,dp) == 1e9){
        cout<<-1<<endl;
        return;
      }
      else{
        cout<<dp[x]<<endl;
        return;
      }
    
        
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
