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

int binExp(int a, int b, int mod) {
    int res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

//if a<=1e18 , each time a is multiplied and taken mod so take mod prior as it wont affect the answer
//a^b%M = ((a%M)^b)%M
int binExp(int a, int b, int mod) {
    int res = 1;
    a %= mod;//phle hi mod kr diye
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

//now if mod<=1e18 so suppose a*a result in 1e18 but now in next time 1e18*1e9 ->> overflow as mod to iske baad kaam krega
//rather we can do addition of a till a times as a+a<1e18 and mod it but i takes o(n) 
//now to do this in O(LOgn) we use binary multiplication of a*b here we make b into binary
int binMultiply(int a, int b, int mod) {//runs in logn
    int res = 0;
    while (b > 0) {
        if (b & 1) {
            res = (res + a) % mod;
        }
        a = (a + a) % mod;
        b >>= 1;
    }
    return res;
}


ll binExp(ll a, ll b,ll mod) {//log^2(n)
    ll res = 1;
    a %= mod;//phle hi mod kr diye
    while (b > 0) {
        if (b & 1) {
            res = binMultiply(a,res,mod);
        }
        a = binMultiply(a,a,mod);
        b >>= 1;
    }
    return res;
}

void solve(){
   //your code starts from here
   ll n,k;
   cin>>n>>k;
   cout<<(((n*k)/60))<<" "<<((n*k)%60)<<endl;
   
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
