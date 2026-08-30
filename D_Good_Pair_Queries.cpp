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

bool isok(ll x,ll y, ll z){
    ll t = min(x,y);
    ll k = x - t + y - t;
    return z>=k;
}

void solve(){
   //your code starts from here
   ll n,q;
   cin>>n>>q;
   string a,b;
   cin>>a;
   cin>>b;
   vector<vector<ll>> v(n+1,vector<ll>(3,0));// type 1 ,type 2 , type3 
   for (ll  i = 0; i < n; i++)
   {
    if(a[i]==b[i]) v[i+1][2]++;
    else if(a[i]=='0' && b[i]=='1') v[i+1][0]++;
    else v[i+1][1]++;
   }
   for (ll i = 1; i <=n; i++)
   {
    v[i][0] += v[i-1][0];
    v[i][1] += v[i-1][1];
    v[i][2] += v[i-1][2];
   }
   
   for (ll i = 0; i < q; i++)
   {
    ll l,r;
    cin>>l>>r;
    ll x = v[r][0] - v[l-1][0];
    ll y = v[r][1] - v[l-1][1];
    ll z = v[r][2] - v[l-1][2];
    if(isok(x,y,z)){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
   }
   

   
}

int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    ll T; 
    cin >> T; 
    while (T--) { 
        solve(); 
    } 
    return 0; 
}

