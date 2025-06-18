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
    ll a,b;
    cin>>a>>b;
    if(__gcd(a,b)>1){
        cout<<0<<endl;
        return;
    }
    if(__gcd(a+1,b)>1){
        cout<<1<<endl;
        return;
    }
    if(__gcd(a,b+1)>1){
        cout<<1<<endl;
        return;
    }
    if(__gcd(a+2,b)>1){
        cout<<2<<endl;
        return;
    }
    if(__gcd(a,b+2)>1){
        cout<<2<<endl;
        return;
    }
    if(__gcd(a+1,b+1)>1){
        cout<<2<<endl;
        return;
    }
    
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