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
  vector <ll> v(5);
  long long cnt = 0;
  for (ll i = 0; i < 5; i++)
  {
    cin>>v[i];
    cnt += v[i];
  }
  if(cnt>=35){
    cout<<0<<endl;
    return;
  }
  else{
    sort(v.begin(),v.end());
    long double l = 1;
    ll ans = 0;
    for (ll i = 0; i < 5; i++)
    {
        cnt = cnt - v[i] + 10 ;
        ans++;
        if(cnt>=35){
            break;
        }
        

        
    }
    cout<<ans*100<<endl;
    
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