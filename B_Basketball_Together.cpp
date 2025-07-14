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
  ll n,d;
  cin>>n>>d;
  vector<ll> v(n);
  for (ll i = 0; i < n; i++)
  {
    cin>>v[i];
  }

  if(n == 1){
    if(v[0]>d){
        cout<<1<<endl;
    }
    else{
        cout<<0<<endl;
        
    }
    return;
  }

  sort(all(v));

  ll i = 0;
  ll j = n-1;
  ll cnt = 1;
  ll ans = 0;
  while(v[j]>d && j>=0){
    // cout<<ans<<endl;
    ans++;
    j--;
  }
  
  while(i<j){
    if(v[i]>d){
        ans++;
        i++;
        continue;
    }
    if(v[j]>d){
        ans++;
        j--;
        continue;
    }
    if((v[j]*(cnt+1))>d){
        cnt = 1;
        ans++;
        i++;j--;
        continue;
    }
    if((v[j]*(cnt+1))<=d){
        cnt++;
        i++;
    }

  }
  if(i == j && (v[j]*(cnt)>d)){
    ans++;
  }
  cout<<ans<<endl;
  

  
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