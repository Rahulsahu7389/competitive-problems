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
bool primeFactorisation(int n,set<ll> & s){
    set<ll> temp(all(s));
    dbg(n)
    for (int i = 2; i*i <=n; i++)
    {
        while(n%i == 0){
            if(temp.count(i)>0){
                return true;
            }
            s.insert(i);
            n /= i;
        }
    }
    
    if(n!=1){
        if(temp.count(n)>0){
            return true;
        }
        s.insert(n);
        // cout<<n<<endl;
    }

    
    return false;
}

void solve(){
   //your code starts from here
   ll n;
   cin>>n;
   vector<ll> v(n);
   set<ll> s;
   map<ll,ll> m;
   for (ll i = 0; i < n; i++)
   {
    cin>>v[i];
   }
   for (ll i = 0; i < n; i++)
   {
    ll b;
    cin>>b;
   }

   //for 0
   for (ll k = 0; k < n; k++)
   {
    ll t = v[k];
    set<ll>s ;

    for (int i = 2; i*i <=t; i++)
    {
        while(t%i == 0){
            s.insert(i);
            t /= i;
        }
    }
    
    if(t!=1){
        s.insert(t);
    }
    for (auto &&i : s )
    {
        if(m[i]>0){
            cout<<0<<endl;
                return;
        }
        else{
            m[i]++;
        }
    }
    
   }

//    for 1
   for (ll k = 0; k < n; k++)
   {
    ll t = v[k] + 1;
    for (int i = 2; i*i <=t; i++)
    {
        while(t%i == 0){
            if(m[i]>0){
                cout<<1<<endl;
                return;
            }
            // s.insert(i);
            t /= i;
        }
    }
    
    if(t!=1){
        if(m[t]>0){
            cout<<1<<endl;
            return ;
        }
        // s.insert(t);
        // cout<<n<<endl;
    }
   }

   cout<<2<<endl;
   
   

   
   
   

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
