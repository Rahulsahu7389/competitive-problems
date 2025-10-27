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
   ll n;
   cin>>n;
   vector<ll> v(n);
   for (ll i = 0; i < n; i++)
   {
    cin>>v[i];
   }
   if(n == 1){
    cout<<1<<endl;return;
   }
   vector<ll> s;
   s.pb(v[0]);
   for (ll i = 1; i < n; i++)
   {
    if(v[i]==v[i-1]){
        continue;
    }
    else{
        s.pb(v[i]);
    }
   }
//    dbg(s)
   if(s.size() == 1){
    cout<<1<<endl;
    return;
   }
   if(s.size() == 2){
    cout<<2<<endl;
    return;
   }
   vector<bool> ans1(s.size(),true);
   vector<bool> ans2(s.size(),true);
//    ll prev = 0;
//    ll idx = 1;
//    ll ahead = 2;
   for (ll idx = 1; idx<s.size()-1; idx++)
   {
    if(s[idx]>s[idx-1] && (s[idx]<s[idx+1])){
        ans1[idx] = false; 
    }
   }
   reverse(all(s));

   for (ll idx = 1; idx < s.size()-1; idx++)
   {
    if(s[idx]>s[idx-1] && (s[idx]<s[idx+1])){
        ans2[idx] = false; 
    }
   }
   ll cnt1 = 0;
   ll cnt2 = 0;
//    for (auto &&i : ans1)
//    {
//     cout<<i<<" ";
//    }
//    cout<<endl;
//    for (auto &&i : ans2)
//    {
//     cout<<i<<" ";
//    }
//    cout<<endl;
   
   
   for (ll i = 0; i < ans1.size(); i++)
   {
    if(ans1[i]){
        cnt1++;
    }
    if(ans2[i]){
        cnt2++;
    }
   }
//    dbg(cnt1,cnt2)
   cout<<min(cnt1,cnt2)<<endl;
   

   
   
   
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
