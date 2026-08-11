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

void solve(ll n,ll m,ll x,ll y,vector<ll>&a ,vector<ll>&b){
   //your code starts from here
   


   ll t = x-1;
   ll z = y-1;
   set<ll> st;
   ll aa = n-1;
   ll bb = m-1;
   ll ans = 0;
   while(aa>0 && t>=0){
    ans += a[t];

    st.insert(a[t--]);
    aa--;

   }
   while(bb>0 && z>=0){
    if(st.count(b[z])==0){
        ans += b[z];
        bb--;
        st.insert(b[z]);
    }
    z--;
   }
//    dbg(ans)


    ll maxi = -1;
    while(t>=0 && st.count(a[t])>0){
        t--;
    }
    if(t>=0){

        maxi = max(maxi,a[t]);
    }
    while(z>=0 && st.count(b[z])>0){
        z--;
    }
    if(z>=0){

        maxi = max(maxi,b[z]);
    }
    if(maxi!=-1){

        ans += maxi;
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
        ll n,m,x,y;
        cin>>n>>m>>x>>y;
        vector<ll> a(x),b(y);
        for (ll i = 0; i < x; i++)
        {
            cin>>a[i];
        }
        for (ll i = 0; i < y; i++)
        {
            cin>>b[i];
        }
        if(x>y){

            solve(m,n,y,x,b,a); 
        }
        else{

            solve(n,m,x,y,a,b); 
        }
    } 
    return 0; 
}
