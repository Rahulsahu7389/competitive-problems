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
   ll n;
   cin>>n;
   vector<vector<int>> v(n+1,vector<int> (n+1,0));
//    dbg("hre")
   v[1][2] = v[2][1] = 3;
   v[1][3] = v[3][1] = 2;
   v[2][2] = 4;
   v[2][3] = v[3][2] = 1;
   v[3][3] =4;
   v[1][4] = v[4][1] = v[4][3] = v[3][4] = 3;
   v[2][4] = v[4][4] = v[4][2] = 2;
   if(n==4){
    v[1][4] =5;
    v[4][1] =5;
   }
   vector<pair<int,int>> dir;
   dir.push_back({-2,-1});
   dir.push_back({-2,1});
   dir.push_back({-1,2});
   dir.push_back({1,2});
   dir.push_back({-1,-2});
   dir.push_back({1,-2});
   dir.push_back({2,1});
   dir.push_back({2,-1});
   for(int j =5;j<=n;j++){
    for (int  i = 1; i <=4 ; i++)
    {
        int ans = 1e9;
        for(auto val:dir){
            int x = i+val.first;
            int y = j+val.second;
            if(x>=1 && x<=n && y>=1 && y<=n && v[x][y]!=0){
                ans =min(ans,v[x][y]);
            }
        }
        // dbg(i,j)
        v[i][j] = ans +1;
    }
   }
   for (int  i = 5; i <=n ; i++)
    for(int j =1;j<=4;j++){
    {
        int ans = 1e9;
        for(auto val:dir){
            int x = i+val.first;
            int y = j+val.second;
            if(x>=1 && x<=n && y>=1 && y<=n && v[x][y]!=0){
                ans =min(ans,v[x][y]);
            }
        }
        // dbg(i,j)
        v[i][j] = ans +1;
    }
   }
   for (int  i = 5; i <=n ; i++)
    for(int j =5;j<=n;j++){
    {
        int ans = 1e9;
        for(auto val:dir){
            int x = i+val.first;
            int y = j+val.second;
            if(x>=1 && x<=n && y>=1 && y<=n && v[x][y]!=0){
                ans =min(ans,v[x][y]);
            }
        }
        // dbg(i,j)
        v[i][j] = ans +1;
    }
   }
    // dbg(v)
   for(int i = 1;i<=n;i++){
    for (int j  = 1; j  <=n ; j ++)
    {
        cout<<v[i][j]<<" ";
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
