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

ll power(ll x,ll n){
    ll pro = 1;
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
  ll n,k;
  cin>>n>>k;
  bool flag = false;
  ll ans = 2e9;
  ll pro = 1;
  ll cnteven = 0;
  // unordered_map<ll,ll> m;
  vector<ll> v(n);
  for (ll i = 0; i < n; i++)
  {
    cin>>v[i];
    if(v[i]%2==0){
      cnteven++;
    }
    pro *= v[i];
    if(pro%k==0){
        flag = true;
    }
    ans = min(ans,(k - (v[i]%k)));
  }
  if(flag){
    cout<<0<<endl;
    return;
  }
  if(k == 4){
    ll t ;
    
    if(cnteven==0){
      t = 2;
      ans= min(ans,t);
    }
    else if(cnteven==1){
      t = 1;
      ans= min(ans,t);
    }
    else{
      t = 0;
      ans= min(ans,t);
    }
    cout<<ans<<endl;
    return;
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