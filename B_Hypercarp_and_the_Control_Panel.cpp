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
   vector<pair<ll,ll>> p;//cnt,num
   int cnt = 1;
   for (ll i = 1; i < n; i++)
   {
    if(v[i]==v[i-1]){
        cnt++;
    }
    else{
        p.push_back({cnt,v[i-1]});
        cnt= 1;
    }
   }
   p.push_back({cnt,v[n-1]});
//    dbg(p)
   ll ans = p.size();
   //check for +2
   
  
   for (ll i = 1; i < p.size(); i++)
   {
    if(p[i].first>=2 && p[i-1].first>=2){
        cout<<ans+2<<endl;
        return;
    }
   }
   if(p.size()==1){
    cout<<ans<<endl;
    return;
   }
   //check for +1
//    vector<pair<ll,ll>> t = p;
//    if(p.size()==2){
//     if((p[0].first>=2 && p[1].first==1) || (p[0].first==1 && p[1].first>=1)){
//         ans++;
//     }
//     cout<<ans<<endl;
//     return;
//    }
   for (ll i = 0; i <=p.size()-2; i++)
   {
    if(i==p.size()-2 && p[i].first>=2 && p[i+1].first==1){
        
        cout<<ans+1<<endl;
        return;
    }
    else if(p[i].first>=2 && p[i+1].first==1 && p[i+2].second!=p[i].second){
        cout<<ans+1<<endl;
        return;
    }
   }

   
   reverse(all(p));
   for (ll i = 0; i <=p.size()-2; i++)
   {
    if(i==p.size()-2 && p[i].first>=2 && p[i+1].first==1){
        
        cout<<ans+1<<endl;
        return;
    }
    else if(p[i].first>=2 && p[i+1].first==1 && p[i+2].second!=p[i].second){
        cout<<ans+1<<endl;
        return;
    }
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
