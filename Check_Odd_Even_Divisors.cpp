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
  ll x,y;
  cin>>x>>y;
  if(x == 0 && y >0 || (x ==0 && y ==0)){
    cout<<"No\n";
    return;
  }
  if(x>0 && y ==0){
    cout<<"Yes\n";
    return;
  }
  if(x!=0 && y!=0){
    if(y%x==0){
        ll sum = y/x;
        if(sum>=1){
            cout<<"Yes\n";
            return;
        }
    }
  }
  cout<<"No\n";

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