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
//   cout<<"here\n";
//   ll n,m;
//   cin>>n>>m;
//   vector<vector<ll>> ans(n , vector<ll>(m));
//   bool flag = false;
//   for (ll i = 0; i < n; i++)
//   {
//     for (ll j = 0; j < m; j++)
//     {
//         // ll a;
//         cin>>ans[i][j];

//     }

//   }
//   for (ll i = 0; i < n; i++)//sorting each rows
//   {
//     sort(ans[i].begin(),ans[i].end());
//   }
//   vector<ll> p(n);
//   for (ll i = 0; i < n; i++)
//   {
//     p[i] = i + 1;
//   }

//   for (ll i = 0; i < n; i++)
//   {
//     for (ll j = i+1; j < m; j++)
//     {
//         //checking by the first method of difference
//         if(ans[i][0]>ans[j][0]){
//             swap(ans[i],ans[j]);
//             swap(p[i],p[j]);
//         }
//     }

//   }
//   for (ll i = 0; i < m; i++)
//   {
//     for (ll j = 0; j < n; j++)
//     {
//         if(ans[j][i] != (i*n + j)){
//             cout<<-1<<endl;
//             return;
//         }
//     }

//   }
//   for(auto val : p){
//     cout<<val<<" ";
//   }
//   cout<<endl;

// }
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     ll T;
//     cin >> T;
//     while (T--) {
//         cout<<"here1\n";
//         solve();
//     }
//     return 0;
// }

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
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> ans(n, vector<ll>(m));
    bool flag = false;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            // ll a;
            cin >> ans[i][j];
        }
    }
    for (ll i = 0; i < n; i++) // sorting each rows
    {
        sort(ans[i].begin(), ans[i].end());
    }
    vector<ll> p(n);
    for (ll i = 0; i < n; i++)
    {
        p[i] = i + 1;
    }
    for (ll i = 0; i < n; i++)
    {
        for (ll j = i + 1; j < n; j++)
        {
            // checking by the first method of difference
            if (ans[i][0] > ans[j][0])
            {
                swap(ans[i], ans[j]);
                swap(p[i], p[j]);
            }
        }
    }
    for (ll i = 0; i < m; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (ans[j][i] != (i * n + j))
            {
                cout << -1 << endl;
                return;
            }
        }
    }
    for (auto val : p)
    {
        cout << val << " ";
    }
    cout << endl;
    // cout << "here\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}