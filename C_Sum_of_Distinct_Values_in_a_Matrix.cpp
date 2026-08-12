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

ll finds(ll n,ll m ,ll x,ll y, vector<ll> &a ,vector<ll>&b){
    ll p1 = 0;
    ll p2 = 0,both = 0;
    ll ans = 0;
    while((p1<x || p2<y) && (p1 + p2 -both<n+m)){//both counted twice
        if(p1==x || (p1-both)>=n){
            //when we cannot take from a
            if(p2==y || (p2-both)>=m) break;//cannot take from b also
            ans += b[p2];
            p2++;
        }
        else if(p2==y || (p2-both)>=m){
            //when we cannot take from b
            if(p1==x || (p1-both)>=n) break;//cannot take from a also
            ans += a[p1];
            p1++;
        }
        else{
            if(a[p1]==b[p2]){
                both++;
                ans += a[p1];
                p1++;
                p2++;
            }
            else{
                if(a[p1]>b[p2]){
                    ans += a[p1];
                    p1++;
                }
                else{
                    ans += b[p2];
                    p2++;
                }
            }
        }
    }
    return ans;
}

void solve(){
   //your code starts from here
   ll n,m,x,y;
   cin>>n>>m>>x>>y;
   vector<ll> a(x),b(y);
   for (ll i = 0; i < x; i++)
   {
    cin>>a[i];
   }
   for (ll i = 0; i < y; i++)
   {
    cin>>b[i];
   }
   sort(a.rbegin(),a.rend());
   sort(b.rbegin(),b.rend());
   ll ans = max(finds(n-1,m,x,y,a,b),finds(n,m-1,x,y,a,b));
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
