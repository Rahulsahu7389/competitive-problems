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

// ll noswap(vector<ll> & v ,vector<pair<ll,ll>>&t,ll k){
//     ll ans = 0;
//     for (ll i = 0; i < v.size()-1; i++)
//     {
//         for (ll j = 0; j < v.size()-1; j++)
//         {
//             if(v[j]>v[j+1]){
//                 swap(v[j],v[j+1]);
//                 t.push_back({k,j+1});
//                 ans++;
//             }
//         }
        
//     }
//     return ans;
    
// }


// void solve(){
//   //your code starts from here
//   ll n;
//   cin>>n;
//   vector<ll> a(n);
//   vector<ll>b(n);
//   vector<pair<ll,ll>> t;
//   for (ll i = 0; i < n; i++)
//   {
//     cin>>a[i];
//   }
//   for (ll i = 0; i < n; i++)
//   {
//     cin>>b[i];
//   }
//   ll ans = 0;
//   ans += (noswap(a,t,1));
//   ans += (noswap(b,t,2));
//   for (ll i = 0; i < n; i++)
//   {
//     if(a[i]<b[i]){
//         t.push_back({3,i+1});
//         ans++;
//     }
//   }
//   cout<<ans<<endl;
//   for(auto val:t){
//     cout<<val.first<<" "<<val.second<<endl;
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

#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

ll noswap(vector<ll>& v, vector<pair<ll, ll>>& ops, ll op_type) {
    ll count = 0;
    for (ll i = 0; i < v.size(); ++i) {
        for (ll j = 0; j < v.size() - 1; ++j) {
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
                ops.push_back({op_type, j + 1}); // Operation at position j+1
                count++;
            }
        }
    }
    return count;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    vector<pair<ll, ll>> ops;

    for (ll i = 0; i < n; i++) cin >> a[i];
    for (ll i = 0; i < n; i++) cin >> b[i];

    // First ensure a[i] >= b[i]
    for (ll i = 0; i < n; i++) {
        while (a[i] < b[i]) {
            a[i]++;
            ops.push_back({3, i + 1});
        }
    }

    // Then sort both arrays
    noswap(a, ops, 1); // sort a
    noswap(b, ops, 2); // sort b

    cout << ops.size() << '\n';
    for (auto t : ops) {
        cout << t.first << " " << t.second << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll T;
    cin >> T;
    while (T--) solve();
    return 0;
}
