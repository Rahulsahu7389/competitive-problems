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

bool isInteger(float n)
{
  // cout<<(floor(n))<<endl;
  float fractional_part = ceil(n)-(int)n ;
  cout << fractional_part << endl;
  if (fractional_part == 0)
  {
    return true;
  }
  return false;
}
bool isPowerOfTwo(int n)
{
  float sum = (float)(log(n)) / log(2);
  cout << (sum) << endl;
  if (isInteger(sum) && sum >= 0)
  {
    return true;
  }
  return false;
}
bool com(pair<int,int> a , pair<int,int> b){
  return a.second<b.second;
}

void solve()
{
  vector<pair<int,int>> m = {{4,2},{3,2},{5,1},{1,0}};
  vector<int> v = {3,2,1,5,8,0};
  sort(m.begin(),m.end(),com);
  for (auto val : m)
  {
    cout<<val.first<<" "<<val.second<<endl;
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