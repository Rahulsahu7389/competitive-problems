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
   string s;
   cin>>s;
   string t;
   cin>>t;
   map<char,ll> m1;
   map<char,ll> m2;
   for(auto val:s){
    m1[val]++;
   }
   for(auto val:t){
    m2[val]++;
   }
   dbg(m2)
   bool flag = false;
   for(auto val:m1){
    if(m1[val.first]>m2[val.first]){
        flag = true;
        break;
    }
    else{
        m2[val.first] -= m1[val.first];
    }
   }
   dbg(m2)
   if(flag){
    cout<<"Impossible\n";
    return;
   }

   string temp = "";
   for(auto val:m2){
    for (ll i = 0; i < val.second; i++)
    {
        temp += val.first;
    }
    
   }
//    dbg(temp)
   ll l = 0;//s
   ll r = 0;//temp
   string ans = "";
   while(l<s.length() && r<temp.length()){
    if(temp[r]<s[l]){
        ans += temp[r];
        r++;
    }
    else if(temp[r]>s[l]){
        ans += s[l];
        l++;
    }
    else{
        ans += s[l];
        l++;
    }
   }
   dbg(ans)
   while(l<s.length()){
    ans += s[l];
    l++;
   }
   while(r<temp.length()){
    ans += temp[r];
    r++;
   }
   dbg(ans)
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
