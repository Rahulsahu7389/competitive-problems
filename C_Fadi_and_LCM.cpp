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

ll gcd(ll a, ll b)
{
    if(a==0){
        return b;

    }
    return gcd(b%a,a);
}

void solve()
{
    // your code starts from here
    ll x;
    cin >> x;
    vector<ll> v;
    ll n = x;
    ll ans = 1e15;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ll g;
            g = gcd(i , n/i);
            if(g==1){
                ans = min(ans,max(i,n/i));
            }
        }
    }
    cout<<ans<<" "<<n/ans<<endl;
    
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