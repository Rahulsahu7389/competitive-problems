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
   //your code starts from here
   ll n1,n2;
   cin>>n1;
   vector<ll> a(n1);
   
   ll sum1 = 0;
   ll sum2 = 0;
   for (ll i = 0; i < n1; i++)
   {
    cin>>a[i];
    sum1 += a[i];
   }
   cin>>n2;
   vector<ll> b(n2);
   for (ll i = 0; i < n2; i++)
   {
    cin>>b[i];
    sum2 += b[i];
   }
   
   if(sum1!=sum2){
    cout<<-1<<endl;
   }
   
   vector<ll> temp;
   if(n1<n2){
    temp = a;
    a = b;
    b = temp;
   }
   ll i= 0;
   ll j = 0;
   ll prev = -1;
   bool flag = false;
   
   n1 = a.size();
   n2 = b.size();

   ll idx = -1;
   ll sum = 0;
   while(i<n1 && j<n2){
    ll val = b[j];
    sum += a[i];
    if(sum == val){
        i++;
        sum = 0;
        j++;
    }
    else if(sum<val){
        i++;
        
        
    }
    else if(sum>val){
        
    }
    else{
        break;
        flag = true;
    }
   }
   if(flag){
    ll ans = j+1;
    cout<<ans<<endl;
   }
   cout<<n2<<endl;

   
   
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
