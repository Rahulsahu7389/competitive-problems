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
  ll n;
  cin>>n;
  ll x = n;
  ll cnt = 0;
  ll pro = 1;
  while(x>0){
    ll rem = x%10;
    cnt++;
    if(rem!=0){

        pro *= rem;
    }
    x /= 10;
  }
  if(cnt==1){
    cout<<pro<<endl;
    return;
  }
  x= n;
  //changing
  ll splus ;
  for (ll i = 0; i < cnt; i++)
  {
      ll rem = x%10;
      if(i == n-1 && rem == 1){
        break;
      }
    if(rem == 0){
        pro = pro*9;
    }
    if(rem!=0){
        ll p = pro;
        if(((p/rem)*9)>p){
            pro /= rem;
            pro *= 9;
            splus = 1;
        }

    }
    x /= 10;

  }
  cout<<pro<<endl;
  


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