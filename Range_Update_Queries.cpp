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
vector<ll>v;
vector<ll> seg;
vector<ll> lazy;

void build(ll id,ll l ,ll r){
    if(l == r){
        seg[id] = v[l];
        return;
    }
    ll mid = (l + r)/2;
    build(2*id+1,l,mid);
    build(2*id+2,mid+1,r);
    seg[id] = seg[2*id+1]+seg[2*id+2];
}
void checklazy(ll id ,ll l ,ll r){
    if(lazy[id]!=0){
        seg[id] += (r - l+1)*lazy[id];
        if(l!=r){
            lazy[2*id+1] += lazy[id];
            lazy[2*id+2] += lazy[id];
        }
        lazy[id] = 0;
    }
}
void rangesum(ll id, ll l ,ll r ,ll a, ll b ,ll u){
    checklazy(id ,l, r);
    if(l>b || r < a) return ;
    if(a<=l && r<=b){
        seg[id] += (r - l +1)*u;//since it says increase the value so +
        if(l!=r){
           lazy[2*id+1] += u;
           lazy[2*id+2] += u;
        }
        return;
    }

    ll mid = (l+r)/2;
    rangesum(2*id+1,l,mid,a,b,u);
    rangesum(2*id+2,mid+1,r,a,b,u);
    seg[id] = seg[2*id+1]+seg[2*id+2];//just assign the value


}

ll query(ll id , ll low ,ll high,ll l ,ll r){
    checklazy(id,low,high);
    if(low>r || high<l) return 0;
    if(l<=low && high<=r){
        return seg[id];
    }

    ll mid = (low + high)/2;
    ll left = query(2*id+1,low,mid,l,r);
    ll right = query(2*id+2,mid+1,high,l,r);
    return left+right;
}

void solve(){
   //your code starts from here
   ll n,q;
   cin>>n>>q;
   v.assign(n+1,0);
   for (ll i = 0; i < n; i++)
   {
    cin>>v[i];
   }
   seg.assign(4*n+2,0);
   lazy.assign(4*n+2,0);
   build(0,0,n-1);

   for (ll i = 0; i < q; i++)
   {
    ll a;
    cin>>a;
    if(a == 2){
        ll b;
        cin>>b;
        b--;
        ll val = query(0,0,n-1,b,b);
        cout<<val<<endl;
    }
    else{
        ll b,c,d;
        cin>>b>>c>>d;
        b--;c--;
        rangesum(0,0,n-1,b,c,d);
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
