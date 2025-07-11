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
  vector<ll> v(n);
  for (ll i = 0; i < n; i++)
  {
    cin>>v[i];
  }
  ll grpCnt = 1;
  ll u = 1;
  set<ll> s1;
  set<ll> s2;
  s1.insert(v[0]);
  s2.insert(v[0]);
  for (ll i = 1; i < n; i++)
  {

    if(s2.count(v[i])>0){
      s2.erase(v[i]);
    }
    if(s2.size()==0){
      grpCnt++;
      s2 = s1;
      
    }
    // s2.insert(v[i]);
    s1.insert(v[i]);
  }
  cout<<grpCnt<<endl;
  
  
  

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

//note we can assign a set to another set thus prevent us from going to insert all the element again till the i 