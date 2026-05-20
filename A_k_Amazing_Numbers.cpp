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
   ll n;
   cin>>n;
   vector<ll> v(n+1);
   set<ll> st;
   for (ll i = 1; i <=n; i++)
   {
    cin>>v[i];
    st.insert(v[i]);
   }
   
   vector<ll> idx(n+1,-1);
   vector<ll> maxval(n+1);
   for (ll i = 1; i <=n; i++)
   {
    ll val = v[i];
    ll sum = abs(idx[val] - i+1);
    maxval[val] = max(maxval[val],sum);
    idx[val] = i-1;
   }
   
   for (ll i = 0; i < n; i++)
   {
    ll val = v[i+1];
    ll sum = abs(n - idx[val]);
     maxval[val] = max(maxval[val],sum);
   }
   dbg(idx)
   dbg(maxval)
   vector<pair<ll,ll>> p;
   for (ll i = 0; i < n; i++)
   {
    ll val = maxval[i+1];
    p.push_back({i+1,val});
   }
   sort(all(p));
   dbg(p)
   vector<ll> ans(n+1,-1);
   for(auto val:p){
    if(ans[val.second]==-1){

        ans[val.second] = val.first;
    }
    
   }
   if(st.size()==1){
    ans[1] = v[1];
   }
   ll val = 1e9;
   bool start = false;
   for (ll i = 1; i <=n; i++)
   {
    if(ans[i]!=-1){
        start = true;
        val = min(ans[i],val);
        ans[i] = val;
    }
    else{
        if(start){

            ans[i] = val;
        }
    }
   }
   
   for (ll i = 1; i <=n; i++)
   {
    cout<<ans[i]<<" ";
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
