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
   ll n ,q;
   cin>>n>>q;
   vector<ll> v(n);
   for (ll i = 0; i < n; i++)
   {
    cin>>v[i];
   }
   vector<pair<ll,ll>> que;
   vector<ll> contri(n+1);
   for (ll i = 0; i < q; i++)
   {
    ll a,b;
    cin>>a>>b;
    a--;b--;//0 based
    que.push_back({a,b});
    contri[a] += 1;
    contri[b+1] -= 1; 
   }
   sort(v.rbegin(),v.rend());
   //populate
   for (ll i = 1; i <=n; i++)
   {
    contri[i] += contri[i-1];
   }

   dbg(contri)
   vector<pair<ll,ll>> p;
   for (ll i = 0; i < n; i++)
   {
    p.pb({contri[i],i});
   }
   sort(p.rbegin(),p.rend());
   dbg(p)
   //put max element onto that
   vector<ll> temp(n);
   ll idx = 0;//for v
   for(int i = 0;i<n;i++){
    auto val = p[i];
    temp[val.second] = v[idx++];
   }
   dbg(temp)
   vector<ll> prefix(n+1);
   for (ll i = 1; i <=n; i++)
   {
    prefix[i] = prefix[i-1] + temp[i-1];
   }
   dbg(prefix)
   ll ans = 0;
   for(auto t:que){
    ll a = t.first + 1;//1 based
    ll b = t.second + 1;//1 based
    dbg(a,b)
    ans += (prefix[b] - prefix[a-1]);
    dbg((prefix[b] - prefix[a-1]))

   }
   cout<<ans<<endl;
   
   


   

   
   
   

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
