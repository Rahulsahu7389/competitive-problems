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
  string s;
  cin>>s;
  string t= s;
  vector<bool> flag(s.length(),true);
  ll i = 0;
  for (ll j = 0; j < s.length(); j++)
  {
    if(s[i]!=s[j] && flag[j]!=false){
        swap(s[i],s[j]);
        flag[i] = false;
        flag[j] = false;
        while(i<s.length()){
            if(flag[i]==false){
                i++;
            }
            else{
                break;
            }
        }
    }
  }
  int cnt = 0;
  for (ll i = 0; i < s.length(); i++)
  {
    if(t[i]==s[i]){
        break;
    }
    else{
        cnt++;
    }
  }
  cout<<(s.length()-cnt)<<endl;
  
  
  


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