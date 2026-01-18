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

bool valid(ll mid , vector<ll> &v, ll h){
    if(v.size() == 1){
        if(v[0] <=h) return true;
        else return false;
    }
    if(v.size() == 2){
        if(max(v[0] , v[1]) <=h){
            return true;
        }
        else{
            return false;
        }
    }
    sort(v.begin(),v.end());
    ll e ;
    if(mid%2==0){
        e = 0;
    }
    else{
        e = 1;
    }
    bool flag = true;
    for (int i = mid - 1; i >= e; i-=2)
    {
        if(h<0){
            flag = false;
        }
        ll sum = max(v[i], v[i-1]);
        h -= sum;
        
    }
    if(h<0){
            flag = false;
    }
    if(flag==false) return flag;
    if(mid%2!=0){
        if(v[0]>h) return false;
    }
    return true;
}

void solve(){
   //your code starts from here
   ll n,h;
   cin>>n>>h;
   vector<ll> v(n);
   for (ll i = 0; i < n; i++)
   {
    cin>>v[i];
   }
   ll st = 1;
   ll end = n;
   ll ans = -1;
   while(st<=end){
    ll mid = st + (end - st)/2;
    vector<ll> temp(v.begin(),v.begin()+mid);
    // dbg(temp,mid)
    if(valid(mid,temp,h)){
        ans = max(ans,mid);
        st = mid + 1;
    }
    else{
        end = mid - 1;
    }
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
