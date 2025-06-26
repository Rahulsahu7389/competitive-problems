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
  string a;
  string b;
  cin>>a;
  cin>>b;
  ll cnt1 = 0;
  ll cnt2 = 0;
  for (ll i = 0; i <n ; i++)
  {
    if(i%2==0){
        if(a[i]=='0'){
            cnt1++;
        }
        if(b[i] == '0'){
            cnt2++;
        }
    }
    else{
        if(a[i]=='0'){
            cnt2++;
        }
        if(b[i] == '0'){
            cnt1++;
        }
    }
  }
//   cout<<cnt1<<" "<<cnt2<<endl;
  if(cnt1>=(ceil((double)n/2)) && cnt2>=((n/2))){
    cout<<"YES\n";
  }
  
  else{
    cout<<"NO\n";
  }
  
  
  

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