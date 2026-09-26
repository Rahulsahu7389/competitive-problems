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
   ll q;
   cin>>q;
   string s;
   cin>>s;
   string t;
   cin>>t;
   ll n = s.length();
   ll m = t.length();
   vector<pair<ll,ll>> que(q);
   for (ll i = 0; i < q ; i++)
   {
    cin>>que[i].first>>que[i].second;
    que[i].first--;
    que[i].second--;
   }
  vector<pair<ll,ll>> match;
   for (ll i = 0; i <= n - m; i++)
   {
    if (s.substr(i, m) == t) {
        match.push_back({i, i+m-1});
    }
   }

   auto getval = [&](ll a,ll b){
        if (match.empty()) return false; 
        
        ll l = 0;
        ll r = match.size()-1;
        ll fin = -1;
        while(l<=r){
            ll mid = (l+r)/2;
            if(match[mid].second<=b){
                fin = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        if(fin==-1) return false;
        ll L = match[fin].first;
        ll R = match[fin].second;
        if(a<=L && R<=b) return true;
        return false;
   };
   for(auto val:que){
    ll a = val.first;
    ll b = val.second;
    bool p = getval(a,b);
    if(p){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }
   }
   
   

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
