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

vector<ll> p(30);
// ll compute(ll x){
//     ll p = 1;
//     ll t = 0;
//     while(p*3<=x){
//         p *= 3;
//         t++;
//     }
//     return t;
// }
ll compute(ll x){
    return (p[x+1] + x*p[x-1]);
}



void solve(){
   //your code starts from here
   ll n,k;
   cin>>n>>k;

   ll bit[30];
   for (ll i = 0; i < 30; i++)
   {
    bit[i] = 0;
   }
   
   ll x = n;
   ll ans = 0;
   ll i = 0;
   while(x>0){
    ll rem = x%3;//no of deal to be done for 3^i wala deal
    ans += compute(i)*rem;
    bit[i] = rem;
    i++;
    k -= rem;
    x /= 3;
   }
   dbg(ans)
   if(k<0){
    cout<<-1<<endl;
    return;
   }
   ll reduction = 0;
   for (int i = 30 - 1; i >= 1; i--)
   {
    if(k>1 && bit[i]){

        ll times = min(k/2,bit[i]);
        k -= times*2;
        bit[i] -= times;
        bit[i-1] += 3*times;
        reduction += times*p[i-1];
    }
   }
   cout<<(ans - reduction) <<endl;
   
   
   
   
}

int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
     p[0] = 1;
    for (ll i = 1; i <30; i++)
    {
        p[i] = p[i-1]*3;
    }
    ll T; 
    cin >> T; 
    while (T--) { 
        solve(); 
    } 
    return 0; 
}
