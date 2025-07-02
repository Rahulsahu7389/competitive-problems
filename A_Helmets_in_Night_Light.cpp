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
  //your code starts from here
  ll n , p;
  cin>>n>>p;
  vector<pair<ll,ll>> v;
  vector<ll> pre(n);
  ll cnt = 0;
  for (ll i = 0; i < n; i++)
  {
    ll a;
    cin>>a;
    cnt += a;
   
    v.pb({-1,a});
  }
  for (ll i = 0; i < n; i++)
  {
    ll a;
    cin>>a;
    v[i].first = a;
  }
//   cout<<"here\n";
  sort(v.begin(),v.end());
  pre[0] = v[0].second;
  for (ll i = 1; i < n; i++)
  {
    pre[i] = v[i].second + pre[i-1];
  }
  
  
  
  ll ans = 2e9;
  for (ll i = 0; i < n; i++)
  {
    if(pre[i]>=(n - (i+1))){
        ll sum = (i + 1)*p ;
        ll cnt = i+1;
        ll idx = 0;
        while(cnt<n){
            sum += (v[idx].first*v[idx].second);
            cnt += v[idx].second;
            idx++;
        }
        
        ans = min(sum,ans);
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