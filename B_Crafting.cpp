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
  vector<ll> a(n);
  vector<ll> b(n);
  ll noOfincrease = 0;
  ll idx = -3;
  for (ll i = 0; i < n; i++)
  {
    cin>>a[i];
  }
  for (ll i = 0; i < n; i++)
  {
    cin>>b[i];
    if(a[i]<b[i]){
        noOfincrease++;
        idx = i;
    }
  }
  if(noOfincrease>1){
    cout<<"NO"<<endl;
    return;
  }
  if(noOfincrease==0){
    cout<<"YES"<<endl;
    return;
  }
  ll mini = 1e9;
  for (ll i = 0; i < n; i++)
  {
    if(i!=idx){
        mini = min(mini,modl(a[i]-b[i]));
    }
  }
  if(modl(a[idx]-b[idx])>mini){
    cout<<"NO"<<endl;
    return;
  }
  cout<<"YES"<<endl;
  
  

  

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