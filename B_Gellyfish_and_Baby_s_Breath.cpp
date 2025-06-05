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

ll power(ll n , ll x){
    ll ans = 1;
    while(n>0){
        if(n%2==1){
            ans *= x;
        }
        n /= 2;
        x *=x;
    }
    return ans;
}


void solve(){
  //your code starts from here
  ll n;
  cin>>n;
  vector<ll> p;
  vector<ll> q;
  vector<ll> ans;
  for (ll i = 0; i < n; i++)
  {
    ll a;
    cin>>a;
    p.pb(power(a,2));
  }
  for (ll i = 0; i < n; i++)
  {
    ll a;
    cin>>a;
    q.pb(power(a,2));
  }
  for (ll i = 0; i < n; i++)
  {
    ll sum = -1e9;
    for (ll j = 0; j <= i; j++)
    {
        sum = max(sum,(p[j]+q[i-j]));
    }
    cout<<sum<<" ";
    
  }
  cout<<endl;
  
  

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