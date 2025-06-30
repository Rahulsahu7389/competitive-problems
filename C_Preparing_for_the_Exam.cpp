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
    ll n, m, k;
    cin >> n >> m >> k;
    
    vector<ll> a(m);
    vector<ll> q(k);
    for (ll i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    // bool flag = true;
    for (ll i = 0; i < k; i++)
    {
        cin >> q[i];
    }

    string ans = "";
    if (k < n - 1)
    {
        for (ll i = 0; i < m; i++)
        {
            ans += "0";
        }
        cout << ans << endl;
        return;
    }
    if (k == n)
    {
        for (ll i = 0; i < m; i++)
        {
            ans += "1";
        }
        cout<<ans<<endl;
        return;
    }
    ll missing  = 1;
    // bool flag = false;
    for (ll i = 1; i <=k; i++)
    {
        if(missing == q[i-1]){
            missing++;
        }
    }
    // cout<<missing<<endl;
    for (ll i = 0; i <a.size(); i++)
    {
        if(missing==a[i]){
            ans += "1";
        }
        else{
            ans += "0";
        }
    }
    cout<<ans<<endl;
    
    

    
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