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
  ll n;
  cin >> n;
  // got tle for root x approach
  // ll ans = 2;
  // if(n==1){
  //   cout<<1<<endl;
  //   return;
  // }
  // for (ll i = 2; i*i <= n; i++)
  // {
  //   if(n%i==0){
  //       if(i == n/i){
  //           ans++;
  //       }
  //       else{
  //           ans += 2;
  //       }
  //   }
  // }
  // cout<<ans<<endl;

  // using sieves
  // cout << v[n] << endl;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // v[1] = n;
  ll T;
  cin >> T;
  vector<ll> v(1000001, 0);
  for (ll i = 1; i <= 1000000; i++)
  {
    for (ll j = i; j <= 1000000; j += i)
    {
      v[j]++;
    }
  }
  while (T--)
  {
    ll n;
    cin>>n;
    cout<<v[n]<<endl;
  }
  return 0;
}