#include<bits/stdc++.h>
using namespace std; 

#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++) 
#define FORLL(a, c) for (long long(a) = 0; (a) < (c); (a)++) 
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--) 
typedef long long int ll; 
typedef vector<int> vi; 
typedef pair<int, int> pi; 
#define all(a) a.begin(),a.end()
#define F first 
#define S second 
#define pb push_back 
#define pob pop_back 
ll MOD = 1e9 + 7;

template<typename T>
T mod(T a){
  if(a<0) return -a;
  return a;
}

template<typename T>
T power(T x,T n){
  T pro = 1;
  while(n!=0){
    if(n%2==1){
      pro *= x;
    }
    x *= x;
    n /= 2;
  }
  return pro;
}


void solve(){
  //your code starts from here
  string a ,b;
  cin>>a;
  cin>>b;
  string smaller = (a.length()<b.length()?a:b);
  string bigger = (a.length()<b.length()?b:a);
  string ans = "";
  for (ll i = 0; i < smaller.length(); i++)
  {
    for (ll j = i; j < smaller.length(); j++)
    {
        string s = "";
        for (ll k = i; k <=j; k++)
        {
            s += smaller[k];
        }
        // cout<<s<<" and j is : "<<j<<endl;
        if(bigger.find(s)!=string::npos && ans.length()<=s.length()){
            ans = s;
        }
        
    }
    
  }
  ll sum = a.size() - ans.size() + b.size() - ans.size();
  cout<<sum<<endl;
  

  
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