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
  vector <ll> a(n);
  for (ll i = 0; i < n; i++)
  {
    cin>>a[i];
  }
//   if(a[0]^a[1]!=0){
//     if(a[1]^a[2]!=0){
//         // cout<<"inside the if wala\n";
//         cout<<2<<endl;
//         return;
//     }
//     else{
//         // cout<<"inside else part\n";
//         cout<<1<<endl;
//         return;
//     }
//   }
//   else{
//     for (ll i = 2; i < n; i++)
//     {
//         if(a[i]^a[i-1]!=0){
//             cout<<i+1<<endl;
//             return;
//         }
//     }
    
//   }
  ll idx = -1;
  if(a[0]!=a[1]){
    if(a[1] == a[2]){
        //so a[1] is not the one
        cout<<1<<endl;
        return;
    }
    else{
        cout<<2<<endl;
        return;
    }
  }
  else{
    for (ll i = 1; i < n; i++)
    {
        if(a[i] != a[i-1]){
            cout<<i+1<<endl;
            return;
        }
    }
    
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