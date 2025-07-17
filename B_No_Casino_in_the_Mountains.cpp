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
  vector<ll> v(n);
  ll cntone = 0;
  ll cntzero = 0;
  ll counter = 0;
  ll cnt = 0;
  for (ll i = 0; i < n; i++)
  {
    cin>>v[i];
    if(v[i] == 0){
        cntzero++;
    }
    else{
        cntone++;
    }
  }
  if(cntone == n){
    cout<<0<<endl;
    return;
  }
  for (ll i = 0; i < n; i++)
  {
    while(i<n && v[i] == 1){
        i++;
    }
    counter = 0;
    while(i<n && v[i] == 0){
        counter++;
        i++;
        if(counter == k){
            cnt++;
            counter = 0;
            break;

        }
        
    }
  }
  if(counter>=k){
    cnt++;
  }
  cout<<cnt<<endl;
  

  

  
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