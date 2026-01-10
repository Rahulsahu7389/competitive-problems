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
   ll n,k;
   cin>>n>>k;
   vector<ll> v(n);
   ll maxi = -1;
   

   for (ll i = 0; i < n; i++)
   {
    cin>>v[i];
    maxi = max(maxi,v[i]);
   }
   set<ll> s;
   for (ll i = 0; i <=maxi+1; i++)
   {
    s.insert(i);
   }
//    dbg(s)
   map<ll,ll> m;
   ll l = 0;
   ll r = 0;
   for (ll i = 0; i < k; i++)
   {
    ll val = v[i];
    


   }
//    dbg(m,s)
   ll ans = -1;
   while(r<n){
    ll val = v[r];
    if(r<k){
        if(m.find(val) == m.end()){
            m[val]++;
            s.erase(val);
        }
        else{
            m[val]++;
        }
        if(r == k-1){
            ans = max(ans,(*s.begin()));
        }
    }
    else{
        ll t = v[l];
        if(m[t]==1){
            s.insert(t);
            m.erase(t);
        }
        else{
            m[l]--;
        }
        l++;
        if(m.find(val) == m.end()){
            m[val]++;
            s.erase(val);
        }
        ans = max(ans,(*s.begin()));
    }
    // dbg(ans,r,s)
    r++;
}
ans = max(ans,(*s.begin()));
// dbg(ans,r,s)
   cout<<max(ans-1,1LL)<<endl;

   
   
   
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
