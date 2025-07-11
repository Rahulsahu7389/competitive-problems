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
  ll n;
  cin >> n;
  char c;
  cin >> c;
  string s;
  cin >> s;
  s = s + s;
  ll idxg = s.length();
  ll ans = -1;
  for (int i = 2*n - 1; i >= 0; i--)
  {
    if(s[i] == 'g'){
      // cout<<"it is g at "<<i<<endl;
      idxg = i;
    }
    if(s[i]==c && idxg!=2*n){
      // cout<<"it is c at "<<i<<endl;
      ans = max(ans , abs(idxg - i));
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