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
  for (ll i = 0; i < n; i++)
  {
    cin>>v[i];
  }
  
  ll x2 = (2*v[0] - v[1]);
  
  if(x2<0 || ((x2%(n+1))!=0)){
    cout<<"NO"<<endl;
    return;
  }
  x2 = x2/(n+1);
//   cout<<x2<<endl;
  ll x1 = (v[0] - (n*x2));
  if(x1<0){
    cout<<"NO"<<endl;
    return;
  }
//   cout<<"x1 and x2 "<<x1<<" "<<x2<<endl;
  for (ll i = 1; i <=n; i++)
  {
    // cout<<(v[i-1] - x1*i - x2*(n - i +1))<<endl;
    if((v[i-1] - x1*i - x2*(n - i +1))!=0){
        cout<<"NO"<<endl;
        return;
    }

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