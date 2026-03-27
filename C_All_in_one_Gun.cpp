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
bool DEBUG_MODE = false;  // toggle before submission

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
   ll n , h , k;
   cin>>n>>h>>k;
   vector<ll> v(n);
//    vector<pair<ll,ll>> p;
   ll total = 0;
   for (ll i = 0; i < n; i++)
   {
    cin>>v[i];
    total += v[i];
    
   }
   
   ll mins = 0;
   if(total < h){
    ll sum = (h/total);
    if(h%total == 0){
        mins += sum*n + (sum -1)*k;
        cout<<mins<<endl;
        return;
    }
    else{
        mins += sum*n + sum*k;
    }
    h -= sum*total;
   }

   
   vector<ll> pref(n + 1, 0);
    vector<ll> suf_max(n + 1, 0);

    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + v[i];
    }

    suf_max[n - 1] = v[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suf_max[i] = max(suf_max[i + 1], v[i]);
    }

    dbg(pref, suf_max)
    ll minin = 2e18;
    ll ans = -1;

    for (ll m = 1; m <=n; m++)
    {
        minin = min(v[m-1],minin);
        ll dmgnoswap = pref[m];//dmg without swap

        ll maxdmg = dmgnoswap;
        if(m<n){//if not used all bullet
            maxdmg = max(dmgnoswap , dmgnoswap - minin + suf_max[m]);
        }
        if(maxdmg >= h){
            mins += m;
            break;
        }


    }
    cout<<mins<<endl;
    
    
    
   


  

   
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
