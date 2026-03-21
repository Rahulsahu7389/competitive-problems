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
    ll n;
   cin>>n;
   vector<ll> v(n);
   for (ll i = 0; i < n; i++)
   {
    cin>>v[i];
   }
   vector<ll> pos(n+1);
   for (ll i = 0; i < n; i++)
   {
    pos[v[i]] = i+1;//gives one based indexing of elements
   }

   set<ll> st;
   st.insert(0);//for padding
   st.insert(n+1);
   st.insert(-1);
   st.insert(n+2);
   ll ans = 0;
   for(ll x = n;x>=1;x -= 1){
    auto ind = st.lower_bound(pos[x]);
    ll l = *prev(ind);
    ll l2 = *prev(prev(ind));
    ll r = *ind;
    ll rr = *next(ind);
    if(l>0){
        ans += 1LL*x*(l - l2)*(r - pos[x]);
    }
    if(r<=n){
        ans += x*(rr-r)*(pos[x]-l);
    }
    st.insert(pos[x]);
   }
   cout<<ans<<endl;
   
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
   stack<ll> st1;
   vector<ll> pre(n);
   for (ll i = 0; i < n; i++)
   {
    ll val = v[i];
    if(st1.empty()){
        pre[i] = -1;
        st1.push(i);
        continue;
    }
    if(val < v[st1.top()]){
        pre[i] = st1.top();
        st1.push(i);
        continue;


    }
    while(!st1.empty()){
        if(val < v[st1.top()]) break;
        st1.pop();
    }
    if(!st1.empty()){
        pre[i] = st1.top();
    }
    else{
        pre[i] = -1;
    }
    st1.push(i);
   }

   vector<ll> suff(n);
   stack<ll> st2;

   for(int i = n-1;i>=0;i--)
   {
    ll val = v[i];
    if(st2.empty()){
        suff[i] = -1;
        st2.push(i);
        continue;
    }
    if(val < v[st2.top()]){
        suff[i] = st2.top();
        st2.push(i);
        continue;


    }
    while(!st2.empty()){
        if(val < v[st2.top()]) break;
        st2.pop();
    }
    if(!st2.empty()){
        suff[i] = st2.top();
    }
    else{
        suff[i] = -1;
    }
    st2.push(i);
   }

   dbg(pre,suff)

   //contribution method
   ll ans = 0;
   for (ll i = 0; i < n; i++)
   {
    ll val = v[i];
    ll left = pre[i];
    ll right = suff[i];
    dbg(left,right)
    if(left == -1 && right ==-1){
        dbg(i,"first")
        continue;
    }
    else if(left == -1 && right !=-1){
        dbg(i,"second")
        ll cntr = 1;
        for (ll j = right+1; j < n; j++)
        {
            if(v[j]<val){
                cntr++;
            }
            else{
                break;
            }
        }
        ans += cntr*(i +1)*val;
        
    }
    else if(left !=-1 && right == -1){
        dbg(i,"third")
        ll cntl = 1;
        for (ll j = left -1;j>=0;j--)
        {
            if(v[j]<val){
                cntl++;
            }
            else{
                break;
            }
        }
        ans += cntl*(n-i)*val;
    }
    else{
        dbg(i,"4th")
        ll cntr = 1;
        for (ll j = right+1; j < n; j++)
        {
            if(v[j]<val){
                cntr++;
            }
            else{
                break;
            }
        }
        ll cntl = 1;
        for (ll j = left -1;j>=0;j--)
        {
            if(v[j]<val){
                cntl++;
            }
            else{
                break;
            }
        }
        ans += ((right - i)*cntr + (i - left)*cntl)*v[i];

    }
    dbg(i,ans)
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
