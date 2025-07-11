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
    ll target = v[j-1];
    sort(v.begin(),v.end());
    ll idx = distance(v.begin(),find(v.begin(),v.end(),target));
    ll ans = 0;
    if(target == v[n-1]){
        ans += n - idx -1;
    }
    else{
        ans += n - idx - 2;
    }
    ans += idx;
    ll remain = n - ans;
    if(remain <=k){
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";
    

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