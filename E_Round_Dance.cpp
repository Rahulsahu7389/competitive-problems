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

bool  bfs(ll s ,vector<vector<ll>>& adj , vector<ll>&vis){
    queue<pair<int,int>> q;
    q.push({s,-1});//node,parent
    vis[s] = 1;
    bool flag = false;
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        
        
        for(auto val:adj[it.first]){
            if(!vis[val]){
                q.push({val,it.first});
                vis[val] = 1;
            }
            else if(val!= it.second){
                flag = true;//if it finds any loop
            }
        }
        
    }
    return flag;
}

void solve(){
   //your code starts from here
   ll n;
   cin>>n;
   vector<ll> v(n);
   set<pair<ll,ll>> st;
   for (ll i = 0; i < n; i++)
   {
    cin>>v[i];
    ll mini = min(i+1,v[i]);
    ll maxi = max(i+1,v[i]);
    st.insert({mini,maxi});
   }
   vector<vector<ll>> adj(n);
   for(auto val:st){
    ll f = val.first;
    ll s = val.second;
    f--;s--;
    adj[f].push_back(s);
    adj[s].push_back(f);
   }

   vector<ll> vis(n);

   ll looped = 0;
   ll linear = 0;
   for (ll i = 0; i < n; i++)
   {
    if(vis[i]==0){
        bool ok = bfs(i,adj,vis);
        // dbg(i+1,ok)
        if(ok){
            looped++;
        }
        else{
            linear++;
        }
    }
   }
   ll mini = looped;
   if(linear>0){
    mini++;
   }
   cout<<mini<<" "<<looped+linear<<endl;
   



   
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
