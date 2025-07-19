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

void fun(ll a , ll b , string small , string large){
    // a is smaller
    ll gaps = a+1;
    ll rem = b%(a+1);
    ll pro = b/(a+1);
    ll t = a;
    ll remaining = abs(gaps - rem);//without adding rem part
    for (ll i = 0; i <(rem); i++)
    {
        for (ll j = 0; j < (pro + 1); j++)
        {
            cout<<large;
        }
        cout<<small;
        t--;
        
    }
    for (ll i = 0; i < abs(gaps - rem); i++)
    {
      // cout<<small<<"";
      for (ll j = 0; j < (pro); j++)
      {
        cout<<large<<"";
      }
      if(t>0){
        cout<<small;
        t--;
      }
      
    }
    cout<<endl;
    
    
}

void solve(){
  //your code starts from here
  ll n , a,b;
  cin>>n>>a>>b;
  if(a>b){
    fun(b,a,"B","R");
  }
  else{
    fun(a,b,"R","B");
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