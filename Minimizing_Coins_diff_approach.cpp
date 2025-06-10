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
long long modl(ll a){
  if(a<0){return -a;}
  return a;
}

int modl(int a){
  if(a<0){return -a;}
  return a;
}


void solve(){
  //iterative approach
  ll n, x;
    cin >> n >> x;
    vector<ll> v(n);
    vector<ll> dp(x + 1, 1e9); // dp[i] - min no of coins required to form the value i
    dp[0] = 0;
    for (ll i = 0; i < n; i++)
    {
    cin>>v[i];
    }
    for (ll i = 0; i <=x; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if(v[j]<=i){

                dp[i] = min(dp[i],(dp[i - v[j]] + 1));
            }
        }
        
    }
    if(dp[x] == 1e9){
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
    ll T; 
    cin >> T; 
    while (T--) { 
        solve(); 
    } 
    return 0; 
} 