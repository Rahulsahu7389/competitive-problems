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

// ll dp[5003][5003];
// ll fun(int i , int  j , vector<ll> &a , vector<ll> & b , ll n1 ,ll n2){
//     if(i>n1 || j>n2){
//         return 0;
//     }
//     if(dp[i][j]!=-1){
//         return dp[i][j];
//     }
//     if(a[i]==b[j]){
//         return 1 + fun(i+1,j+1,a,b,n1,n2);
//     }
//     //if doesnt match then either of them is skipped
//     return dp[i][j]=max(fun(i+1,j,a,b,n1,n2),fun(i,j+1,a,b,n1,n2));
    
// }

const int m = 10;

void solve(){
   //your code starts from here
   string a,b;
   cin>>a;
   cin>>b;
   ll n1 = a.length();
   ll n2 = b.length();
   vector<ll> pre1(n1+1),pre2(n2+1);
    for (ll i = 1; i <=n1; i++)
    {
        ll val = stol(string(1,a[i-1]));
        pre1[i] += val;
        pre1[i] = (pre1[i] + pre1[i-1])%m;
    }
    for (ll i = 1; i <=n2; i++)
    {
        ll val = stol(string(1,b[i-1]));
        pre2[i] += val;
        pre2[i] = (pre2[i] + pre2[i-1])%m;
    }
    // dbg(pre1,pre2)
    if(pre1.back()!=pre2.back()){
        cout<<-1<<endl;
        return;
    }
    vector<vector<ll>>dp(n1+2,vector<ll>(n2+2));
    ll ans = 0;
    for(int i = n1;i>=1;i--){
        for (int j = n2; j >= 1; j--)
        {
            if(pre1[i]==pre2[j]){
                dp[i][j] = 1 + dp[i+1][j+1];
            }
            else{

                //if doesnt match then either of them is skipped
                dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
            }
        }
        
    }
    cout<<dp[1][1]<<endl;

    

   
   
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
