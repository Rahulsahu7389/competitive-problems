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
  ll n,k;
  cin>>n>>k;

  vector<vector<ll>> v(n);
  for (ll i = 0; i < n; i++)
  {
    ll a;
    cin>>a;
    v[i].push_back(a);
    v[i].push_back(i);
}
for (ll i = 0; i < n; i++)
{
    ll b;
    cin>>b;
    v[i].push_back(b);
  }
  sort(v.begin(),v.end());

  auto it = v.end()-1;
  for(it; it!=v.begin()-1;it--){
    if(it>v.begin()){

        auto it2 = it-1;
        // cout<<((*it)[0])<<endl;
        while(idx<=k && idx<n){
            
        }
    }

  }
  
  
//   map<ll,vector<ll>> m;
//   vector<ll> v(n);
//   for (ll i = 0; i < n; i++)
//   {
//     ll a;
//     cin>>a;
//     v[i] = a;
//     m[a] = {i};
//   }
//   for (ll i = 0; i < n; i++)
//   {
//     ll b;
//     cin>>b;
//     m[v[i]].pb(b);
//   }

//   ll ans = 0;
//   for(auto val: m){
//     // cout<<val.first<<" "<<val.second[0]<<" "<<val.second[1]<<endl;
//     v[val.second[0]] = ans;
//     ans+= val.second[1];
//   }
//   for(auto val: v){
//     cout<<val<<endl;
//   }
  
  

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