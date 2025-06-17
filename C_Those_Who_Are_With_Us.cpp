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
//     ll n, m;
//     cin >> n >> m;
//     vector<vector<ll>> v(n, vector<ll>(m));
//     ll maxi = -1e9;
//     for (ll i = 0; i < n; i++)
//     {
//         for (ll j = 0; j < m; j++)
//         {
//             cin >> v[i][j];
//             maxi = max(maxi, v[i][j]);
//         }
//     }
//     ll cnt = 0;
//     for (const auto &row : v)
//     {
//         cnt += count(row.begin(), row.end(), maxi);
//     }
//     // cout << cnt << endl;
//     for (ll i = 0; i < n; i++)
//     {
//         for (ll j = 0; j < m; j++)
//         {
//             if (v[i][j] == maxi)
//             {
//                 // column me jao
//                 ll temp = 0;
//                 for (ll k = 0; k < n; k++)
//                 {
//                     if (v[k][j] == maxi)
//                     {
//                         temp++;
//                     }
//                 }
//                 for (ll k = 0; k < m; k++)
//                 {
//                     if (v[i][j] == maxi)
//                     {
//                         temp++;
//                     }
//                 }
//                 if (temp == cnt)
//                 {
//                     cout << (maxi - 1) << endl;
//                     return;
//                 }
//             }
//         }
//     }
//     cout << maxi << endl;
// }
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     ll T;
//     cin >> T;
//     while (T--)
//     {
//         solve();
//     }
//     return 0;
// }

#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define INF 1e9

void solve() {
    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> v(n, vector<ll>(m));
    ll maxi = -INF;

    // Step 1: Read input and find max value
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cin >> v[i][j];
            maxi = max(maxi, v[i][j]);
        }
    }

    // Step 2: Store all positions having max value
    vector<pair<ll, ll>> max_positions;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if (v[i][j] == maxi) {
                max_positions.emplace_back(i, j);
            }
        }
    }

    // Step 3: Try applying operation at each (row, col) that has a max value
    ll result = maxi;
    for (auto &[r, c] : max_positions) {
        ll local_max = -INF;

        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                ll new_val = v[i][j];
                if (i == r || j == c) new_val--; // operation applied
                local_max = max(local_max, new_val);
            }
        }

        result = min(result, local_max); // pick the best result
    }

    cout << result << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
