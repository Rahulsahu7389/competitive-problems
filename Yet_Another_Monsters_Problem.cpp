
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
  ll  n;
  cin>>n;
  vector<ll> v(n);
  for (ll i = 0; i < n; i++)
  {
    cin>>v[i];
  }
  ll i = 0;
  sort(v.begin(),v.end());
  ll ans = n;
  for (i; i < n; i++)
  {
    ans = min((v[i]+(n - i -1)),ans);
  }
  cout<<ans<<endl;
  
  

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

// #include "bits/stdc++.h" 
// using namespace std; 

// #define pb push_back 
// #define pob pop_back 
// long long modl(ll a){
//   if(a<0){return -a;}
//   return a;
// }

// int modl(int a){
//   if(a<0){return -a;}
//   return a;
// }


// void solve(){
//   //your code starts from here
//   ll n;
//   cin>>n;
// //   vector<ll> v(n);
//   unordered_set<ll> s;
//   for (ll i = 0; i < n; i++)
//   {
//     ll a;
//     cin>>a;

//     s.insert(a);
//   }
// //   sort(s.begin(),s.end());
// //   ll ansf = 0;
//   ll ansb = s.size();
// //   set<ll> ::iterator it;

// //   for (it = s.begin()+1;it!=s.end();it++)
// //   {
// //     if((*it)>((*(it-1))+1)){

// //     }
// //   }
  
  
//   cout<<ansb<<endl;

  

// }
// int main() 
// { 
//     ios::sync_with_stdio(0); 
//     cin.tie(0); 
//     ll T; 
//     cin >> T; 
//     while (T--) { 
//         solve(); 
//     } 
//     return 0; 
// } 