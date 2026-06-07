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
vector<ll> mp;
ll fun(ll i, ll j,vector<vector<ll>>& v , ll val ){
    ll ans = 0;
    ll m = v[0].size();
    ll n = v.size();
    vector<ll>temp(m);
    for (ll k = 0; k <m; k++)
    {
        temp[k] = v[j][k] - v[i-1][k];
    }

    
    mp[0] = 1;
    ll sum = 0;
    for (ll i = 0; i < m; i++)
    {
        sum += temp[i];
        ll diff = sum -val;
        if(diff>=0 && mp[(diff)]){
            ans += mp[diff];
        }
        mp[sum]++;

    }
    dbg(i,j,ans)
    sum = 0;
    mp[0] = 0; // Resets the base case
    for (ll k = 0; k < m; k++) {
        ll val_at_k = v[j][k] - v[i - 1][k];
        sum += val_at_k;
        mp[sum] = 0; // Forces the index back to exactly 0
    }
    return ans;
    
    
}

void solve(){
   //your code starts from here
   ll n,m,k;
   cin>>n>>m>>k;
    vector<vector<ll>> v;
    string s;
    cin>>s;
    vector<ll>temp(m);
    v.push_back(temp);
    for (ll i = 0; i < s.length(); i++)
    {
        temp[i]=(s[i]-'0');
    }
    v.push_back(temp);
    vector<ll> curr(m);
   for (ll i = 1; i < n; i++)
   {
    string st;
    cin>>st;
    for (ll i = 0; i < st.length(); i++)
    {
        ll sum = temp[i] + (st[i]-'0');
        curr[i] = sum;
    }
    v.push_back(curr);
    temp = curr;
    
   }
   dbg(v)
   mp.assign(n*m+1,0);
   ll ans = 0;
   for (ll i = 1; i <=n; i++)
   {
    for (ll j = i; j <=n; j++)
    {
        ans += fun(i,j,v,k);
    }
    
   }
   cout<<ans<<endl;
   
   
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
