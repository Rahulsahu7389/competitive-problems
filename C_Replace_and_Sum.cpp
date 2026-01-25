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
   ll n,q;
   cin>>n>>q;
   vector<ll> a(n);
   vector<ll> b(n);
   for (ll i = 0; i < n; i++)
   {
    cin>>a[i];
   }
   for (ll i = 0; i < n; i++)
   {
    cin>>b[i];
   }
   for (ll i = 0; i < n; i++)
   {
    if(a[i]<b[i]){
        a[i] = b[i];
    }
   }
//    dbg(a)
   vector<ll> suff(n);
   suff[n-1] = a[n-1];
   ll val = a[n-1];
   for (int i = n - 1; i >= 0; i--)
   {
    if(a[i]>val){
        val =a[i];
        suff[i] = val;
    }
    else{
        suff[i] = val;
    }
   }
//    dbg(suff)

   vector<ll> pre(n);
   pre[0] = suff[0];
   for (ll i = 1; i < n; i++)
   {
    pre[i] = suff[i] + pre[i-1];
   }
//    dbg(pre)
   

   for (ll i = 0; i < q; i++)
   {
    ll l,r;
    cin>>l>>r;
    if(l == 1){
        ll sum = pre[r-1];
        cout<<sum<<" ";
    }
    else{
        ll sum = pre[r-1] - pre[l-2];
        cout<<sum<<" ";
    }
   }
   cout<<endl;
   
   
   
   
   
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
