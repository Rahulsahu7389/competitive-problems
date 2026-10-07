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

pair<ll,ll> get(ll a, ll b,ll c){
    ll s1 = b -c,s2 = a-c,s3 = b-c;
    if(s1>0) return {1,2};
    else if(s2>0) return {0,2};
    else if(s3>0) return {0,1};
    return {-1,-1};
}

void solve(){
   //your code starts from here
   ll n,k;
   cin>>n>>k;
   vector<vector<ll>> v(n,vector<ll>(3));
   for (ll i = 0; i < n; i++)
   {
    cin>>v[i][0]>>v[i][1]>>v[i][2];
   }
   if(n==1){
    ll sum = v[0][0] + v[0][1] + v[0][2];
    pair<ll,ll> p = get(v[0][0] , v[0][1] , v[0][2]);
    if(p.first==-1){
        cout<<sum<<endl;
        return;
    }
    else{
        cout<<sum+k<<endl;return;
    }
   }
   priority_queue<pair<ll,ll>,vector<pair<ll,ll>> , greater<pair<ll,ll>>> q;
   for (ll i = 0; i < n; i++)
   {
    ll sum = v[i][0] + v[i][1] + v[i][2];
    q.push({sum,i});
   }

   bool flag = false;

   while(k>0){
    auto tp = q.top();
    q.pop();
    int idx = tp.second;
    ll sum = v[idx][0] + v[idx][1] + v[idx][2];
    pair<ll,ll> p = get(v[idx][0] , v[idx][1] , v[idx][2]);
    if(p.first==-1 || k<=0) break;
    auto stop = q.top();
    ll val = stop.first;
    ll t = llabs(sum - val);
    if(t==0){
        flag = true;
        break;
    }
    ll s = min(t,k);
    k -=s ;
    ll c = 3 - p.first - p.second;
    v[idx][c] += s;
    sum += s;
    q.push({sum,idx});
    // dbg("here")
   }
   
   ll x = (k/n);
   ll rem = k%n;
   //dekho ki sb me kr skte yaa nhi
   bool ok = true;
   for (ll i = 0; i < n; i++)
   {
    auto p = get(v[i][0],v[i][1],v[i][2]);
    if(p.first==-1){
        ok = false;
    }
   }
   if(ok==false){
    cout<<q.top().first<<endl;
    return;
   }
   ll ans = 1e18;
   for (ll i = 0; i < n; i++)
   {
    ll sum = v[i][0]+v[i][1]+v[i][2]+x;
    ans = min(sum,ans);
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
