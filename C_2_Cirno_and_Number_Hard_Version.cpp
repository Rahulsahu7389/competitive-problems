
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
   ll a,n;
   cin>>a>>n;
   vector<ll> v(n);
   for (ll i = 0; i < n; i++)
   {
    cin>>v[i];
   }
   
   string s = to_string(a);
   ll l = s.length();
   //for smaller length use v[1]
   ll ans = 2e18;
   if(l>1){
       for(auto x:v){
        ll val = 0;

    
        for (ll i = 0; i < l-1; i++)
        {
            val = val*10 + x;
        }
        ans = min(ans,abs(val - a));
        dbg(val)
    
    }
   }
   //for greater length
    if(n>1 || (n ==1 && v[0]!=0)){

   
        ll val = 0;
        if(v[0]==0){
            val = v[1];
        }
        else val = v[0];
        for (ll i = 1; i < l+1; i++)
        {
            val = val*10 + v[0];
        }
        dbg(val)
        ans = min(ans,abs(val - a));
    }
   
   
   
   //go digit by digit
   ll curr = 0;
   bool made = true;
   for (ll i = 0; i < l; i++)
   {
    ll dig = s[i]-'0';
    for(auto d:v){
        ll temp = curr*10 + d;
        if(d>dig){
            //first point of diff is greater so put smaller no ahead
            for (ll j = i+1; j < l; j++)//we have already chosen till i digit
            {
                temp = temp*10 + v[0];
            }
            
            
        }
        else if(d<dig){
            for (ll j = i+1; j < l; j++)//we have already chosen till i digit
            {
                temp = temp*10 + v[n-1];
            }
        }
        ans = min(ans,abs(a - temp));
    }
    bool found = true;//true means we could not found
    for(auto x:v){
        if(x == dig){
            found = false;
        }
    }
    if(found){//means we could not find dig
        made = false;
        break;
    }
    curr = curr*10 + dig;
   }
   if(made){
    cout<<0<<endl;
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

