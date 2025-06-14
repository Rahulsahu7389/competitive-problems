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
    ll n;
    cin >> n;
    vector<ll> v(n);
    unordered_map<ll, ll> m;
    ll maxi = -5;
    vector<pair<ll, ll>> suffix;
    
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];

        // if(m.find(v[i])==m.end()){
        //     m[v[i]] = -1;
        // }
        if (maxi <= v[i])
        {
            maxi = v[i];
            suffix.pb({v[i], maxi});
        }
        if (maxi > v[i])
        {
            m[v[i]] = maxi;
            suffix.pb({v[i], maxi});
        }
    }
   
    ll preSum = 0;
    for (ll i = n - 1; i >= 0; i--)
    {
        // ll ans = 0;
        preSum = v[i] + preSum;
        // if (suffix[i].second > v[i])
        // {
        //     ans += (curr - v[i] + m[v[i]]);
        // }
        // else
        // {
        //     ans += (curr);
        // }
        cout << (preSum - v[i] + suffix[i].second) << " ";
    }
    cout << endl;
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