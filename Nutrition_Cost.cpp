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
  ll n, c;
  cin >> n >> c;
  vector<ll> a(n);
  vector<pair<ll, ll>> b;
  //   vector<ll> ans(n+1,0);
  for (ll i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  for (ll i = 0; i < n; i++)
  {
    ll t;
    cin >> t;
    b.pb({t, a[i]});
  }
  sort(b.begin(), b.end());
  ll ans = 0;
  ll amt = 1;
  ll value = 0;
  set<ll> s;
  for (ll i = 0; i < n; i++)
  {
    ll sum = (c*amt - (value+b[i].first));
    if(s.count(b[i].second)==0){
      s.insert(b[i].second);
      if(sum>=0){

        amt++;
        value += b[i].first;
        ans = max(sum,ans);
      }
    }
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