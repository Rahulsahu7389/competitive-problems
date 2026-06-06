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
   ll n;
   cin>>n;
   string s;
   cin>>s;
   vector<pair<ll,char>> freq(26);//freq,char
   for (ll i = 0; i < 26; i++)
   {
    freq[i].second = 'a' + i;
   }
   
   for(auto val:s){
    freq[val-'a'].first++;
    // freq[val-'a'].second = val;
   }
   dbg(freq)
   sort(freq.rbegin(),freq.rend());
   ll bestk = 1;
   ll minchanges = n;
   for (ll i = 1; i <=26; i++)
   {
    if(n%i!=0) continue;
    //can have i number of distinct char in answer
    ll sum = 0;
    for(int j = 0;j<i;j++){//take top i char
      sum += min(n/i,freq[j].first);
    }
    if(n -sum <minchanges){
      minchanges = n -sum;
      bestk = i;
    }
    
   }
   dbg(bestk,minchanges)
   map<char,ll> mp;
   for (ll i = 0; i < bestk; i++)
   {
    mp[freq[i].second] += n/bestk;
   }

   //got like all characters jo hone chaiye first solve the fixed one
   string ans(n,' ');//string with " "
   for (ll i = 0; i < n; i++)
   {
    if(mp[s[i]]){
      ans[i] = s[i];
      mp[s[i]]--;
    }
   }
   dbg(ans)
   dbg(mp)
   for (ll i = 0; i < n; i++)
   {
    if(ans[i]!=' ') continue;
    while(!mp.empty() && mp.begin()->second ==0){//deleting the first zeros
      mp.erase(mp.begin());
    }
    auto it = mp.begin();
    ans[i] = it->first;
    it->second--;


   }
   cout<<minchanges<<endl;
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
