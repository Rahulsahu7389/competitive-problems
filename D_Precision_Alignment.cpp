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
    ll s1 = a-b,s2 = a-c,s3 = b-c;
    if(s1>0) return {0,1};
    else if(s2>0) return {0,2};
    else if(s3>0) return {0,1};
    else if(s1==0 && s2==0 && s3==0) return {-2,-2};
    return {-1,-1};
}

ll getsum(ll i ,vector<vector<ll>> &v){
    return v[i][0]+v[i][1]+v[i][2];
}

bool check(long long mid, const vector<vector<ll>>& v, ll k) {
    long long req = 0;
    int n = v.size();
    
    for (int i = 0; i < n; i++) {
        ll a = v[i][0];
        ll b = v[i][1];
        ll c = v[i][2];
        ll sum = a+b+c;
        // If this lab already meets the required minimum sum, skip
        if (sum >= mid) continue;

        long long diff = mid - sum;

        // If any strict greater-than relation exists, we can increase the sum directly
        if (a > b || a > c || b > c) {
            req += diff;
        } else {
            // Otherwise, a <= b <= c. We are locked.
            if (a == b && b == c) {
                return false; // Impossible to break out if all are equal
            }
            
            // To break out, we either decrease b until it is strictly less than a,
            // or decrease c until it is strictly less than b. We take the cheaper one.
            long long extra_ops = 2LL * min(b - a + 1, c - b + 1);
            req += diff + extra_ops;
        }

        if (req > k) return false;
    }
    
    return true; 
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

   ll l = 1e18;
   for (ll i = 0; i < n; i++)
   {
    ll sum = getsum(i,v);
    l = min(l,sum);
   }
   ll r = l+k;
   ll ans = l;
//    dbg(l,r)
   while(l<=r){
    ll mid = (r+l)/2;
    bool ok = check(mid,v,k);
    // dbg(mid,ok)
    if(ok){
        ans = mid;
        l = mid+1;
    }
    else{
        r = mid-1;
    }
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
