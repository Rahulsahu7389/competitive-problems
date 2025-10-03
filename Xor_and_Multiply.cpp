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
   ll n ,a,b;
   cin>>n>>a>>b;
   ll p = 0;
   ll q = 0;
   ll x = 0;
   for (int i = n-1 ; i >= 0; i--)
   {
    if((a&(1<<i))&&(b&(1<<i))) continue;//both bit set so keep x[i] = 0 so that xor krke 1 mile
    if(!(a&(1<<i))&&!(b&(1<<i))) {
        x |= (1<<i);
        continue;
    }
    if((a&(1<<i))){//a[i] = 1 and b[i] = 0 
        // if first decisive try to make q max
        // x |= (1<<i);//as x[i] = 1 so p[i] = 0 and q[i] = 1 so q>p
        // now for below indices
        for (int j = i - 1; j >= 0; j--)
        {
            if((a&(1<<j))&&(b&(1<<j))) continue;
            if(!(a&(1<<j))&&!(b&(1<<j))) {

                x |= (1<<j);
                continue;
            }
            //prime focus to make p larger as at first decisive q>p so
            //if a[j] = 0 and b[j] = 1 so  do  as x[j] = 1 so p[j] = 1
            if((a&(1<<j))) x|= (1<<j);//this is for a[j] = 1 and b[j] = ;
            //if b[j] = 0 and a[j] = 1 x[j] = 0 so dont do anythinh
        }
        


    }
    else{//a[i] = 0 and b[i] = 1 
        // if first decisive try to make q max
        // x |= (1<<i);//as x[i] = 0 so p[i] = 0 and q[i] = 1 so q>p
        // now for below indices
        for (int j = i - 1; j >= 0; j--)
        {
            if((a&(1<<j))&&(b&(1<<j))) continue;
            if(!(a&(1<<j))&&!(b&(1<<j))) {

                x |= (1<<j);
                continue;
            }
            //prime focus to make p larger as at first decisive q>p so
            //if a[j] = 0 and b[j] = 1 so  do  as x[j] = 1 so p[j] = 1
            if((b&(1<<j))) x|= (1<<j);//this is for a[j] = 0 and b[j] = 1;
            
        }
        


    }
    break;
   }
   cout<<x<<endl;
   
   
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
