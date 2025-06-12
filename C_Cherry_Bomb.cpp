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
    ll curr = -1;
    bool flag = true;
    ll cntnegone = 0;
    vector<ll> a(n);
    vector<ll> b(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> b[i];
        // cout<<"curr "<<curr<<endl;
        if (b[i] == -1)
        {
            cntnegone++;
        }
        if (b[i] != -1 && curr == -1)
        {
            curr = b[i] + a[i];
            continue;
        }
        if (b[i] != -1 && curr != (a[i] + b[i]))
        {
            flag = false;
        }
    }
   
    if (flag == false)
    {
        cout << 0 << endl;
        return;
    }
    ll mini = *min_element(a.begin(), a.end());
    ll maxy = *max_element(a.begin(), a.end());
    if (flag == true && cntnegone != n)
    {
        if (curr > k || curr<maxy)
        {

            cout << 0 << endl;
            return;
        }
        else if (curr <= k && curr>=maxy )
        {
            cout << 1 << endl;
            return;
        }
        
    }
    
    cout << ((mini + k) - maxy + 1) << endl;
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