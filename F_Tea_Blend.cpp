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

const int M = 1000000;

vector<int> spf(M+1);

void linearSieve(int n) { // O(n)

    // vector<int> spf(n + 1);
    vector<int> primes;

    for(int i = 2; i <= n; i++) {

        // i is prime so prime wale array me dalo
        if(spf[i] == 0) {
            spf[i] = i;
            primes.push_back(i);
        }
        // jo jo primes hai usko i se multiply kroge to vo sare composite number milenge
        for(int p : primes) {

            if(p > spf[i] || 1LL * i * p > n)// first condition ensure ki composite ek baar touch hota
                break;

            spf[i * p] = p;
        }
    }

}

// struct custom_hash {
//     static uint64_t splitmix64(uint64_t x) {
//         x += 0x9e3779b97f4a7c15;
//         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//         return x ^ (x >> 31);
//     }
//     size_t operator()(uint64_t x) const {
//         static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
//         return splitmix64(x + FIXED_RANDOM);
//     }
// };

void solve(){
   //your code starts from here
   ll n;
   cin>>n;
   vector<ll> v(n);
   for (ll  i = 0; i < n; i++)
   {
    cin>>v[i];
   }
   unordered_map<int,int> cnt;
   for (ll  i = 0; i < n; i++)
   {
    ll val = v[i];
    ll base = 1;
    while(val>1){
        ll x = spf[val];
        while(val%x==0){

            if(base%x==0){
                base /= x;
            }
            else base *= x;
            val /= x;
        }
    }
    cnt[base]++;
   }

   ll ans = 0;
   unordered_set<int> st;
   ll p = 1; // Declare p outside the loop to maintain its state

    for (int i = 0; i < n; i++) {
        int val = v[i];
        while(val > 1) {
            ll x = spf[val];
            if (st.count(x)) {
                st.erase(x);
                // If x is removed, divide p by x
                // Note: only do this if p wasn't already marked as invalid (-1)
                if (p != -1) p /= x; 
            } else {
                st.insert(x);
                // If x is added, multiply p by x
                if (p != -1) {
                    p *= x;
                    if (p > M) p = -1;
                }
            }
            val /= x;
        }
        
        // Now you just check p without iterating over st!
        if (p != -1 && p<=M) {
            ans += cnt[p];
        }
    }
   cout<<ans<<endl;
   
   

   
}

int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    linearSieve(M);
    ll T; 
    cin >> T; 
    while (T--) { 
        solve(); 
    } 
    return 0; 
}
