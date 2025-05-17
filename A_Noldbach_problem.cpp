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

bool isPrime(ll a){
    for (ll i = 2; i*i <= a; i++)
    {
        if(a%i==0){
            return false;
        }
    }
    return true;
    
}


void solve(){
  //your code starts from here
  ll n,k;
  cin>>n>>k;
  vector<ll> v;
  for (ll i = 2; i < n; i++)
  {
   
    if(isPrime(i)){
        v.pb(i);
    }
    
    
  }
  ll cnt = 0;
  for (ll i = 1; i < v.size(); i++)
  {
    if(isPrime(v[i]+v[i-1]+1) && (v[i]+v[i-1]+1)<=n){
        cnt++;
        // cout<<(v[i]+v[i-1]+1)<<endl;
    }
  }
  if(cnt>=k){
    cout<<"YES"<<endl;
    return;
  }
  else{
    cout<<"NO"<<endl;
  }
  
  



}
int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    // ll T; 
    // cin >> T; 
    // while (T--) { 
        solve(); 
    // } 
    return 0; 
} 