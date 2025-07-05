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
  ll n;
  cin>>n;
  vector<ll> f;
  vector<ll> s;
  for (ll i = 0; i < n; i++)
  {
    ll m;
    cin>>m;
    vector<ll> temp;
    for (ll j = 0; j < m; j++)
    {
        ll a;
        cin>>a;
        temp.pb(a);
    }
    sort(all(temp));
    f.pb(temp[0]);
    s.pb(temp[1]);
    
  }
  sort(all(s));
  f.pb(s[0]);
  s[0] = 0;
  ll sum = accumulate(all(s),0LL);
  ll mini = *min_element(all(f));
  cout<<(mini + sum)<<endl;
  

  
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