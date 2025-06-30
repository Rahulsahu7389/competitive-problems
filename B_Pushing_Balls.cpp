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
  ll n, m;
  cin >> n >> m;
  ll cnt = 0;
  vector<string> v(n);
  for (ll i = 0; i < n; i++)
  {
    cin >> v[i];
  }

  for (ll i = 1; i < n; i++)
  {
    for (ll j = 1; j < m; j++)
    {
      // cout<<"here\n";
      bool flag1 = false;
      bool flag2 = false;
      if (v[i][j] == '1')
      {

        // if(v[i-1][j]=='1'){
        for (ll k = 0; k <= (i - 1); k++)
        {
          if (v[k][j] == '0')
          {
            flag1 = true;
            break;
          }
        }
        // continue;

        // }
        // if(v[i][j-1]=='1'){
        for (ll k = 0; k <= (j - 1); k++)
        {
          if (v[i][k] == '0')
          {
            flag2 = true;
            break;
          }
        }
        // }
      }
      if(flag1 && flag2){
        cout<<"NO\n";
        return;
      }
    }
  }
  cout << "YES\n";
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