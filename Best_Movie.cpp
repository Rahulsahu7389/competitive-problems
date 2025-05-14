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
  ll n;
  cin>>n;
  vector <pair<ll,ll>> v;//<idm, cost>
  ll cnt = 0;
  for (ll i = 0; i < n; i++)
  {
    ll a,b;
    cin>>a>>b;
    if(a>=7){
        cnt++;
    }
    v.pb({a,b});
  }
  if(cnt == 0){
    cout<<-1<<endl;
    return;
  }
  ll ans = 1000000;
  for (auto val : v)
  {
    if(val.first>=7){
        ans = min(val.second,ans);
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