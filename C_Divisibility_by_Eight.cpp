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
    string s;
    cin >> s;
    ll n = s.length();
    if (n >= 1)
    {

        for (ll i = 0; i < n; i++)
        {
            if (s[i] == '8' || s[i] == '0')
            {
                cout << "YES" << endl;
                cout << s[i] << endl;
                return;
            }
        }
    }

    if (n >= 2)
    {
        for (ll i = 0; i < n; i++)
        {
            for (ll j = i + 1; j < n; j++)
            {
                ll sum = (s[i] - '0') * 10 + (s[j] - '0');
                if (sum % 8 == 0)
                {
                    cout << "YES" << endl;
                    cout << sum << endl;
                    return;
                }
            }
        }
    }
    if (n >= 3)
    {
        for (ll i = 0; i < n; i++)
        {
            for (ll j = i + 1; j < n; j++)
            {
                for (ll k = j + 1; k < n; k++)
                {
                    ll sum = (s[i] - '0') * 100 + (s[j] - '0') * 10 + (s[k] - '0');
                    if (sum % 8 == 0)
                    {
                        cout << "YES" << endl;
                        cout << sum << endl;
                        return;
                    }
                }
            }
        }
    }
    cout << "NO" << endl;
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

// void solve()
// {
//     // your code starts from here
//     ll n;
//     cin >> n;
//     vector<ll> v;
//     ll x = n;
//     ll cnt = 0;
//     while (x != 0)
//     {
//         ll rem = x % 10;
//         if (rem == 0)
//         {
//             cnt++;
//         }
//         v.pb(rem);
//         x /= 10;
//     }

//     reverse(v.begin(), v.end());
//     ll sz = v.size();
//     cout<<cnt<<endl;

//     if (cnt > 0)
//     {
//         cout << "YES" << endl;
//         cout << 0 << endl;
//         return;
//     }
//     if (sz == 1)
//     {
//         if (v[0] % 8 == 0)
//         {
//             cout << "YES" << endl;
//             cout << v[0] << endl;
//             return;
//         }
//     }
//     if (sz == 2)
//     {
//         if (n % 8 == 0)
//         {

//             cout << "YES" << endl;
//             cout << n << endl;
//             return;
//         }
//     }

//     for (ll i = 0; i < sz; i++)
//     {
//         if (v[i] % 8 == 0)
//         {
//             cout << "YES" << endl;
//             cout << v[i] << endl;
//             return;
//         }
//         for (ll j = i + 1; j < sz; j++)
//         {
//             if (v[j] % 8 == 0)
//             {
//                 cout << "YES" << endl;
//                 cout << v[j] << endl;
//                 return;
//             }
//             for (ll k = j + 1; k < sz; k++)
//             {
//                 if (v[k] % 8 == 0)
//                 {
//                     cout << "YES" << endl;
//                     cout << v[k] << endl;
//                     return;
//                 }
//                 if ((v[i] * 10 + v[j]) % 8 == 0)
//                 {
//                     cout << "YES" << endl;
//                     cout << (v[i] * 10 + v[j]) << endl;
//                     return;
//                 }
//                 if ((v[j] * 10 + v[k]) % 8 == 0)
//                 {
//                     cout << "YES" << endl;
//                     cout << (v[j] * 10 + v[k]) << endl;
//                     return;
//                 }
//                 if ((v[i] * 10 + v[k]) % 8 == 0)
//                 {
//                     cout << "YES" << endl;
//                     cout << (v[i] * 10 + v[k]) << endl;
//                     return;
//                 }

//                 if ((v[i] * 100 + v[j] * 10 + v[k]) % 8 == 0)
//                 {
//                     cout << "YES" << endl;
//                     cout << (v[i] * 100 + v[j] * 10 + v[k]) << endl;
//                     return;
//                 }
//             }
//         }
//     }
//     cout << "NO" << endl;
// }
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     // ll T;
//     // cin >> T;
//     // while (T--) {
//     solve();
//     // }
//     return 0;
// }