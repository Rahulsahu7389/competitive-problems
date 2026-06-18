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

void ngeleft(vector<ll>& v, vector<ll>&ngel){
    stack<ll> st;
    ll n = v.size();
    for (ll i = 0; i < n; i++)
    {
        ll val = v[i];
        while(!st.empty() && v[st.top()]<=val){
            st.pop();
        }
        if(st.empty()){
            ngel[i] = -1;
        }
        else{
            ngel[i] = st.top();
        }
        st.push(i);
    }
    
    
}
void ngeright(vector<ll>& v, vector<ll>&ngel){
    stack<ll> st;
    ll n = v.size();
    for (ll i= n -1;i>=0;i--)
    {
        ll val = v[i];
        while(!st.empty() && v[st.top()]<=val){
            st.pop();
        }
        if(st.empty()){
            ngel[i] = -1;
        }
        else{
            ngel[i] = st.top();
        }
        st.push(i);
    }
    
    
}

int dp[200001];
ll dfsdp(ll u,vector<ll>&lc, vector<ll>&rc, vector<ll>&h){
    if(u == -1){
        //invalid so return 0
        return 0;//cant go any new range
    }
    if(dp[u]!=-1){
        return dp[u];
    }
    ll lft = dfsdp(lc[u],lc,rc,h);
    ll right = dfsdp(rc[u],lc,rc,h);
    ll ans = 1;
    if(lft!=0){//left se contribution aaya hai
        
        //go to that left child
        ans = max(ans,1 + lft);
        
    }
    if(right!=0){
        
        //go to that left child
        ans = max(ans,1 + right);
        
    }
    return dp[u]= ans;
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
   vector<ll> lc(n),rc(n);
   ngeleft(v,lc);
   ngeright(v,rc);
   vector<pair<ll,ll>> p(n);
   for (ll i = 0; i < n; i++)
   {
    p[i] = {v[i],i};
   }
   sort(p.rbegin(),p.rend());
   ll ans = 0;
   memset(dp,-1,sizeof(dp));
   for (ll i = 0; i < n; i++)
   {
    ans = max(ans, dfsdp(p[i].second,lc,rc,v));
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
