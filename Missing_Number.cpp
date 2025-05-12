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
  ll n;
  cin>>n;
  vector <ll> v(n-1);
  for (ll i = 0; i < n-1; i++)
  {
    cin>>v[i];
  }
  if(n==2){
    if(v[0]==2){

        cout<<1<<endl;
        return;
    }
    else{
        cout<<2<<endl;
        return;
    }
    return;
  }
  sort(v.begin(),v.end());
  for (ll i = 1; i <n-1 ; i++) 
  {
    if(v[i]!= (v[i-1]+1)){
        cout<<(v[i-1]+1)<<endl;
        return;
    }
  }
  cout<<n<<endl;
  
  

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