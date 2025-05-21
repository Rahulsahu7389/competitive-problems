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
long long modl(ll a)
{
    if (a < 0)
    {
        return -a;
    }
    return a;
}

int modl(int a)
{
    if (a < 0)
    {
        return -a;
    }
    return a;
}

void solve()
{
    // your code starts from here
    ll n, m;
    cin >> n >> m;
    vector<ll> a(5, 0);
    vector<ll> b(5, 0);
    for (ll i = 1; i <=n; i++)
    {
        a[i % 5]++;
    }
    // for (auto val : a)
    // {
    //     cout << val << endl;
    // }
    for (ll i = 1; i <= m; i++)
    {
        b[i % 5]++;
    }
    // for (auto val : b)
    // {
    //     cout << val << endl;
    // }
    ll ans = 0;
    ans += a[0] * b[0];
    for (ll i = 1; i < 5; i++)
    {
        ans += a[i] * b[5 - i];
    }
    cout << ans << endl;
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
//   ll n , m;
//   cin>>n>>m;
//   ll ans = 0;
//   if(m>=n){

//     ll sum = n/5;
//     for (ll i = 1; i <= m; i++)
//     {
//         ll j;
//         ll rem = i%5 ;
//         if(i<5){
//             j = i + 5 - rem;
//             if(j>=1 && j<=n){
//                 ans++;
//                 cout<<j<<" inner"<<endl;
//             }
//         }
//         else if(i == 5){
//             j = 5;
//             if(j>=1 && j<=n){
//                 ans+=sum;
//                 cout<<j<<" inner"<<endl;
//             }
//         }
//         else{
//             if((5- rem)>=1 && (5 - rem)<=n){
//                 ans++;
//                 cout<<j<<" outer"<<endl;
//             }
//             j = (5 - rem) + i;
//             if(j>=1 && j<=n){
//                 ans++;
//                 cout<<j<<" outer"<<endl;
//             }
//         }
//     }

//   }
//   else{
//     ll sum = m/5;
//     for (ll i = 1; i <= n; i++)
//     {
//         ll j;
//         ll rem = i%5 ;
//         if(i<5){
//             j = i + 5 - rem;
//             if(j>=1 && j<=m){
//                 ans++;
//                 cout<<j<<endl;
//             }
//         }
//         else if(i == 5){
//             j = 5;
//             if(j>=1 && j<=m){
//                 ans+=sum;
//                 cout<<j<<endl;
//             }
//         }
//         else{
//             if((5- rem)>=1 && (5 - rem)<=m){
//                 ans++;
//             }
//             j = (5 - rem) + i;
//             if(j>=1 && j<=m){
//                 ans++;
//                 cout<<j<<endl;
//             }
//         }
//     }

//   }
//   cout<<ans<<endl;

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