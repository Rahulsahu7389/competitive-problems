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
  vector<ll> v(n);
  vector<pair<ll,ll>> pre;
  ll mini = 1e9;
  ll maxi = -1e9;
  for (ll i = 0; i < n; i++)
  {
    cin>>v[i];
    maxi = max(maxi ,v[i]);
    mini = min(mini,v[i]);
  }
  ll p = v[0];
  for (ll i = 0; i < n; i++)
  {
    if(v[i]<=p){
        p = v[i];
    }
    pre.pb({p,-1e9});
  }
  p = v[n-1];
  for (ll i = n-1; i >=0; i--)
  {
    if(v[i]>=p){
        p = v[i];
    }
    pre[i].second = p;
  }
  string ans = "";
  for (ll i = 0; i < n; i++)
  {
    if(v[i] == mini){
        ans += "1";
        continue;
    }
    if(v[i] == maxi){
        ans += "1";
        continue;
    }
    if((pre[i].first == v[i] && pre[i].second>=v[i]) || (pre[i].first <= v[i] && pre[i].second==v[i])){
        ans += "1";
    }
    else{
        ans += "0";
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