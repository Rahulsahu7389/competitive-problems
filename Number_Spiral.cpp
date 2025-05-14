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
  // ll n;
  // cin>>n;
  ll x,y;
  cin>>y>>x;
  if(x==y){
    cout<<((x*(x-1))+1)<<endl;
    return;
  }
  else if(x<y){
    if(y%2==0){
        cout<<(y*y - x + 1)<<endl;
        return;
    }
    else{
        cout<<((y-1)*(y-1) + x)<<endl;
        return;
    }
  }
  else{
    if(x%2!=0){
        cout<<(x*x - y + 1)<<endl;
        return;
    }
    else{
        cout<<((x-1)*(x-1) + y)<<endl;

    }
  }

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