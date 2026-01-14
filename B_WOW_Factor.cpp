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

ll fun(string& temp ,string &comp,ll i , ll j,vector<vector<ll>> &dp ){
    if(j < 0){
        return 1;
        
    }
    if(i<0){
        return 0 ;
    }
    if(dp[i+1][j+1]!=-1){
        return dp[i+1][j+1];
    }
    ll take = 0;
    if(temp[i] == comp[j]){

        take = fun(temp,comp,i-1,j-1,dp);
    }
    
    ll nottake1 = fun(temp,comp,i-1,j,dp);
    dp[i+1][j+1] = take + nottake1;
    return take + nottake1;
}

void solve(){
   string s;
   cin>>s;
   ll n = s.length();
   string temp = "";
   for (ll i = 1; i < n; i++)
   {
    if(s[i]=='v' && s[i-1] == 'v'){
        temp.pb('w');
    }
    if(s[i] == 'o'){
        temp.pb('o');
    }
   }
//    dbg(temp)
   string comp = "wow";
   int m = temp.size();
    int k = comp.size(); // 3

    vector<vector<long long>> dp(m + 1, vector<long long>(k + 1, 0));

    // Base case: empty comp
    for (int i = 0; i <= m; i++)
        dp[i][0] = 1;

    // Fill DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = dp[i - 1][j];  // not take
            if (temp[i - 1] == comp[j - 1]) {
                dp[i][j] += dp[i - 1][j - 1];  // take
            }
        }
    }

    cout << dp[m][k] << '\n';
   
}

int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    ll T; 
    // cin >> T; 
    // while (T--) { 
        solve(); 
    // } 
    return 0; 
}
