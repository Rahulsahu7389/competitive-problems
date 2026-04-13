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
bool DEBUG_MODE = false;  // toggle before submission

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
   vector<ll> cal(n);
   for (ll i = 0; i < n; i++)
   {
    cin>>cal[i];
   }
   if(n == 1){
    cout<<"YES\n";
    return;
   }
   ll val = cal[0];
   ll valneg = -1*val;
   ll idx = n/2;
   vector<ll> v;
   for (ll i = 0; i < n; i++)
   {
    if(i ==0) continue;
    v.pb(cal[i]);
   }
   sort(all(v));
   vector<ll> pos(n-1,0);
   vector<ll> neg(n-1,0);
   dbg(v)
   //pos loop
   ll id = 0;
   ll taken = v.size()-1;
   while(id<idx && id<n && taken>=0){
    ll t = v[taken];
    if(t<val){
        id++;
        pos[taken]= 1;
    }
    else if(-1*t<val){
        id++;
        pos[taken]= 1;
    }
    taken--;
    
   }
   dbg(pos)
   bool ans1 = true;
   for (ll i = 0; i < n; i++)
   {
    if(pos[i]==0){
        if(v[i]>val && v[i]*-1>val){
            ans1 = false;
            break;
        }
    }
   }
   if(ans1 && id == idx){
    cout<<"YES\n";
    return;
   }
   val = valneg;
   id = 0;
   taken = v.size()-1;
   while(id<idx && id<n && taken>=0){
    ll t = v[taken];
    if(t<val){
        id++;
        neg[taken]= 1;
    }
    else if(-1*t<val){
        id++;
        neg[taken]= 1;
    }
    taken--;
    
   }
   dbg(neg)
   ans1 = true;
   for (ll i = 0; i < n; i++)
   {
    if(neg[i]==0){
        if(v[i]<val && v[i]*-1<val){
            ans1 = false;
            break;
        }
    }
   }
   if(ans1 && id == idx){
    cout<<"YES\n";
    return;
   }
   cout<<"NO\n";
   
   
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
