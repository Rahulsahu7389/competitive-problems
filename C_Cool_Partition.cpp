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
  ll grpCnt = 0;
  ll prevGrpSize = 0;
  unordered_set<ll> s;
  for (ll i = 0; i < n; i++)
  {
    if(s.count(v[i])>0 && s.size()>=prevGrpSize){
        grpCnt += 1;
        prevGrpSize = s.size();
        s.clear();
        s.insert(v[i]);
    }
    else{
        s.insert(v[i]);
    }
  }
  //checking jb loop khatam ho gya
  if(s.size()>=prevGrpSize){
    grpCnt += 1;
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