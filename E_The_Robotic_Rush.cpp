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

void solve(){
    ll n,m,k;
    cin>>n>>m>>k;

    vector<ll>a(n),b(m);
    for(ll i=0;i<n;i++) cin>>a[i];
    for(ll i=0;i<m;i++) cin>>b[i];

    string st;
    cin>>st;

    sort(all(a));
    sort(all(b));

    vector<pair<ll,ll>> p;

    ll i=0;

    while(i<n && a[i]<b[0]){
        p.pb({LLONG_MIN, b[0]-a[i]});
        i++;
    }

    if(i<n){
        for(ll j=0;j<m-1;j++){
            if(i==n) break;
            if(a[i]>b[j] && a[i]<b[j+1]){
                p.pb({-(a[i]-b[j]), b[j+1]-a[i]});
                i++;
                j--;
            }
        }
    }

    while(i<n){
        p.pb({-(a[i]-b[m-1]), LLONG_MAX});
        i++;
    }

    map<ll,ll> left,right;
    for(ll j=0;j<p.size();j++){
        left[p[j].first]++;
        right[p[j].second]++;
    }

    ll val=0;
    ll ans=n;

    for(ll j=0;j<k;j++){
        if(st[j]=='L') val--;
        else val++;

        auto itl=left.begin();
        while(itl!=left.end() && itl->first>=val){
            ans-=itl->second;
            itl=left.erase(itl);
        }

        auto itr=right.begin();
        while(itr!=right.end() && itr->first<=val){
            ans-=itr->second;
            itr=right.erase(itr);
        }

        if(ans<0) cout<<0<<" ";
        else cout<<ans<<" ";
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
