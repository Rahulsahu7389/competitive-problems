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

bool comp(pair<ll,ll> a , pair<ll,ll> b){
    if(a.first == b.first){
        return a.second<b.second;
    }
    return a.first>b.first;
}

void solve(){
  //your code starts from here
  ll n,k;
  cin>>n>>k;
  vector<pair<ll,ll>> v;
  for (ll i = 0; i < n; i++)
  {
    ll a;
    cin>>a;
    v.pb({a,i+1});
  }
  if(k == 1){
    for (ll i = 0; i < n; i++)
    {
        cout<<(i+1)<<" ";
    }
    cout<<endl;return;
    
  }
  for (ll i = 0; i < n; i++)
  {
    if((v[i].first%k == 0 )){
        v[i].first = k;
    }
    else{
        v[i].first = v[i].first%k;
    }
  }
  sort(all(v),comp);
  for(auto val:v){
    cout<<val.second<<" ";

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