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

bool check(ll hc, ll dc, ll hm, ll dm)
{
  ll moBc = (hm - 1 + dc) / dc;
  ll cBmo = (hc - 1 + dm) / dm;
  // cout<<"character took : "<<moBc<<endl;
  // cout<<"monster took : "<<cBmo<<endl;
  if (moBc <= cBmo)
  {
    // character wins
    return true;
  }
  else if (moBc > cBmo)
  {
    // monster wins
    return false;
  }
  // else{
  //     //character attacked first
  //     return true;
  // }
}

void solve()
{
  // your code starts from here
  ll hc, dc, hm, dm, k, w, a;
  cin >> hc >> dc;
  cin >> hm >> dm;
  cin >> k >> w >> a;
  // without aid
  if (check(hc, dc, hm, dm))
  {
    cout << "YES" << endl;
    return;
  }
  // with aid 
  for (ll i = 0; i <= k; i++)
  {
    if(check((hc+i*a),(dc + (k-i)*w),hm,dm)){
      cout<<"YES"<<endl;
      return;
    }
  }
  cout<<"NO"<<endl;
  
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