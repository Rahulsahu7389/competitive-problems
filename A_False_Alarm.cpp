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
  ll cntclosed = 0;
  vector <ll> v(n);
  for (ll i = 0; i < n; i++)
  {
    cin>>v[i];
    if(v[i] == 1){
        cntclosed++;
    }
  }
  bool flag = false;
  for (ll i = 0; i < n; i++)
  {
    if(v[i]==1 && flag == false){
        while (x>0)
        {
            if(v[i] == 1){
                cntclosed--;
            }
            x--;
            i++;
        }

        flag = true;
        if(cntclosed<=0){
            cout<<"YES"<<endl;
            return;
        }
        i--;
        continue;
        
    }
    
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