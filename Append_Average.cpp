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

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    ll sum = 0;
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    sort(v.begin(), v.end());
    ll a = v[0], b = v[1];
    ll added = 0;
    ll steps;
    if(k<200){
        steps = k;
    }
    else{
        steps = 200;
    }
    ll t = b;
    for (ll i = 0; i < steps; i++) {
        t = (a + t + 1) / 2;
        added += t;
    }
    if (k > steps) {
        added += (k - steps) * t; 
    }
    cout << sum + added << "\n";
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