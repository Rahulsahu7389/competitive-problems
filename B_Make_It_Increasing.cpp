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

ll power(ll x , ll n){
    ll pro = 1;
    while(n>0){
        if(n%2 == 1){
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
  vector <ll> v(n);
  for (ll i = 0; i < n; i++)
  {
    cin>>v[i];
  }
  if(n==1){
    cout<<0<<endl;
    return;
  }
//   cout<<power(2,5)<<endl;
  if(is_sorted(v.begin(),v.end())){
    cout<<0<<endl;
    return;
  }
  ll ans = 0;
    long double l = 1;
  for (ll i = n-1; i >0; i--)
  {
    if(v[i]<=v[i-1]){
        while(v[i]<=v[i-1]){
            if(v[i] == 0 && v[i-1]!=0){
                cout<<-1<<endl;
                return;
            }
            v[i-1] = v[i-1]/2;
            // cout<<v[i-1]<<endl;
            ans++;
        }
    }
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