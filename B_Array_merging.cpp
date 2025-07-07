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
    vector<ll> a(n);
    vector<ll> b(n);
    unordered_map<ll,pair<ll,ll>> m;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    ll maxi1 = -5;
    ll maxi2 = -5;
    ll cnt1 = 1;
    ll cnt2 = 1;
    for (ll i = 1; i < n; i++)
    {
        if(a[i]==a[i-1]){
            cnt1++;
        }
        else{
            // maxi1 = max(cnt1,maxi1);
            m[a[i-1]] = {(max(cnt1,m[a[i-1]].first)),0};
            cnt1 = 1;
        }
        
    }
    m[a[n-1]] ={(max(cnt1,m[a[n-1]].first)),0};
    for (ll i = 1; i < n; i++)
    {
        if(b[i]==b[i-1]){
            cnt2++;
        }
        else{
            // maxi2 = max(cnt2,maxi2);
            m[b[i-1]].second = max(cnt2,m[b[i-1]].second);
            cnt2 = 1;
        }
        
    }
    m[b[n-1]].second = max(cnt2,m[b[n-1]].second);
    // for(auto val:m){
    //     cout<<val.first<<" "<<val.second.first<< " "<<val.second.second<<endl;
    // }
    
    ll ans = -4;
    for(auto val:m){
        ans = max(ans,(val.second.first + val.second.second));
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