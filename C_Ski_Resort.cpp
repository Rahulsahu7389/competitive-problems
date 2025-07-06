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
    ll n, k, q;
    cin >> n >> k >> q;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<ll> d;
    ll i = 0;
    ll j;
    
    while ((v[i] > q) && i<n)
    {
        // cout << "here\n";
        i++;
    }
    j  = i;
    ll diff = 0;
    while((i<n && j<n)){
        if(v[j]>q && diff>=k-1){
            d.pb(diff);
            diff = 0;
            i = j+1;
            j = i;
            continue;
        }
        else if(v[j]>q && diff<k-1){
            diff = 0;
            i = j+1;
            j = i;
            continue;
        }
        else{
            diff++;
            j++;
        }
    }
    if(diff>=k-1){
        d.pb(diff);
    }
    ll ans = 0;
    for (auto val : d)
    {
        // ll sum = ((val+1)*val)/2;
        ll val2 = val - (k-1);
        ll sum2 = ((val2+1)*val2)/2;
        ans += sum2;
        
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