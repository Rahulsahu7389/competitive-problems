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
  ll a,b,c,d;
  cin>>a>>b>>c>>d;
  ll minOfgf = min(a,c);
  ll minOff = min(b,d);
  if(minOff == minOfgf){
    cout<<"Gellyfish"<<endl;
    return;
  }
  else if(minOfgf>minOff){
    cout<<"Gellyfish"<<endl;
    return;
  }
  else{
    cout<<"Flower"<<endl;
    return;
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