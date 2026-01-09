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

bool a = false;//0,1
bool b = false;//1,1



void solve(){
   //your code starts from here
   ll n;
   cin>>n;
   vector<vector<ll>> v(2,vector<ll>(n));
   for (ll i = 0; i < 2; i++)
   {
    for (ll j = 0; j < n; j++)
    {
        cin>>v[i][j];
    }
    
   }
   vector<ll> pre(n);
   pre[0] = min(v[0][0],v[1][0]);
   for (ll i = 1; i < n; i++)
   {
    ll mini = min(v[0][i],v[1][i]);
    ll maxi = max(v[0][i],v[1][i]);
    if(pre[i-1]>maxi){
         pre[i] = 1e18;
         continue;
    }
    if(pre[i-1]<=mini){
        pre[i] = mini;
    }
    else{
        pre[i] = maxi;
    }
   }
//    dbg(pre)
   vector<ll> suff(n);
   suff[n-1] = max(v[0][n-1],v[1][n-1]);
   for (int i = n - 2; i >= 0; i--)
   {
    ll mini = min(v[0][i],v[1][i]);
    ll maxi = max(v[0][i],v[1][i]);
    if(mini> suff[i+1]){
        suff[i] = -1;
        continue;
    }
    if(maxi<=suff[i+1]){
        suff[i] = maxi;
    }
    else{
        suff[i] = mini;
    }
   }
   bool flag= (suff[0] == max(v[0][0],v[1][0])) || (pre[n-1] == min(v[0][n-1],v[1][n-1]));
//    dbg(suff)
   for (ll i = 1; i < n-1; i++)
   {
    ll mini = min(v[0][i],v[1][i]);
    ll maxi = max(v[0][i],v[1][i]);
    if(mini>=pre[i-1] && maxi<=suff[i+1]){
        flag = true;
    }
   }
   if(flag){
    cout<<"Yes\n";
   }
   else{
    cout<<"No\n";
   }
   
   
   


   
}

ll get(ll i, ll j, bool flip, vector<vector<ll>>& v) {
    if (!flip) return v[i][j];
    return v[1 - i][j];
}


bool fun(vector<vector<ll>> &v, ll i, ll j, ll flip,vector<vector<vector<ll>>> &dp) {

    // base cases
    if (i == 0 && j == 0) return true;
    if (i < 0 || j < 0) return false;
    if (j == 0 && i == 1) return false;
    if(dp[i][j][flip]!=-1){
        return dp[i][j][flip];
    }

    bool ok = false;

    // ===== FROM LEFT (same row, previous column) =====
    if (j > 0) {
        for (bool prevFlip : {0, 1}) {
            if (get(i, j - 1, prevFlip, v) <= get(i, j, flip, v)) {
                if (fun(v, i, j - 1, prevFlip,dp)) {
                    ok = true;
                    break;
                }
            }
        }
    }

    // ===== FROM UP (only if bottom row) =====
    if (!ok && i == 1) {
        if (get(0, j, flip, v) <= get(1, j, flip, v)) {
            if (fun(v, 0, j, flip,dp)) {
                ok = true;
            }
        }
    }

    dp[i][j][flip] = ok;
    return ok;
}

void solve2(){
    ll n;
   cin>>n;
   vector<vector<ll>> v(2,vector<ll>(n));
   for (ll i = 0; i < 2; i++)
   {
    for (ll j = 0; j < n; j++)
    {
        cin>>v[i][j];
    }
    
   }
   vector<vector<vector<ll>>> dp1(2,vector<vector<ll>>(n,vector<ll>(2,-1)));
//    vector<vector<vector<ll>>> dp2(2,vector<vector<ll>>(n,vector<ll>(2,-1)));
   bool ans = fun(v,1,n-1,0,dp1) | fun(v,1,n-1,1,dp1);
   if(ans){
    cout<<"Yes\n";
   }
   else{
    cout<<"No\n";
   }

}


int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    ll T; 
    cin >> T; 
    while (T--) { 
        solve2(); 
    } 
    return 0; 
}
