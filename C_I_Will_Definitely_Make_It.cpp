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
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    vector<ll> diff;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ll val = v[k-1];
    sort(all(v));
    diff.pb(v[0]);
    for (ll i = 1; i < n; i++)
    {
        if(v[i]==v[i-1]){
            i++;
            continue;
        }
        
        diff.pb(v[i]);
        
    }
    // ll var
    ll idx = distance(diff.begin(),find(all(diff) , val));
    // cout<<idx<<endl;
    ll level = 1;
    for (ll i = idx+1; i < diff.size(); i++)
    {
        /* code */
        ll d = diff[i] - diff[i-1];
        if(level + d - 1 > diff[i-1]){
            cout<<"NO\n";
            return;
        }
        else if((level + d)>diff[i]){
            cout<<"NO\n";
            return;
        }
        else{
            level += d;
        }
        
    }
    cout<<"YES\n";
    
    
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