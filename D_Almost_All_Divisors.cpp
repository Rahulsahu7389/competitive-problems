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
  vector <ll> v(n);
  vector <ll> b;
  for (ll i = 0; i < n; i++)
  {
    cin>>v[i];
  }
  sort(v.begin(),v.end());
  ll original = v[0]*v[n-1];
  for (ll i = 2; i*i<=original; i++)
  {
    if(original%i==0){
        b.pb(i);
        if((original/i)!=i){
            b.pb(original/i);
        }
    }
  }
  sort(b.begin(),b.end());
  if(v==b){
    cout<<original<<endl;
  }
  else{
    cout<<-1<<endl;
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
// #include "bits/stdc++.h" 
// using namespace std; 

// #define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++) 
// #define FORLL(a, c) for (long long(a) = 0; (a) < (c); (a)++) 
// #define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--) 
// #define INF 1000000000000000003 
// typedef long long int ll; 
// typedef vector<int> vi; 
// typedef pair<int, int> pi; 
// #define F first 
// #define S second 
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
//   vector <ll> v(n);
//   for (ll i = 0; i < n; i++)
//   {
//     cin>>v[i];
//   }
//   sort(v.begin(),v.end());
//   ll st = 0;ll end = n-1;
//   ll ans = v[st]*v[end];
//   while(st<=end){
//     if(v[st]*v[end]!=ans){
//         cout<<-1<<endl;
//         return;
//     }
//     st++;end--;
//   }
//   cout<<ans<<endl;
  

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

// #include "bits/stdc++.h"
// using namespace std;

// #define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
// #define FORLL(a, c) for (long long(a) = 0; (a) < (c); (a)++)
// #define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
// #define INF 1000000000000000003
// typedef long long int ll;
// typedef vector<int> vi;
// typedef pair<int, int> pi;
// #define F first
// #define S second
// #define pb push_back
// #define pob pop_back
// long long modl(ll a)
// {
//     if (a < 0)
//     {
//         return -a;
//     }
//     return a;
// }

// int modl(int a)
// {
//     if (a < 0)
//     {
//         return -a;
//     }
//     return a;
// }

// ll gcd(ll a, ll b)
// {
//     if (a == b)
//         return a;
//     else if (a == 0)
//         return b;
//     else if (b == 0)
//         return a;
//     if (a > b)
//     {
//         return gcd(a % b, b);
//     }
//     return gcd(a, b % a);
// }

// void solve()
// {
//     // your code starts from here
//     ll n;
//     cin >> n;
//     vector<ll> v(n);
//     for (ll i = 0; i < n; i++)
//     {
//         cin >> v[i];
//     }
//     if (n == 1)
//     {
//         cout << (v[0] * v[0]) << endl;
//         return;
//     }
//     sort(v.begin(), v.end());
//     ll c = v[n - 1];
//     ll ans = -1e9;
//     for (ll i = 1; i < n; i++)
//     {
//         ll a = v[i];
//         ll b = v[i - 1];
//         ll t = (a * b) / gcd(a, b);
//         if(t>c){
//             ans = max(ans,t);
//         }
//     }
//     if(ans<0){
//         for (ll i = 1; i < n; i++)
//         {
//             if(v[i]*v[0]>v[n-1]){
//                 ans = max(ans,v[i]*v[0]);
//                 break;
//             }
//         }
        
//     }
//     cout<<(ans<0?-1:ans)<<endl;
// }
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     ll T;
//     cin >> T;
//     while (T--)
//     {
//         solve();
//     }
//     return 0;
// }