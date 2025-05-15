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

bool isOdd(ll n)
{
    if (n % 2 != 0)
    {
        return true;
    }
    return false;
}

void solve()
{
    // your code starts from here
    string s;
    cin >> s;
    ll n = s.length();
    vector<ll> v(26, 0);
    for (ll i = 0; i < n; i++)
    {
        v[s[i] - 'A']++;
    }
    ll noofOdd = count_if(v.begin(), v.end(), isOdd);
    if (noofOdd > 1)
    {
        cout << "NO SOLUTION\n"
             << endl;
        return;
    }
    // cout << "entered\n";
    if(n%2==0){
    //     //even length
        string t1 = "";
        string t2 ;
        for (ll i = 0; i < v.size(); i++)
        {
            ll x = v[i];
            x /=2;
            while((x)>0){
                t1 += (char)('A' + i);
                x--;
            }
        }
        t2 = t1; //for reversing the second part
        reverse(t2.begin(),t2.end());
        cout<<(t1 + t2)<<endl;

    }
    else{
        // for odd 
        ll idx;
        
        string t1 = "";
        string t2 ;
        for (ll i = 0; i < v.size(); i++)
        {
            ll x;
            if(v[i]%2!=0){
                idx = i;
                x = (v[i]-1)/2;
            }
            else{
                x = v[i]/2;
            }
            while((x)>0){
                t1 += (char)('A' + i);
                x--;
            }
        }
        t2 = t1;
        reverse(t2.begin(),t2.end());
        t1 += + (char)('A' + idx);

        cout<<(t1 + t2)<<endl;
    }
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