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
  //your code starts from 
  ll n,s;
  cin>>n>>s;
  vector<ll> v(n);
  for (ll i = 0; i < n; i++)
  {
    cin>>v[i];
  }
  sort(v.begin(),v.end());
  ll ans = 0;
  ll left = (s - v[0]);
  ll right = (v[n-1] - s);
  if(s>=v[n-1]){
    cout<<left<<endl;
    return;
  }
  if(s<=v[0]){
    cout<<right<<endl;
    return;
  }
  if(left<right){
    ans += (left)*2 + right;
  }
  else{
    ans += (right)*2 + left;
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