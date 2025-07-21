#include <bits/stdc++.h>
using namespace std;

#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORLL(a, c) for (long long(a) = 0; (a) < (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(a) a.begin(), a.end()
#define F first
#define S second
#define pb push_back
#define pob pop_back
ll MOD = 1e9 + 7;

template <typename T>
T mod(T a)
{
    if (a < 0)
        return -a;
    return a;
}

template <typename T>
T power(T x, T n)
{
    T pro = 1;
    while (n != 0)
    {
        if (n % 2 == 1)
        {
            pro *= x;
        }
        x *= x;
        n /= 2;
    }
    return pro;
}

void solve()
{
    // your code starts from here
    ll n;
    cin >> n;
    vector<pair<ll,ll>> v;
    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        v.pb({a,i+1});
    }
    sort(v.rbegin(), v.rend());
    vector<pair<ll,ll>> left;
    // vector<ll> right;
    ll ans = 0;
    ll r = 1;
    ll idx = 1;

    for (ll i = 0; i < n; i += 2)
    {
        ans += 2 * v[i].first * r;
        left.pb({v[i].second,idx});
        idx++;
        r++;
    }
    // left.pb({0,0});
    idx = -1;
    r = 1;
    if (n >= 2)
    {

        for (ll i = 1; i < n; i += 2)
        {
            ans += 2 * v[i].first * r;
            left.pb({v[i].second,idx});
            idx--;
            r++;
        }
    }
    sort(all(left));
    cout<<ans<<endl;
    cout<<0<<" ";
    for (auto &&i : left)
    {
        cout<<(i.second)<<" ";
    }
    cout<<endl;
    
    
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