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

vector <ll> v(10001,1);
unordered_map <ll , vector<ll>> m;

void solve(){
  //your code starts from here
  ll d;
  cin>>d;

  for (ll i = 1; i < 10001; i++)
  {
    ll mn = 1e9;
    if(v[i]>=4){
        for (ll j = 1; j < m[i].size(); j++)
        {
            mn = min(modl(m[i][j]-m[i][j-1]),mn);
        }
        if(mn >=d){
            cout<<i<<endl;
            return;
        }
    }
  }
  
  

}
int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 

    
    for (ll i = 2; i*i < 10001; i++)
    {   
        for (ll j = i; j <10001; j+=i)
        {
            if(j%i==0){
                v[j]++;
                if(m.find(j)==m.end()){
                    m[j] = {1,i};
                }
                else{
                    m[j].pb(i);
                }
            }
        }
        
    }
    




    ll T; 
    cin >> T; 
    while (T--) { 
        solve(); 
    } 
    return 0; 
} 