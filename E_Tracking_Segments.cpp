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

bool valid(ll mid , vector<pair<ll,ll>> &range , vector<ll> &que, ll n){

    vector<ll> temp(n+1);
    for (ll i = 0; i < mid; i++)
    {
        temp[que[i]] = 1;
    }
    //make it prefix 
    for (ll i = 1; i <=n; i++)
    {
        temp[i] = temp[i-1] + temp[i];
    }
    //now check if any segment valid
    for(auto val:range){
        ll a = val.first;
        ll b = val.second;
        ll sum = temp[b] - temp[a-1];
        ll zero = (b - a + 1) - sum;
        if(sum>zero){
            return true;
        }
    }
    return false;
    
    
}

void solve(){
   //your code starts from here
   ll n,m;
   cin>>n>>m;
   vector<pair<ll,ll>> range(m);
   for (ll i = 0; i < m; i++)
   {
    cin>>range[i].first>>range[i].second;
   }
   ll q;
   cin>>q;
   vector<ll> que(q);
   for (ll i = 0; i <  q; i++)
   {
    cin>>que[i];
   }
   ll st = 0;
   ll end = q;
   ll ans = 1e15;
   while(st<=end){
    ll mid = (st + end)/2;
    // dbg(mid)
    if(valid(mid,range,que,n)){
        //look for smaller 
        ans = mid;
        end = mid-1;
    }
    else{
        st = mid + 1;
    }
   }
   if(ans == 1e15){
    cout<<-1<<endl;
    return;
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
