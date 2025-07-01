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
    ll n, k, j;
    cin >> n >> j >> k;
    vector<ll> v(n);
    ll cnt = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ll t = v[j - 1];
    cnt += count(v.begin(), v.end(), t);
    sort(v.begin(), v.end());
    ll maxi = v.back();
    auto it = find(v.begin(), v.end(), t);
    ll lb = distance(v.begin(), it);
    //   ll ub = *upper_bound(v.begin(),v.end(),k) + 1;
    ll ans = 0;

    // cout << "cnt is " << lb << endl;
    ans += lb;
    ans += (cnt - 1);
    // cout << ans << endl;
    if (maxi != t)
    {
        // cout << "here\n";
        ans += 1;
    }
    ll sum = n - ans;
    // cout << sum << endl;
    if (sum <= k)
    {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
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