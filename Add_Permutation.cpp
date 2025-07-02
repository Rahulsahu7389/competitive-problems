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
    ll n, k;
    cin >> n >> k;
    
        
        vector<int> p;

        for (int i = n - k + 1; i >= 1; i--)
        {
            p.push_back(i);
        }
        

        for (int i = n - k + 2; i <= n; i++)
        {
            p.push_back(i);
        }
        

        for (int x : p)
        {
            cout << x << " ";
        }
        cout << endl;
    
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