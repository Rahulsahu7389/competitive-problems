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
    string s;
    cin >> s;
    // ll i = 0;
    ll ans = INT_MIN;
    vector<ll> suffix(n);
    unordered_set<char> s1;
    unordered_set<char> s2;
    for (ll i = n-1; i >=0; i--)
    {
        s1.insert(s[i]);
        suffix[i] = s1.size();
    }
    // for(auto val:suffix){
    //     cout<<val<<endl;
    // }
    for (ll i = 0; i < n-1; i++)
    {
        s2.insert(s[i]);
        ll t = (s2.size() + suffix[i+1]);
        ans = max(ans , t);
    }
    

    

    cout << ans << endl;
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