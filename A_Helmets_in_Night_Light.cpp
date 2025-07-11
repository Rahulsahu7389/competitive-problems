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
  if(a.second != b.second){
    return (a.second<b.second);
  }
  return (a.first>b.first);

}


void solve(){
  //your code starts from here
  ll n,p;
  cin>>n>>p;
  // vector<ll> pre(n);
  vector<pair<ll,ll>> v;//{no of people,cost of notify}
  // ll ans = 2e9;
  for (ll i = 0; i < n; i++)
  {
    ll a;
    cin>>a;
    v.pb({-1,a});
  }
  
  for (ll i = 0; i < n; i++)
  {
    ll b;
    cin>>b;
    v[i].first = b;
    
  }
  sort(v.begin(),v.end());
  ll alreadyShared = 1;
  ll cost = p;
  for(auto val:v){
    ll canbeshared = val.second;
    ll sharingCost = val.first;

    if(sharingCost >= p){
      break;
    }

    if(alreadyShared + canbeshared > n){
      cost += (n  - alreadyShared)*sharingCost;
      alreadyShared = n;
      break;
    }
    else{
      cost += canbeshared * sharingCost;
      alreadyShared += canbeshared;
    }
  }

  cost += (n - alreadyShared)*p;//chief
  cout<<cost<<endl;
  
  
  

  
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