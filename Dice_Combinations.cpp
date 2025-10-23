/* ITERATIVE APPROACH - by me


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
ll MOD = 1e9 + 7;
long long modl(ll a){
  if(a<0){return -a;}
  return a;
}

int modl(int a){
  if(a<0){return -a;}
  return a;
}


void solve(){
  //your code starts from here
  ll n;
  cin>>n;
  vector<ll> dp(n+1,0);//dp[i] is the number of ways to construct i 
  dp[0] = 1;
  for (ll i = 1; i <=n; i++)
  {
    for (ll j = 1; j <=6; j++)
    {
      if(j<=i){
        dp[i] = (dp[i]%MOD + dp[i - j]%MOD)%MOD;
      }
    }
    
  }
  cout<<((dp[n])%MOD)<<endl;
  
  
  

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

*/
//appraoch 2 - recursive code by me
// #include "bits/stdc++.h" 
// using namespace std; 

// #define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++) 
// #define FORLL(a, c) for (long long(a) = 0; (a) < (c); (a)++) 
// #define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--) 
// #define INF 1000000000000000003 
// typedef long long int ll; 
// typedef vector<int> vi; 
// typedef pair<int, int> pi; 
// #define F first 
// #define S second 
// #define pb push_back 
// #define pob pop_back 
// ll MOD = 1e9 + 7;
// long long modl(ll a){
//   if(a<0){return -a;}
//   return a;
// }

// int modl(int a){
//   if(a<0){return -a;}
//   return a;
// }

// vector<ll> dp(1000001,0);

// ll fun(ll n){
//   if(n == 0){
//     return 1;
//   }
//   if(dp[n]!=0){
//     return dp[n];
//   }
//   for (ll i = 1; i <=6; i++)
//   {
//     if(i<=n){
//       // cout<<"entered\n";
//       dp[n] = (dp[n]%MOD + fun(n-i)%MOD)%MOD;
//     }
//   }
//   return dp[n]%MOD;
  
// }


// void solve(){
//   //your code starts from here
//   ll n;
//   cin>>n;
//   dp[0] = 1;
//   ll value = fun(n);
//   cout<<value<<endl;

// }
// int main() 
// { 
//     ios::sync_with_stdio(0); 
//     cin.tie(0); 
//     // ll T; 
//     // cin >> T; 
//     // while (T--) { 
//         solve(); 
//     // } 
//     return 0; 
// } 

#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve(){
  ll n;
  cin>>n;
  vector<ll> v = {1,2,3,4,5,6};
  vector<vector<ll>> dp(6,vector<ll>(n+1,0));
  for (ll i = 0; i <=n; i++)
  {
    dp[0][i] = 1;
  }
  for (ll i = 0; i < 6; i++)
  {
    dp[i][0] = 1;
  }
  
  for (ll i = 1; i <6; i++)
  {
    for (ll sum = 1; sum <=n; sum++)
    {
      ll take = 0;
      if(v[i]<=sum){
        take = dp[i-1][sum - v[i]];
      }
      ll nottake = dp[i-1][sum];
      dp[i][sum] = take + nottake;
    }
    
  }
  cout<<dp[5][n]<<endl;
  
  
}

int main(){
  solve();
  return 0;
}