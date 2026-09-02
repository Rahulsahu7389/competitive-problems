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

void fun(ll i, ll k,vector<vector<ll>> &ans,vector<ll> &temp,ll n){
    if(i==n){
        if(k==0) ans.push_back(temp);
        return;
    }
    // if(k<0) return;
    for(int j = 0;j<=(k/i);j++){
        ll sum = k - i*j;
        temp.push_back(j);
        fun(i+1,sum,ans,temp,n);
        temp.pop_back();
    }
}

void fun(ll i ,ll k,vector<vector<ll>> &ans,vector<ll> &temp,ll n){
    if(i==n){
        if(k%i==0){
            temp.push_back(k/i);
            ans.push_back(temp);
            temp.pop_back();
        }
        return;
    }
    for (int j = 0; j*i <=k; j++)
    {
        ll sum = k - i*j;
        temp.push_back(j);
        fun(i+1,sum,ans,temp,n);
        temp.pop_back();
    }
    
}

void solve(){
   //your code starts from here
   ll n,k;
   cin>>n>>k;
    vector<vector<ll>> ans;
    vector<ll> temp;
   fun(1,k,ans,temp,n);
   for(auto &val:ans){
    for(auto cal:val){
        cout<<cal<<" ";
    }
    cout<<endl;
   }
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
