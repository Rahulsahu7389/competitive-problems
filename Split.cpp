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

ll fun(string s , ll k){
    ll zero = 0;
    ll one = 0;
    ll cnt = 0;
    ll maxi = -1;
    ll parts = 1;
    char prev = s[0];
    for (ll i = 0; i < s.length(); i++)
    {
        if(s[i] == '0'){
            zero++;
        }
        if(s[i] == '1'){
            one++;
        }
        
        if((s[i] == '0' && (s[i] == prev)) || (s[i]=='1' && (prev == '0') )){
            cnt++;
        }
        else{
            maxi = max({cnt , zero , one});
            cnt = 0;
        }
        maxi = max({cnt , zero , one});
        if(cnt >=k){
            parts++;
            cnt = 0;
            // continue;
        }
        dbg(i , zero , one);
        dbg(i , maxi , parts);
        prev = s[i];
    }
    if(cnt<maxi){
        parts--;
    }
    return parts;
    
}

bool canSplit(const string &s, int k, int target) {
    int parts = 0;
    int zeros = 0, trailingOnes = 0;

    for (char c : s) {
        if (c == '0') {
            zeros++;
            trailingOnes = 0;  // reset trailing ones after a new zero
        } else {
            trailingOnes++;
        }

        int f = zeros + trailingOnes;
        if (f >= target) {
            parts++;
            zeros = 0;
            trailingOnes = 0;  // start new part
        }
    }
    return parts >= k;
}

void solve(){
   //your code starts from here
   string s;
   ll k;

   cin>>s;
   cin>>k;
   cout<<canSplit(s, k , 1)<<endl;
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
