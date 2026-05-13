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

void update(int i , int add,vector<int> &fen, int N){
    while(i<N){
        fen[i] += add;
        i += (i &(-i));
    }
}

int sum(int i,vector<int> &fen){
    int s =0;
    while(i>0){
        s += fen[i];
        i = i - (i &(-i));
    }
    return s;
}

void solve(){
   //your code starts from here
   ll n;
   cin>>n;
   vector<pair<ll,ll>> p(n);
   for (ll i = 0; i < n; i++)
   {
    cin>>p[i].first>>p[i].second;
   }
   sort(all(p));
   vector<pair<ll,ll>> temp(n);//b[i],index
   for (ll i = 0; i < n; i++)
   {
    temp[i] = {p[i].second , i};
   }
   sort(all(temp));
   
   ll val = 1;
   vector<ll> compress(n);
   for (ll i = 0; i < n; i++)
   {
    compress[temp[i].second] = val++;
   }
   
   ll ans = 0;
   vector<int> fen(n+1,0);
   for(auto val:compress){
    ll maxi = sum(n,fen);
    ll till = sum(val,fen);
    // dbg(maxi,till)
    ans += (maxi - till);
    update(val,1,fen,n+1);
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
