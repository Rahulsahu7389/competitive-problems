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

bool fun(ll mid ,vector<vector<ll>> &v ,vector<pair<ll,ll>> &idx){
    ll x = mid;
    for (ll i = 0; i < v.size(); i++)
    {
        ll sz = idx[i].second;
        ll need = idx[i].first;
        if(x<need){
            return false;
        }
        x += sz;
        
        
    }
    return true;
    
}

void solve(){
   //your code starts from here
   ll n;
   cin>>n;
   vector<vector<ll>> v(n);
//    vector<pair<ll,ll>> idx(n);
   ll total = 0;
   for (ll i = 0; i < n; i++)
   {
    ll k;
    cin>>k;
    // ll maxi = -1;
    for (ll j = 0; j < k; j++)
    {
        ll a;
        cin>>a;
        v[i].pb(a);
        total += a;
        // maxi = max(maxi,a);
    }
    // idx[i] = {maxi,i};
    
   }
   vector<pair<ll,ll>> caves;
    for (int i = 0; i < n; i++) {
        ll need = 0;
        for (int j = 0; j < v[i].size(); j++) {
            need = max(need, v[i][j] - j);
        }
        caves.push_back({need + 1, v[i].size()});
    }
   sort(all(caves));
//    dbg(v)
   ll ans = total+1;
   ll st = 1;
   ll end = total;
   while(st<=end){
    ll mid = st + (end - st)/2;
    bool val = fun(mid,v,caves);
    if(val){
        ans = min(mid,ans);
        end = mid - 1;
    }
    else{
        st = mid + 1;
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


int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
    vector<long long> a(n, LLONG_MAX);
    a[0] = 0;
 
    map<int, long long> st;
    for (auto r : restrictions) {
        if (!st.count(r[0])) st[r[0]] = r[1];
        else st[r[0]] = min(st[r[0]], (long long)r[1]);
    }

    for (auto p : st) {
        a[p.first] = min(a[p.first], p.second);
    }

    for (int i = 1; i < n; i++) {
        a[i] = min(a[i], a[i-1] + diff[i-1]);
    }

    for (int i = n - 2; i >= 0; i--) {
        a[i] = min(a[i], a[i+1] + diff[i]);
    }

    long long ans = 0;
    for (auto val : a) {
        ans = max(ans, val);
    }

    return ans;
}
