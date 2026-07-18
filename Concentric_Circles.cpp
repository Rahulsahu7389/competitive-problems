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
   ll x1,y1,x2,y2,x3,y3,x4,y4;
   cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
   ll knum = (x2*x2 - x1*x1 + y2*y2 - y1*y1)*(x4 - x3) - (x4*x4 - x3*x3 + y4*y4 - y3*y3)*(x2 - x1);
   ll hnum = (x2*x2 - x1*x1 + y2*y2 - y1*y1)*(y4 - y3) - (x4*x4 - x3*x3 + y4*y4 - y3*y3)*(y2 - y1);
   ll kden = 2*((y2-y1)*(x4-x3) - (y4 - y3)*(x2-x1));
   ll hden = 2*((x2-x1)*(y4-y3) - (x4 - x3)*(y2-y1));
   if(kden ==0 || hden==0){
    cout<<"No\n";
    return;
   }
   ll h = hnum/hden;
   ll k = knum/kden;
   ll a = (h-x1)*(h-x1) + (k-y1)*(k-y1);
   ll b = (h-x2)*(h-x2) + (k-y2)*(k-y2);
   ll d = (h-x3)*(h-x3) + (k-y3)*(k-y3);
   ll e = (h-x4)*(h-x4) + (k-y4)*(k-y4);
   if((a==b) && (d == e)){
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
        solve(); 
    } 
    return 0; 
}
