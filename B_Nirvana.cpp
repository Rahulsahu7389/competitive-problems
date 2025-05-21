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

ll product(ll n){
  ll pro = 1;
  while(n>0){
    ll rem = n%10;
    if(rem !=0){
      pro *= rem;
    }
    n /= 10;
  }
  return pro;
}


void solve(){
  //your code starts from here
  ll n;
  cin>>n;
  ll ans = -1e9;
  ll p = 1;
  ans = product(n);
  ll x = n;
  while(x>0){
    ll sum = product(x*p - 1);
    p *= 10;
    ans = max(ans,sum);
    x /= 10;
  }
  cout<<ans<<endl;


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
//   ll x = n;
//   ll cnt = 0;
//   ll pro = 1;
//   vector <ll> v;
//   while(x>0){
//     ll rem = x%10;
//     cnt++;
//     if(rem==0){
//       v.pb(rem);
//     }
//     if(rem!=0){

//         pro *= rem;
//         v.pb(rem);
//     }
//     x /= 10;
//   }
//   if(cnt==1){
//     cout<<pro<<endl;
//     return;
//   }
//   reverse(v.begin(),v.end());
//   // for(auto val:v){
//   //   cout<<val<<endl;
//   // }
//   //changing
//   ll changedp = pro;
//   // cout<<pro<<endl;
//   for (ll i = v.size() -1; i>=0 ; i--)
//   {
//     if(v[i]!=0 && i ==0){
//       continue;
//     }
//     if(v[i] == 0 && i>=1){
//       changedp = (changedp)*9;
      
//       if(v[i-1]>0){
//         changedp = (changedp/v[i-1]);
//         v[i-1]--;
//       }
//       else{
//         v[i-1] = 9;
//       }
      
//       changedp = changedp*v[i-1];
//       pro = max(changedp , pro);
//       // cout<<i<<" "<<pro<<" "<<changedp<<" upper0"<<endl;

//     }
//     if(v[i]!=0 && i>=1){
//       changedp = (changedp/v[i])*9;
      
//       if(v[i-1]>0){
//         changedp = (changedp/v[i-1]);
//         v[i-1]--;
//       }
//       else{
//         v[i-1] = 9;
//       }
      
//       changedp = changedp*v[i-1];
//       pro = max(changedp , pro);
//       // cout<<i<<" "<<pro<<" "<<changedp<<" lower"<<endl;
//     }
    
//   }
  
  
  
//   cout<<pro<<endl;
  


// }
// int main() 
// { 
//     ios::sync_with_stdio(0); 
//     cin.tie(0); 
//     // ll T; 
//     // cin >> T; 
//     // while (T--) { 
//         solve(); 
//     // } 
//     return 0; 
// } 