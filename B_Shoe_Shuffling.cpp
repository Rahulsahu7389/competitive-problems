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
  ll n;
  cin>>n;
  vector<ll> v(n);
  unordered_map<ll,ll> m;
  map<ll,vector<ll>> m2;
  ll mini = 2e9;
  for (ll i = 0; i < n; i++)
  {
    cin>>v[i];
    m[v[i]]++;
    if(m2.find(v[i])==m2.end()){
        m2[v[i]] = {i+1};
    }
    else{
        m2[v[i]].pb(i+1);
    }
  }
//   cout<<"here\n";
  
  for(auto val:m){
    mini = min(mini , val.second);
  }
  if(mini == 1){
    cout<<-1<<endl;
    return;
  }
  for (auto &&i : m2)
  {
    ll ft = i.second[0];
    for (ll j = 1; j < i.second.size(); j++)
    {
        cout<<(i.second[j])<<" ";
    }
    
    cout<<ft<<" ";
    
  }
  cout<<endl;
  

  

  
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