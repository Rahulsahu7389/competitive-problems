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

bool cust(vector<ll> & a, vector<ll>& b){
    if(a[0]==b[0]){
        return a[1]<b[1];
    }
    return a[0]<b[0];
}

void solve(){
   //your code starts from here
   ll n;
   cin>>n;
   vector<vector<ll>> p;//l,r ,i
   for (ll i = 0; i < n; i++)
   {
    ll a,b;
    cin>>a>>b;
    p.pb({a,b,i});
   }
   if(n ==1){
    cout<<-1<<" "<<-1<<endl;
    return;
   }
   sort(all(p));
   ll l = p[0][0];
   ll r = p[0][1];
   ll x = -2;
   ll y = -2;
   ll curr = p[0][2];
   for (ll i = 1; i < n; i++)
   {
    ll a = p[i][0];
    ll b = p[i][1];
    //prev lies inside
    // dbg(a,b)
    if(l<=a && b<=r){
        x = p[i][2];
        y = curr;
        break;
    }
    else if(l>=a && r<=b){
        x = curr;
        y = p[i][2];
        break;
    }
    else{
        l =a ;
        r = b;
        curr = p[i][2];
    }
    // dbg(i,curr)

   }
//    dbg(x,y)
   cout<<x+1<<" "<<y+1<<endl;
   
   
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
