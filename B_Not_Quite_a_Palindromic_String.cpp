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
  ll n,k;
  cin>>n>>k;
  string s;
  cin>>s;
  ll countZero = 0;
  ll countOne = 0;
  for (ll i = 0; i < n; i++)
  {
    if(s[i] == '0'){
        countZero++;
    }
    else{
        countOne++;
    }
  }
  ll sum = (n - 2*k)/2;//assuming that pair exists
  if((countOne - sum)>=0 && (countOne-sum)%2==0 && (countZero - sum)>=0 && (countZero - sum)%2==0){
    cout<<"YES"<<endl;
    return;
  }
  else{
    cout<<"NO"<<endl;
  }
  

  // ll sz = s.length();
  // ll countZero = 0;
  // ll countOne = 0;
  // for (ll i = 0; i < sz; i++)
  // {
  //   if(s[i] == '0'){
  //       countZero++;
  //   }
  //   else{
  //       countOne++;
  //   }
  // }
//   if(countOne == n || countZero == n){
//     cout<<"NO"<<endl;
//     return;
//   }
//   cout<<countOne<<" "<<countZero<<endl;
//   ll mx = max(countOne,countZero);
//   ll mn = min(countOne,countZero);
//   ll sum = mx - 2*k;
// //   cout<<sum<<" "<<mn<<endl;
//   if(sum == 0 && mn!=0){
//     cout<<"NO"<<endl;//as no pair left
//     return;
//   }
//   else if(sum ==0 && mn == 0){
//     cout<<"YES"<<endl;
//     return;
//   }
//   else{

//       if(sum != mn){
//           cout<<"NO"<<endl;
//           return;
//     }
//     else{
//         cout<<"YES"<<endl;
//         return;
//     }

  
  

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