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

bool cust(vector<ll> & a , vector<ll> & b){
    return a.size()>b.size();
}

void solve(){
   //your code starts from here
   ll n;
   cin>>n;
   vector<ll> u(n);
   vector<ll> s(n);
   for (ll i = 0; i < n; i++)
   {
    cin>>u[i];
    u[i]--;//0 based indexing
   }
   for (ll i = 0; i < n; i++)
   {
    cin>>s[i];
   }
   //making the bucket thing
   vector<vector<ll>> p(n);
   for (ll i = 0; i < n; i++)
   {
    ll ui = u[i];
    ll si = s[i];
    p[ui].push_back(si);
   }
   //sorting in decreasing order
   for (ll i = 0; i < n; i++)
   {
    sort(p[i].rbegin(),p[i].rend());
   }
   //making a prefix sum inside the vector
//    vector<ll> ans;
   for (ll i = 0; i < n; i++)
   {
    for (ll j = 1; j < p[i].size(); j++)
    {
        ll sum = p[i][j-1] + p[i][j];
        p[i][j] = sum;
    }
    

   }
//    dbg(p)
   sort(all(p),cust);
   for (ll k = 1; k <=n; k++)
   {
    ll ans = 0;
    for (ll j = 0; j < n; j++)
    {
        ll sum = p[j].size()/k;
        sum = sum*k;
        sum--;
        if(sum>=0){
            ans += p[j][sum];
        }
        else{
            break;//as it will be zero from this point so drop basically pruned the space
        }
    }
    cout<<ans<<" ";
    
   }
   cout<<endl;
   
   
   
   
   


   

   
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
