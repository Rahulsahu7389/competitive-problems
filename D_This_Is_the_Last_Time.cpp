#include<bits/stdc++.h>
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

template<typename T>
T mod(T a){
  if(a<0) return -a;
  return a;
}

template<typename T>
T power(T x,T n){
  T pro = 1;
  while(n!=0){
    if(n%2==1){
      pro *= x;
    }
    x *= x;
    n /= 2;
  }
  return pro;
}

// bool custom(vector<ll> a ,vector<ll> b){
//     return a[1]>b[1];
// }


void solve(){
  //your code starts from here
  ll n , k;
  cin>>n>>k;
  vector<vector<ll>> v;
  for (ll i = 0; i < n; i++)
  {
        ll a,b,c;
        cin>>a>>b>>c;
        v.pb({a,c,b});
    
  }
  ll ans = k;
  sort(all(v));
//   for (ll i = 0; i < n; i++)
//   {
//     for (ll j = 0; j < 3; j++)
//     {
//         cout<<v[i][j]<<" ";
//     }
//     cout<<endl;
    
    
//   }
  for (ll i = 0; i < n; i++)
  {
    if(ans>=v[i][0] && ans<=v[i][2] && v[i][1]>=ans){
        ans = v[i][1];
    }
    
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