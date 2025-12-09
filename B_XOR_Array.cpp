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
   ll n,x,y;
   cin>>n>>x>>y;
   vector<ll> ans;
   ll even = 4;
   ll odd = 1;
   ll idx = 1;
   ll val = 0;
   while(idx<y){
    ll chance;
    if(idx%2!=0){
        chance = odd;
        odd += 2;
    }
    else{
        chance = even;
        even += 2;
    }
    if(idx >= x){
        val = (val^chance);
    }
    dbg(val,idx)
    ans.push_back(chance);
    idx++;
   }

   ll term = val;
   dbg(term)
   ans.push_back(term);
   if(term%2==0){
    idx = 1;
   }
   else{
    idx = 2;
   }
   ll sz = ans.size();
   while(sz!=n){
    ll chance;
    if(idx%2!=0){
        chance = odd;
        if(chance == term){
            odd += 2;
            chance = odd;
        }
        odd += 2;
    }
    else{
        chance = even;
        if(chance == term){
            even += 2;
            chance = even;
        }
        even += 2;
    }
    
    ans.push_back(chance);
    sz++;
    idx++;
   }

   for(auto t:ans){
    cout<<t<<" ";
   }
   cout<<endl;
   



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
