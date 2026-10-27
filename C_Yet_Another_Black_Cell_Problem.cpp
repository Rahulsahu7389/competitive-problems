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

bool check(ll mid ,vector<ll> &v,ll x){
    vector<ll> t;
    ll n = v.size();
    
    // FIX 1: Handle n=1 edge case to prevent out of bounds crash
    if (n == 1) {
        t.push_back(0);
    } 
    else {
        for (ll i = 0; i < n ; i++) {
            if(i==0){
                if(v[1] - v[0] > mid)
                    t.push_back(i);
            } 
            else if(i == n-1){
                if(v[n-1] - v[n-2] > mid)
                    t.push_back(i);
            }
            else if(v[i+1]-v[i] > mid && v[i] - v[i-1] > mid){
                t.push_back(i);
            }
        }
    }
    
    ll need = 0;
    ll m = t.size();
    for (ll i = 0; i < m; i++) {
        // FIX 2: Compare the actual values of the isolated elements, not their indices!
        if(i+1 < m && v[t[i+1]] - v[t[i]] <= 2 * mid){
            i++; // One new element placed between them satisfies both
        }
        need++;
    }
    return need <= x;
}



void solve(){
   //your code starts from here
   ll n,x;
   cin>>n>>x;
   vector<ll> v(n);
   for (ll  i = 0; i < n ; i++)
   {
    cin>>v[i];
   }
   
   ll low = 1;
   ll high = 2e9;
   ll ans = 0;
   while(low<=high){
    ll mid = (low+high)/2;
    ll t = check(mid,v,x);
    // dbg(mid,t)
    if(t){
        // dbg(mid)
        ans = mid;
        high = mid-1;
    }
    else{
        low = mid+1;
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
    while (T--) { 
        solve(); 
    } 
    return 0; 
}
