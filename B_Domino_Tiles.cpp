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

bool valid(string &temp , string &s,ll i){
  if(s[i]!='?' && s[i]!=temp[i]){
    return false;
  }
  return true;
}
ll ans = 0;
void fun(string s ,unordered_map<string,string>&mp){
  ll n = s.length();
  vector<string> v ={"00","01","10","11"};
  for(auto val:v){
    string temp = "";

    bool ok = true;
    for (ll i = 0; i < n; i++)
    {
      if(i==0 || i==1){
        temp.push_back(val[i]);
        if(!valid(temp,s,i)){
          ok = false;
          break;
        }
      }
      else{
        string st;
        st.push_back(temp[i-2]);
        st.push_back(temp[i-1]);
        string nxt= mp[st];
        temp.push_back(nxt[0]);
        if(!valid(temp,s,i)){
          ok = false;
          break;
        }

      }
      // dbg(val,i,temp)
    }
    if(ok){
      ans++;
    }
  }
  
}

void solve(){
   //your code starts from here
   ll n;
   cin>>n;
   string s;
   cin>>s;
   ll cntq = count(all(s),'?');
   if(cntq == n){
    if(n==1){
      cout<<2<<endl;
    }
    else{
      cout<<4<<endl;
    }
    return;
   }
   unordered_map<string,string>mp;
   mp["00"] ="1";
   mp["01"] ="1";
   mp["10"] ="0";
   mp["11"] ="0";
   ans = 0;
   if(cntq ==0){
    bool ok = true;
    if(n==1 || n==2){
      cout<<1<<endl;
      return;
    }
    for (ll i = 1; i < n-1; i++)
    {
      string st;
      st.push_back(s[i-1]);
      st.push_back(s[i]);
      char t = mp[st][0];
      if(t!=s[i+1]){
        // dbg(i)
        cout<<0<<endl;
        return;

      }

    }
    cout<<1<<endl;
    return;
    
   }
   fun(s,mp);

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
