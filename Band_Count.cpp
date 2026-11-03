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


ll low(ll x ,vector<pair<ll,ll>> &a){
    auto it= upper_bound(a.begin(),a.end(),make_pair(x,(ll)1e9));
    ll val = 0;
    if(it==a.begin()) return val;
    it--;
    val = it->second;
    return val;
}
// ll high(ll x ,vector<pair<ll,ll>> &a){
//     auto it= upper_bound(a.begin(),a.end(),make_pair(x,(ll)1e9));
//     ll val = 0;
//     if(it==a.begin()) return val;
//     it--;
//     val = it->second;
//     return val;
// }

void solve(){
   //your code starts from here
   ll n,m,x,q;
   cin>>n>>m>>x>>q;
   map<ll,ll> mpx,mpy;
   for (ll  i = 0; i < x ; i++)
   {
    ll a,b;
    cin>>a>>b;
    mpx[a]++;
    mpy[b]++;
   }
   vector<pair<ll,ll>> px(all(mpx)),py(all(mpy));
//    dbg(mpx)
//    dbg(px)
   ll szx = px.size();
   ll szy = py.size();
   for (ll  i = 1; i <szx; i++)
   {
    px[i].second += px[i-1].second;
   }
   for (ll  i = 1; i <szy; i++)
   {
    py[i].second += py[i-1].second;
   }

//    dbg(px);
//    dbg(py);
//    for(auto val:px){
//     cout<<val.first<<" "<<val.second;
//    }
//    cout<<endl;
//    for(auto val:py){
//     cout<<val.first<<" "<<val.second;
//    }
//    cout<<endl;
   for (ll  i = 0; i < q ; i++)
   {
    ll f;
    cin>>f;
    if(f==1){
        //rows
        ll a,b;
        cin>>a>>b;
        ll sum = low(b,px) - low(a-1,px);
        cout<<sum<<endl;
    }
    else{
        ll a,b;
        cin>>a>>b;
        ll sum = low(b,py) - low(a-1,py);
        cout<<sum<<endl;
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
