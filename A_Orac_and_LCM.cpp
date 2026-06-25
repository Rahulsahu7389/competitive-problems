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
template<typename K, typename V> void _print(const unordered_map<K, V> &m) { cerr << "{"; for (auto &p : m) { _print(p.first); cerr << "->"; _print(p.second); cerr << " "; } cerr << "}"; }

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
   ll n;
   cin>>n;
   vector<ll> v(n);
   for (ll i = 0; i < n; i++)
   {
    cin>>v[i];
   }
   unordered_map<ll,vector<ll>> mp;//mini,second mini,cnt
   for (ll i = 0; i < n; i++)
   {
    ll val = v[i];
    unordered_map<ll,ll>fact;
    for (ll j = 2; j*j <=val; j++)
    {
        while(val%j==0){
            val /= j;
            fact[j]++;
        }
    }
    if(val>1){
        fact[val]++;
    }
    // dbg(v[i])
    // dbg(fact)
    for(auto t:fact){
        int f = t.first;
        int freq = t.second;
        if(mp.count(f)==0){
            mp[f] = {freq,(ll)1e9,1};
        }
       else {
            ll mini = mp[f][0];
            ll ss = mp[f][1];
            ll cnt = mp[f][2];
            
            // FIX #2: ALWAYS increment count, no matter what
            cnt++; 
            
            if (freq < mini) {
                ss = mini;
                mini = freq;
            } 
            else if (freq < ss) {
                ss = freq;
            }
            
            // Reassign the updated values
            mp[f] = {mini, ss, cnt};
        }
    }

    
    }
    // for(auto val:mp){
    //     cout<<val.first<<" "<<val.second.first<<" "<<val.second.second<<endl;
    // }
    // for(auto val:mp){
    //     cout<<val.first<<" "<<val.second[0]<<" "<<val.second[1]<<" "<<val.second[2]<<endl;
    // }
    
    ll ans = 1;
    for(auto val:mp){
        ll smin = 1e9;
        auto &vec = val.second;
        ll f = vec[0];
        ll s =vec[1];
        ll cnt = vec[2];
        if(cnt == n){
            smin = s;
        }
        else if(cnt == n-1){
            smin = f;
        }
        if(smin!=1e9){

            ans *= power(val.first,smin);
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
