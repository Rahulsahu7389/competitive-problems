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

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll n = a+b+c;
    ll m = n*2;
    if(b & 1){
        cout<<-1<<endl;
        return;
    }
    ll d = c/3;
    d *= 3;
    vector<ll> vis(m);
    vector<pair<ll,ll>> ans;
    int i = 0;
    for (i = 0;i < m && d>0; i++)
    {
        if(vis[i]==0 && i+3<m && vis[i+3]==0 && d>0){
            vis[i]=1;
            vis[i+3]=1;
            d--;
            c--;
            ans.push_back({i+1,i+3+1});
        }
    }
    ll r = c%3;
    i = 0;
    while(i<m && vis[i]) i++;

    if(b>=2 && i<m){
        if(r==1){
            if(i+2<m){
                vis[i] = 1;
                vis[i+2] = 1;
                ans.push_back({i+1,i+2+1});
            }
            // int j = i+1;
            if(i+4<m){
                vis[i+1] =1;
                vis[i+4] = 1;
                ans.push_back({i+1+1,i+4+1});
            }
            if(i+5<m){
                vis[i+3] =1;
                vis[i+5] = 1;
                ans.push_back({i+1+3,i+5+1});
            }
            b -= 2;
            c--;
        }
        else if(r==2){
            if(i+2<m){
                vis[i] = 1;
                vis[i+2] = 1;
                ans.push_back({i+1,i+2+1});
            }
            // int j = i+1;
            if(i+4<m){
                vis[i+1] =1;
                vis[i+4] = 1;
                ans.push_back({i+1+1,i+4+1});
            }
            if(i+5<m){
                vis[i+3] =1;
                vis[i+6] = 1;
                ans.push_back({i+1+3,i+6+1});
            }
            if(i+5<m){
                vis[i+5] =1;
                vis[i+7] = 1;
                ans.push_back({i+1+5,i+7+1});
            }
            b -=2;
            c-=2;
        }
    }
    else if(b==0 && i<m){
        for ( i; i < m; i++)
        {
            if(vis[i]==0 && i+3<m && vis[i+3]==0 && c>0){
                c--;
                vis[i] = 1;
                vis[i+3] =1;
                ans.push_back({i+1,i+4});
                i = i+3;
            }
        }
        
    }

    //for 2
    for (ll j = 0; j < m; j++)
    {
        if(vis[j]==0 && j+2<m && vis[j+2]==0 && b>0){
            vis[j]=1;
            vis[j+2] =1;
            b--;
            ans.push_back({j+1,j+2+1});
        }
    }
    //for 1
    for (ll j = 0; j < m; j++)
    {
        if(vis[j]==0 && j+1<m && vis[j+1]==0 && a>0){
            vis[j]=1;
            vis[j+1] =1;
            a--;
            ans.push_back({j+1,j+2});
        }
    }
    if(a>0 || b>0 || c>0){
        cout<<-1<<endl;
        return;
    }
    for(auto val:ans){
        cout<<val.first<<" "<<val.second<<endl;
    }

    
    

    
    
    

    
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
