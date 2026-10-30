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

ll n,q;
vector<ll> values;
unordered_map<ll,vector<ll>> adj;
vector<int> tin,tout,euler;
ll timer =0;
void dfs(int node ,int par){//building the euler tour
    tin[node] =timer;
    euler[timer] =values[node];
    timer++;
    for(auto val:adj[node]){
        if(val == par) continue;
        dfs(val,node);
    }
    tout[node] = timer;
    euler[timer] = values[node];
    timer++;
}

//segment tree part
vector<ll> seg;

void build(ll node ,ll l ,ll r){
    if(l==r){
        seg[node] = euler[l];
        return;
    }
    ll mid = (l+r)/2;
    build(2*node+1,l,mid);
    build(2*node+2,mid+1,r);
    seg[node] = (seg[2*node+1]+seg[2*node+2]);
}

void pointupdate(ll node , ll l ,ll r ,ll idx,ll val){
    if(l==r){
        seg[node] = val;
        return;
    }
    ll mid = (l+r)/2;
    if(l<=idx && idx<=mid){
        pointupdate(2*node+1,l,mid,idx,val);
    }
    else{
        pointupdate(2*node+2,mid+1,r,idx,val);

    }
    seg[node] = (seg[2*node+1]+seg[2*node+2]);
}

ll query(ll node , ll l ,ll r ,ll low ,ll high){
    if(l>high || r<low) return 0;
    if(low<=l && r<=high){
        return seg[node];
    }
    ll mid = (l+r)/2;
    return query(2*node+1,l,mid,low,high)+query(2*node+2,mid+1,r,low,high);
}
void solve(){
   //your code starts from here
   cin>>n>>q;
   ll m = n+1;
   values.assign(m,0);
   tin.assign(m,0);
   tout.assign(m,0);
   euler.assign(2*n,0);
   timer = 0;
   for (ll  i = 1; i <=n ; i++)
   {
    cin>>values[i];
   }
   for (ll  i = 0; i < n -1 ; i++)
   {
    
    ll a,b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
   }
   dfs(1,-1);
   seg.assign(8*n,0);
   build(0,0,2*n-1);
//    dbg(euler)
   for (ll  i = 0; i < q ; i++)
   {
    ll x;
    cin>>x;
    // dbg(i,x)
    if(x==1){
        ll idx,val;
        cin>>idx>>val;
        euler[tin[idx]] =val;
        euler[tout[idx]] =val;
        // dbg(idx,tin[idx])
        // dbg(seg)
        pointupdate(0,0,2*n-1,tin[idx],val);
        pointupdate(0,0,2*n-1,tout[idx],val);
        // dbg(seg)
        
    }
    else{
        ll b;
        cin>>b;
        ll l = tin[b];
        ll r = tout[b];
        ll sum = query(0,0,2*n-1,l,r)/2LL;
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
