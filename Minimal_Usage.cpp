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
bool isSubsetSum(vector<ll>& arr, ll sum,ll total) {
    // code here
    int n = arr.size();
    
    vector<vector<bool>> dp(n,vector<bool>(sum+1,false));
    
    for(int i =0;i<n;i++ ){
        dp[i][0] = true;
    }
    
    
    for(ll val = 0;val<=sum;val++){
        if(val == arr[0]){
            dp[0][val] = true;
        }
    }
    
    for(ll i =1;i<n;i++){
        for(ll val=1;val<=sum;val++){
            bool nottake = dp[i-1][val];
            bool take =false;
            if(val>=arr[i]){
                take = dp[i-1][val-arr[i]];
            }
            dp[i][val] = (take | nottake);
            
        }
    }
    return (dp[n-1][sum]);
}



ll minSum(ll kp, ll m) {
    if (kp == 0) return 0;
    if (m <= kp) {
        ll tot = (kp + 1) * (kp + 2)/2;
        return tot - m;
    } else {
        return kp * (kp + 1)/2;
    }
}

ll maxSum(ll kp, ll n, ll m) {
    if (kp == 0) return 0;
    ll st = n - kp + 1;
    if (m >= st && m <= n) {
        ll tot = (n * (n + 1)) / 2 - ((st - 2) * (st - 1))/2;
        return tot - m;
    } else {
        ll tot = (n * (n + 1)) / 2 - ((st - 1) * st)/2;
        return tot;
    }
}

void solve() {
    ll n,k,s, m;
    cin>>n>>k>>s>>m;
    ll ans = -1;

    for (ll c = 0; c <= k; c++) {
        ll kp = k - c;
        if (kp > n - 1) continue;
        
        ll sp = s -(c*m);
        if (sp < 0) continue;

        ll mn = minSum(kp,m);
        ll mx = maxSum(kp, n,m);

        if (sp>= mn && sp <= mx) {
            ans = c;
            break;
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
