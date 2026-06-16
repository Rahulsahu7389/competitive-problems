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

ll dp[1002][1002];
ll fun(ll i ,ll j ,vector<ll> & a , vector<ll> &b, ll n ,ll m){//her i andj is one based
    if(i ==0 || j==0){
        return 0;//cannot compare it with other
    }
    if(dp[i][j] !=-1){
        return dp[i][j];
    }
    if(a[i-1]==b[j-1]){
        return dp[i][j]=1 + fun(i-1,j-1,a,b,n,m);
    }

    //if not matching then have these many choices
    ll left = fun(i-1,j,a,b,n,m);
    ll right = fun(i,j-1,a,b,n,m);
    return dp[i][j]=max({left ,right});
}

void solve(){
   //your code starts from here
   ll n,m;
   cin>>n>>m;
   vector<ll> a(n),b(m);
   for (ll i = 0; i < n; i++)
   {
    cin>>a[i];
   }
   for (ll i = 0; i < n; i++)
   {
    cin>>b[i];
   }
   
   memset(dp,0,sizeof(dp));
//    ll ans = fun(n,m,a,b,n,m);
   for (ll i = 1; i <=n; i++)
   {
    for (ll j = 1; j <=m; j++)
    {
        
        if(a[i-1]==b[j-1]){
            dp[i][j]= 1 + fun(i-1,j-1,a,b,n,m);
        }
        else{

            
            //if not matching then have these many choices
            ll left = fun(i-1,j,a,b,n,m);
            ll right = fun(i,j-1,a,b,n,m);
            dp[i][j] = max(right,left);
        }
    }
    
   }
   vector<ll> common;

//    for (ll i = 0; i < n; i++)
//    {
//     for (ll j = 0; j < m; j++)
//     {
//         cout<<dp[i][j]<<" ";
//     }
//     cout<<endl;
    
//    }
   ll i = n;
   ll j = m;
   while(i>=1 && j>=1){
    if(a[i-1] == b[j-1]){
        common.push_back(a[i-1]);
        i--;
        j--;
    }
    else{
        ll left = dp[i][j-1];
        ll up = dp[i-1][j];
        if(left==dp[i][j]){
            j--;
        }
        else{
            i--;
        }
    }
   }
   reverse(all(common));
   cout<<common.size()<<endl;
   for(auto val:common){
    cout<<val<<" ";
   }
   cout<<endl;
   
   
   

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
