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
//   approach-1
//   map<char,ll> v;
//   for (ll i = 0; i < s.length(); i++)
//   {
//     v[s[i]]++;
//   }
//   for(auto val: v){
//     cout<<val.first<<" "<<val.second<<endl;
//   }
    // approach-2
    vector <ll> v1(26,0);
    vector <ll> v2(26,0);//upper
    for (ll i = 0; i < s.length(); i++)
    {
        if(s[i]>='a' && s[i]<='z'){
            // cout<<i<<" "<<"lower"<<endl;
            v1[s[i]-'a']++;
        }
        else if(s[i]>='A' && s[i]<='Z'){
            // cout<<i<<" "<<"upper"<<endl;
            v2[s[i]-'A']++;
        }
    }
    
    for (ll i = 0; i < 26; i++)
    {
        if(v2[i]!=0){
            cout<<(char)('A'+i)<<" "<<v2[i]<<endl;
        }
    }
    for (ll i = 0; i < 26; i++)
    {
        if(v1[i]!=0){
            cout<<(char)('a'+i)<<" "<<v1[i]<<endl;
        }
    }
    
    
  


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