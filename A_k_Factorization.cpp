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
  vector <ll> v;
  for (ll i = 2; i*i<=n; i++)
  {
    while(n%i==0){
        v.pb(i);
        n /= i;
    }
  }
  if(n!=1){
    v.pb(n);
  }
//   for(auto val:v){
//     cout<<val<<endl;
//   }
  ll sz = v.size();
  if(sz<k){
    cout<<-1<<endl;
    return;
  }
  else if(sz==k){
    for(auto val: v){
        cout<<val<<" ";
    }
    cout<<endl;
  }
  else{
    ll idx = 0;
    ll pro = 1;
    for (ll i = 0; i < sz; i++)
    {
        if(idx<(sz -k)){
            idx++;
            pro *= v[i];
            continue;
        }
        else if(idx==(sz -k)){
            idx++;
            pro *= v[i];
            cout<<pro<<" ";
            continue;
        }
        cout<<v[i]<<" ";
    }
    cout<<endl;

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