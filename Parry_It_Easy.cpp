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
  ll n,x;
  cin>>n>>x;
  vector<ll> a(n);
  vector<ll> b(n);
  stack <ll> st;
  ll maxy = -1;
  for (ll i = 0; i < n; i++)
  {
    cin>>a[i];
    

  }
  for (ll j = 0; j < n; j++)
  {
    cin>>b[j];
    maxy = max(maxy,a[n-j-1]);
    st.push(maxy);
  }
  ll m = 0;
  // cout<<maxy<<endl;
  // while(!st.empty()){
  //   cout<<st.top()<<endl;
  //   st.pop();
  // }
  
  for (ll i = 0; i < n; i++)
  {
    st.pop();
    if(i == n-1){
      if((x>=b[i])){
        m++;
      }
      continue;
    }
    if((x-1>=st.top()) && (x>=b[i])){
      m++;
      x--;
      
    }
    // st.pop();
  }
  cout<<m<<endl;
  
  
  
  

}
int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    ll T;
    cin >> T;
    while(T--){
      solve();
    }
    
    
    
    return 0; 
} 