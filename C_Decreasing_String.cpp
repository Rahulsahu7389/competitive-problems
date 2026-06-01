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
   ll pos;
   cin>>pos;
   ll n = s.length();
   if(n==1){
    cout<<s[0]<<"";
    return;
   }
   ll sumback = (n)*(n+1)/2 - pos;
//    ll temp = 0;
    ll x = n;
   for (ll i = 1; i <=n; i++)
   {
    ll temp = (i)*(i+1)/2;
    if(temp>sumback){
        x = i;
        break;
    }
   }
   ll nodeletion = n - x ;
   dbg(nodeletion)
   //need to find the smaller ones
   vector<ll> invalid(n);
   for (ll i = 0; i < n-1; i++)
   {
    if(s[i]>s[i+1]){
        invalid[i] = 1;
    }
   }
   string newstr = "";
ll deltillnow = 0;

for (char c : s) {
    // While there are characters in our new string, AND the last character
    // is lexicographically greater than the current one, AND we still need to delete
    while (!newstr.empty() && newstr.back() > c && deltillnow < nodeletion) {
        newstr.pop_back(); // Remove the strictly greater character
        deltillnow++;
    }
    // Add the current character to our new string
    newstr.push_back(c);
}


while (deltillnow < nodeletion) {
    newstr.pop_back();
    deltillnow++;
}
   dbg(newstr)
   //how much pos till now
   ll t = nodeletion -1;
   ll t2 = nodeletion + 1;
   dbg((t*(t+1))/2)
   ll idx = (n*(n+1))/2 - (x*(x+1))/2;
   dbg(idx)
   ll diff = pos - idx;
   dbg(diff)
   diff--;//0 based index for final string
   cout<<newstr[diff]<<"";


   
   

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
