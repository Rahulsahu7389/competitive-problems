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
  ll l1,b1,l2,b2,l3,b3;
  cin>>l1>>b1>>l2>>b2>>l3>>b3;
  ll a1 = l1*b1;
  ll a2 = l2*b2;
  ll a3 = l3*b3;
  ll total = a1+a2+a3;
  ll value = sqrt(total);
  if(value*value != total){
    cout<<"NO"<<endl;
    return;
  }
  
  if ((l1 == l2 + l3 && b2 == b3 && b1 + b2 == l1) || (b1 == b2 + b3 && l2 == l3 && l1 + l2 == b1) || (l1 == l2 && l2 == l3 && b1 + b2 + b3 == l1) || (b1 == b2 && b2 == b3 && l1 + l2 + l3 == b1)){
    cout<<"YES"<<endl;
    return;
  }
  cout<<"NO"<<endl;

  

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
