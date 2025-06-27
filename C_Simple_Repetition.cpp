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
    string x;
    cin >> x;
    ll n;
    cin >> n;
    string s = "";
    for (ll i = 0; i < n; i++)
    {
        s += x;
    }
    if(n==1 && x == "1"){
        cout << "NO" << endl;
        return;
    }
    if(n==2 && x ==  "1"){
        cout<<"YES"<<endl;
        return;
    }
    if (n >=2 && x != "1")
    {
        cout << "NO" << endl;
        return;
    }
    ll t = stoll(s);
    if (t == 1)
    {
        cout << "NO" << endl;
        return;
    }

    for (ll i = 2; i * i <= t; i++)
    {
        if (t % i == 0)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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