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
  ll x,y,z;
  cin>>x>>y>>z;
  if(x == 0){
    cout<<"Yes"<<endl;
    return;
  }
  if(y == 0){
    // if(z == 1 && x <= 2){
    //     cout<<"Yes"<<endl;
    //     return;
    // }
    // else if(2*z - 1 >= x){
    //     cout<<"Yes"<<endl;
    //     return;
    // }
    // else{
    //     cout<<"No"<<endl;
    //     return;
    // }
    if(z == 0){
        cout<<"No"<<endl;
        return;
    }
    if(x == 0){
        cout<<"Yes"<<endl;
        return;
    }
    if((x<=(z+1))){
        cout<<"Yes"<<endl;
        return;
    }
    else{
        cout<<"No"<<endl;
        return;
    }
    

  }
  if(z == 0 ){
    if(x!=0){
        cout<<"No"<<endl;
        return;
    }
    else{
        cout<<"Yes"<<endl;
        return;
    }
  }
  else{
    if((x<=(z))){
        cout<<"Yes"<<endl;
        return;
    }
    else{
        cout<<"No"<<endl;
        return;
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

// void solve(int X, int Y, int Z) {
    
//     if(Z == 0){
//         cout<<"No"<<endl;
//         return;
//     }
//     if (Z == 0 && Y == 0) { 
//         cout << "No" << endl;
//         return;
//     }
//     if (X > Y + Z + 1) { 
//         cout << "No" << endl;
//         return;
//     }
    
//     cout << "Yes" << endl;
// }

// int main() {
//     int T;
//     cin >> T;
//     while (T--) {
//         int X, Y, Z;
//         cin >> X >> Y >> Z;
//         solve(X, Y, Z);
//     }
//     return 0;
// }