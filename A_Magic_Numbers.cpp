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
  string s1 = "1";
  for (ll i = 0; i < s.length(); i++)
  {
    string s2 = "";
    string s3 = "";
    s3+= s[i];
    s3+= s[i+1];
    s3+=s[i+2];
    s2+=s[i];
    s2+=s[i+1];
    // cout<<"s3 is : "<<s3<<endl;
    if((s3 == "144") && (i+1 < s.length()) && (i+2 < s.length())){
        // cout<<"first\n";
        i = i + 2;
    }
    else if(s2 == "14" && (i+1 < s.length())){
        // cout<<"second\n";
        i = i + 1;
    }
    else if(s[i] == '1'){
        // cout<<"third\n";
        continue;
    }
    else{
        cout<<"NO"<<endl;
        return;
    }
  }
  cout<<"YES"<<endl;
  
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