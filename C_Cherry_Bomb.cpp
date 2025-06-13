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
    ll x = -2;
    bool flag = true;
    // ll bwala = -2;
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
        if(b[i] == -1){
            cntnegone++;
        }
        if(b[i]!=-1 && x == -2){
            x = a[i] + b[i];
            continue;
        }
        
        
    }
    //now check if you know bi or you dont
    if(cntnegone!=n){//mil gya hoga x then
        for (ll i = 0; i < n; i++)
        {
            if(((a[i]+b[i])!=x) && b[i]!=-1){//if you know the bi
                cout<<0<<endl;
                return;
            }
            if(((x - a[i] )<0 || (x - a[i])>k) && b[i]==-1){//you dont know bi
                cout<<0<<endl;
                return;
            }
        }
        cout<<1<<endl;
        return;
        
    }
    
    cout<<((*min_element(a.begin(),a.end()) + k) - *max_element(a.begin(),a.end()) + 1)<<endl;

   
    
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