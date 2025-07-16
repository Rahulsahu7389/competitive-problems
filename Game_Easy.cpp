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
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    // sort(v.rbegin(), v.rend());
    for (ll k = 1; k <= 2 * n; k++)
    {
        ll sum = 0;
        ll ans = -1;
        
        ll t = k;
        ll x = 0;
        for (ll i = 0; i <= n; i++)
        {
            ll j = 0;
            for (ll w = 0; w <i && t>0 ; w++)
            {
                sum += (v[w]);
                x++;
                t--;
            }
            if (i > 0)
            {

                for (j = 0; j <i; j++)
                {
                    if (t >= 2)
                    {
                        sum += (v[j] + x);
                        x++;
                        t -= 2;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            
            ans = max(ans, sum);
            sum = 0;
            
        }
        cout<<ans<<" ";
        ans = -1;
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