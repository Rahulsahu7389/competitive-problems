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

    vector<int> parent,sizes;

    
    int findPar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findPar(parent[node]);//this assignment makes it compression
    }
    
    void unionBySize(int u,int v){
        int ulti_u = findPar(u);
        int ulti_v = findPar(v);
        if(ulti_u == ulti_v) return;
        if(sizes[ulti_u]<sizes[ulti_v]){
            parent[ulti_u] = ulti_v;
            sizes[ulti_v]  += sizes[ulti_u];
        }
        else{
            parent[ulti_v] = ulti_u;
            sizes[ulti_u] += sizes[ulti_v];
        }
    }


void solve(){
   //your code starts from here
   ll n,x,y;
   cin>>n>>x>>y;
   vector<ll> v(n);
   for (ll i = 0; i < n; i++)
   {
    cin>>v[i];
   }
   parent.assign(n+1,0);
   sizes.assign(n+1,1);
   for (ll i = 1; i <=n; i++)
   {
    parent[i] = i;
   }
   for (ll i = 0; i < n; i++)
   {
    ll left1 = i-x;
    if(left1>=0){
        unionBySize(v[i],v[left1]);
    }
    ll right = i+x;
    if(right<n){
        unionBySize(v[i],v[right]);
    }
   }
   for (ll i = 0; i < n; i++)
   {
    ll left1 = i-y;
    if(left1>=0){
        unionBySize(v[i],v[left1]);
    }
    ll right = i+y;
    if(right<n){
        unionBySize(v[i],v[right]);
    }

   }
   vector<ll> temp(all(v));
   sort(all(temp));
   for (ll i = 0; i < n; i++)
   {
    if(v[i]!=temp[i]){
        if(findPar(v[i])!=findPar(temp[i])){
            cout<<"NO\n";
            return;
        }
    }
   }
   cout<<"YES\n";
   
   
   
   
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
