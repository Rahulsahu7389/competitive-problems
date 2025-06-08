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

pair<ll,ll> leftright(ll a, ll x , ll y){
    return {x-a,x+a};
}

pair<ll,ll> topBottom(ll a, ll x , ll y){
    return {y-a,y+a};
}




void solve(){
  //your code starts from here
  ll a,b;
  ll xk,yk,xq,yq;
  cin>>a>>b;
  cin>>xk>>yk;
  cin>>xq>>yq;

  //taking king as reference  and first using a
  //right and left
  ll x1 , x2;
  auto cord = leftright(a , xk,yk);
  cout<<cord.first<<" "<<cord.second<<endl;





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