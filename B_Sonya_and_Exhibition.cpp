#include <bits/stdc++.h>
using namespace std;

#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++) 
#define FORLL(a, c) for (long long(a) = 0; (a) < (c); (a)++) 
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--) 
typedef long long int ll; 
typedef vector<int> vi; 
typedef pair<int, int> pi; 
#define all(a) a.begin(),a.end()
#define F first 
#define S second 
#define pb push_back 
#define pob pop_back 
ll MOD = 1e9 + 7;

// ======== DEBUG SYSTEM ========
bool DEBUG_MODE = true;  // toggle before submission

template<typename T> void _print(const T &x) { cerr << x; }
template<typename T1, typename T2> void _print(const pair<T1, T2> &p) { cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}"; }
template<typename T> void _print(const vector<T> &v) { cerr << "["; for (auto &i : v) { _print(i); cerr << " "; } cerr << "]"; }
template<typename T> void _print(const set<T> &s) { cerr << "{"; for (auto &i : s) { _print(i); cerr << " "; } cerr << "}"; }
template<typename T> void _print(const multiset<T> &s) { cerr << "{"; for (auto &i : s) { _print(i); cerr << " "; } cerr << "}"; }
template<typename K, typename V> void _print(const map<K, V> &m) { cerr << "{"; for (auto &p : m) { _print(p.first); cerr << "->"; _print(p.second); cerr << " "; } cerr << "}"; }

// Variadic template for multiple args
void dbg_out() { cerr << "\n"; }
template<typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) { _print(H); if(sizeof...(T)) cerr << " | "; dbg_out(T...); }

#define dbg(...) if(DEBUG_MODE){ cerr << "[" << __LINE__ << "] " << #__VA_ARGS__ << " = "; dbg_out(__VA_ARGS__); }

// ======== UTILITY FUNCTIONS ========
template<typename T>
T mod(T a){ return (a<0)? -a : a; }

template<typename T>
T power(T x,T n){
  T pro = 1;
  while(n!=0){
    if(n%2==1) pro *= x;
    x *= x;
    n /= 2;
  }
  return pro;
}

void solve(){
   //your code starts from here
   ll n, m;
   cin>>n>>m;
   vector<pair<ll,ll>> p(m);
   for (ll i = 0; i < m; i++)
   {
    cin>>p[i].first>>p[i].second;
   }

   vector<pair<ll,ll>> pre1(n+1);//one,zero
   vector<pair<ll,ll>> pre0(n+1);
   for (ll i = 1; i <=n; i++)
   {
    if(i%2==0){
        pre1[i].second = pre1[i-1].second + 1;
        pre1[i].first = pre1[i-1].first;
        pre0[i].first = pre0[i-1].first + 1;
        pre0[i].second = pre0[i-1].second;

    }
    else{
        pre1[i].first = pre1[i-1].first + 1;
        pre1[i].second = pre1[i-1].second;
        pre0[i].second = pre0[i-1].second + 1;
        pre0[i].first = pre0[i-1].first;
    }
   }
   ll val1 = 0;
   for(auto val:p){
    ll f = val.first;
    ll s = val.second;
    ll sum = (pre1[s].first - pre1[f-1].first )*(pre1[s].second- pre1[f-1].second);
    val1 += sum;
   }
   ll val0 = 0;
   for(auto val:p){
    ll f = val.first;
    ll s = val.second;
    ll sum = (pre0[s].first - pre0[f-1].first )*(pre0[s].second- pre0[f-1].second);
    val0 += sum;
   }

   bool isone = true;
   if(val0>val1) isone = false;
   for (ll i = 1; i <=n; i++)
   {
    if(isone){
        cout<<(i%2);
    }
    else{
        cout<<(i+1)%2;
    }
   }
   cout<<endl;
   
   
}

int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    ll T; 
    // cin >> T; 
    // while (T--) { 
        solve(); 
    // } 
    return 0; 
}
