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
  string s;
  cin>>s;
  if(n==1){
    if(s[0]=='1'){
        cout<<"Yes"<<endl;
        return;
    }
    else{
        cout<<"No"<<endl;
        return;
    }
  }
  vector<bool> v(n,false);

  for (ll i = 0; i < n; i++)
  {
    // ll cnt = 2;
    if(s[i]=='1'){
        // cout<<"chla\n";
        if(i==0){
            v[i] = true;
            v[i+1] = true;//workks for length >=2
            continue;
        }
        else if(i==n-1){
            // if(v[i-1]==false){
                v[i-1] = true;
                v[i] = true;
            // }
            continue;
        }
        else{
            if(v[i-1]==false){
                v[i-1] = true;
                v[i] = true;
            }
            else{
                v[i] = true;
                v[i+1] = true;
            }
            continue;
        }
    }
  }
//   for(auto val:v){
//     cout<<val<<endl;
//   }
  for (ll i = 0; i < n; i++)
  {
    if(v[i]==false){
        cout<<"No"<<endl;
        return;
    }
  }
  cout<<"Yes"<<endl;
  
  

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