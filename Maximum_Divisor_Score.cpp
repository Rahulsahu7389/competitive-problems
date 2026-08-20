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

vector<ll> fact;

void compute(ll n){
  fact[0] =fact[1] = 1;
  for (ll i = 2; i<=n; i++)
  {
    for (ll j =i*2; j <=n; j+=i)
    {
      fact[j]++;
    }
    
  }
  
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
   ll maxi = *max_element(all(v));
   fact.assign(maxi+4,2);
   compute(maxi);
   map<ll,ll> mp ;
  //  dbg(fact[4],fact[99])
  // dbg(v)
  // dbg(fact)
   for (ll i = 0; i < n ; i++)
   {
    ll val = v[i];
    ll ans = fact[val];
  //   // dbg(i)
    if(mp.count(val*2)){
      ans = max(ans,fact[val]+mp[val*2]);
    }
    if(mp.count(val*3)){
      ans = max(ans,fact[val] + mp[val*3]);
    }
    if(val%2==0 && mp.count(val/2)){
      ans = max(ans,fact[val] + mp[val/2]);
    }
    if(val%3==0 && mp.count(val/3)){
      ans = max(ans,fact[val] + mp[val/3]);
    }
    if(mp.count(val-1)){
      ans = max(ans,fact[val]+mp[val-1]);
    }
    if(mp.count(val+1)){
      ans = max(ans,fact[val]+mp[val+1]);
    }
    mp[val] = ans;
   }

   ll ans = 0;
   for(auto val:mp){
    ans = max(ans,val.second);
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

long long dp[100004];
    
  int solve(vector<int>& nums, int k) {
      ll n ,k;
      cin>>n;
      vector<ll> nums(n);
      for (ll i = 0; i < n; i++)
      {
        cin>>nums[i];
      }
      cin>>k;
      
      memset(dp,0,sizeof(dp));
      deque<int> dq;
      for(int i = n-1;i>=0;i--){
          if(i == n-1){
              dp[i] = nums[i];
              dq.push_front(i);
              continue;
          }
          
          // need to check expiry
          while(!dq.empty() && i+k<dq.front()){
              dq.pop_front();
          }
          long long ans = -1e9;
          if(!dq.empty()){
              int idx = dq.front();
              ans = max(ans,nums[i] + dp[idx] );
          }
          //insert after getting the choice done
          dp[i]= ans;
          while(!dq.empty() && dp[dq.back()]<=dp[i]){
              dq.pop_back();
          }
          dq.push_back(i);
          
      }
      return dp[0];
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


