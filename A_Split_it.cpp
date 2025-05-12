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
  ll n,k;
  cin>>n>>k;
  string s;
  cin>>s;

  //2conditions 
  //1.2k+ 1 > n 
  //2.first k characters and last k characters must be a palindrome
  
  if(k == 0){
    cout<<"YES"<<endl;
    return;
  }
  if(2*k+1 > n){
    //this is to check if 2k + 1 strings hai if they are greater than the actual number of strings so false
    cout<<"NO"<<endl;
    return;
  }
  bool flag = true;
  for(ll i = 0 ; i<k ; i++){
    if(s[i]!=s[n - i -1]){
      flag = false;
      break;
    }
  }
  if(flag){
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