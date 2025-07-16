#include<bits/stdc++.h>
using namespace std; 

#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++) 
#define FORLL(a, c) for (long long(a) = 0; (a) < (c); (a)++) 
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--) 
typedef long long int ll; 
typedef vector<int> vi; 
typedef pair<int, int> pi; 
#define all(a) a.begin(),a.end()
#define F first 
#define S second 
#define pb push_back 
#define pob pop_back 
ll MOD = 1e9 + 7;

template<typename T>
T mod(T a){
  if(a<0) return -a;
  return a;
}

template<typename T>
T power(T x,T n){
  T pro = 1;
  while(n!=0){
    if(n%2==1){
      pro *= x;
    }
    x *= x;
    n /= 2;
  }
  return pro;
}


void solve(){
  //your code starts from here
  ll n,k;
  cin>>n>>k;
  string s;
  cin>>s;
  ll prefix[n];
  prefix[0] = ((s[0] == 'B')?(0):1);
  for (ll i = 1; i < n; i++)
  {
    if(s[i]=='W'){
        prefix[i] = prefix[i-1] + 1;
    }
    else{
        prefix[i] = prefix[i-1];
    }
  }
  ll ans = (prefix[k-1]);

  for (ll i = k; i < n; i++)
  {
    ll nowhite = prefix[i] - prefix[i - k];
    ans = min(ans , nowhite);
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