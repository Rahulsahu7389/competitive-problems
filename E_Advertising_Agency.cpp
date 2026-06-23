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
const int MOD = 1e9 + 7;

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


ll power(ll x,ll n){
  ll pro = 1;
  while(n!=0){
    if(n%2==1) pro = (pro*x)%MOD;
    x = (x*x)%MOD;
    n /= 2;
  }
  return pro%MOD;
}
ll inverse(ll a){
    return power(a,MOD-2);
}


ll multiplicationMethod(ll n,ll r){
    if(n-r<r) r = n-r;
    ll num = 1;
    ll den = 1;
    for (ll i = 0; i < r; i++)
    {
        num = (num*(n-i))%MOD;
        den = (den*(i+1))%MOD;
    }
    ll inv = inverse(den);
    return (num*inv)%MOD;
    
}

void solve(){
   //your code starts from here
   ll n,k;
   cin>>n>>k;
   vector<ll> v(n);
   for (ll i = 0; i < n; i++)
   {
    cin>>v[i];
   }
   sort(v.rbegin(),v.rend());
   int j = k;
   ll maxsum = 0;
   for (ll i = 0; i < n && j>0; i++)
   {
    maxsum += v[i];
   }
   ll ele = v[k-1];
   j = 0;
   ll totalfreq = 0;
   ll tillkfreq = 0;
   for (ll i = 0; i < n; i++)
   {
    if(v[i]==ele){
        if(i<k){
            tillkfreq++;
        }
        totalfreq++;
    }
   }

   ll ans = multiplicationMethod(totalfreq,tillkfreq);
   cout<<ans<<endl;

   
   
   
   
   
   
   
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
