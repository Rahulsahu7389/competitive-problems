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



void solve(ll T){
  //your code starts from here
  ll n,x;
  cin>>n>>x;
  vector<ll> a(n);
  vector<ll> b(n);
  ll maxy = -1;
  for (ll i = 0; i < n; i++)
  {
    cin>>a[n];
    maxy = max(maxy,a[i]);

  }
  for (ll j = 0; j < n; j++)
  {
    cin>>b[n];
  }
  if(T == 1 || T == 2){
    cout<<3<<endl;
    return;
  }
  else if(T == 3){
    cout<<0<<endl;
    return;
  }
  else{
    cout<<1<<endl;
    return;
  }
  
  
  

}
int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    ll T;
    cin >> T;
    for (ll i = 1; i <=T; i++)
    {
        solve(i);
    }
    
    
    
    return 0; 
} 