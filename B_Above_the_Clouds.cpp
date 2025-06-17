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
  vector<ll> freq(26,0);
//   ll n = s.length();
  char a = s[0];
  char c = s[n - 1];
  for (ll i = 1; i <=n-2; i++)
  {
    // cout<<"ran\n";
    freq[s[i] - 'a']++;
  }
//   cout<<freq[0]<<endl;
  if(freq[a - 'a']>0 || freq[c - 'a']>0){
    cout<<"Yes"<<endl;
    return;
  }
  ll maxi = *max_element(freq.begin(),freq.end());
  if(maxi>1){
    cout<<"Yes"<<endl;
    return;
  }
  cout<<"No"<<endl;
  
  


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