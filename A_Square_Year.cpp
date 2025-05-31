// // #include "bits/stdc++.h" 
// #include<iostream>
// #include<cmath>
// #include <string>
// using namespace std; 
// typedef long long int ll;


// long long modl(ll a){
//   if(a<0){return -a;}
//   return a;
// }

// int modl(int a){
//   if(a<0){return -a;}
//   return a;
// }

// bool isSquare(ll a){
//     ll v = sqrt(a);
//     return (v*v == a);
// }


// void solve(){
//   //your code starts from here
//   ll n;
//   string s;
//   cin>>s;
//   n = stoll(s);
//   if(isSquare(n)){
//     ll v = sqrtl(n);
//     cout<<v<<" "<<0<<endl;
//     return;
    
//   }
//   cout<<-1<<endl;
  

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
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

typedef long long int ll;

bool isSquare(ll a){
    ll root = sqrt(a);
    return root * root == a;
}

void solve(){
    ll n;
    string s;
    cin >> s;
    n = stoll(s);  // Use stoll, not stoi
    if(isSquare(n)){
        ll v = sqrt(n);
        cout << v << " " << 0 << endl;
        return;
    }
    cout << -1 << endl;
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
