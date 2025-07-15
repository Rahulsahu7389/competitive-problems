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


void solve(){
  //your code starts from here
  ll n, x;
  cin>>n>>x;
  vector<ll> v(n);
  vector<pair<ll,ll>> lm;
  for (ll i = 0; i < n; i++)
  {
    cin>>v[i];
    lm.pb({v[i]-x,v[i]+x});
  }

  
  ll ans = 0;

  ll l = lm[0].first;
  ll r = lm[0].second;
  for(auto val:lm){
    l = max(val.first,l);
    r = min(val.second,r);
    if(l>r){
        l = val.first;
        r = val.second;
        ans++;
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