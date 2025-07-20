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

ll getmsb(ll n){
    string s = "";
    while(n!=0){
        ll rem = n%2;
        if(rem == 1){
            s += '1';
        }
        else{
            s += '0';
        }
        n /= 2;
    }
    return s.size();

}


void solve(){
  //your code starts from here
  ll n;
  cin>>n;
  ll msb = n-1;
  ll val = getmsb(msb);
  ll lb = power(1LL*2,val-1) - 1;
  ll t = lb;
  while(t>=0){
    cout<<t<<" ";
    t--;
  }
  for (ll i = lb+1; i < (n); i++)
  {
    cout<<i<<" ";

  }
  cout<<endl;
  


  
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