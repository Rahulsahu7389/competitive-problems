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

// void solve2(vector<ll> &v){
//     ll i,x;
//     cin>>i>>x;
//     v[i-1] = x;
//     ll ans = -1;
//     ll s1 = 0;
//     ll s2 = 0;

//     ll j = 0;
//     for (ll i = 1; ((i < v.size())&&(j<v.size())) ; i++)
//     {
//         if(v[i]<v[j]){
//             s1 += min(v[i],v[j]);
//             j = i;
//         }
//         else{
//            s1 += min(v[i],v[j]);
//         }
//     }
//     j = v.size()-1;
//     for (ll i = v.size()-2; ((i >=v.size())&&(j>=v.size())) ; i--)
//     {
//         if(v[i]>v[j]){
//             s2 += min(v[i],v[j]);
            
//         }
//         else{
//            s2 += min(v[i],v[j]);
//             j = i;
//         }
//     }

//     ans = max(s1,s2);
//     cout<<ans<<endl;
    
// }


// void solve(){
//   //your code starts from here
//   ll n,q;
//   cin>>n>>q;
//   vector<ll> v(n);
//   for (ll i = 0; i < n; i++)
//   {
//     cin>>v[i];
//   }
//   while(q--){
//     solve2(v);
//   }
  

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


#include <bits/stdc++.h>
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

// ll solve2(const vector<ll> &v) {
//     ll score = 0;
//     for (int i = 0; i < (int)v.size() - 1; i++) {
//         score += min(v[i], v[i + 1]);
//     }
//     return score;
// }

void solve() {
    ll n, q;
    cin >> n >> q;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++) cin >> v[i];

    ll total = 0;
    for (int i = 0; i < n - 1; i++) {
        total += min(v[i], v[i + 1]);
    }

    while (q--) {
        ll idx, x;
        cin >> idx >> x;
        idx--;

        if (idx > 0) total -= min(v[idx], v[idx - 1]);
        if (idx < n - 1) total -= min(v[idx], v[idx + 1]);

        v[idx] = x;

      if (idx > 0) total += min(v[idx], v[idx - 1]);
        if (idx < n - 1) total += min(v[idx], v[idx + 1]);

        cout << total << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {

        solve();
    }
}
