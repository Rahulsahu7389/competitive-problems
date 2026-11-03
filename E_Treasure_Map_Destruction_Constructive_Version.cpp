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
   vector<ll> v(n);
   for (ll  i = 0; i < n ; i++)
   {
    cin>>v[i];
   }
   vector<ll> diff(n+1);
   for (ll  i = 0; i < n; i++)
   {
    if(v[i]==0 || v[i]==-1) continue;
    int left = i-v[i];
    int right = i +v[i];
    bool f1 = false,f2 = false;
    if(left>=0 && v[left]!=0 && v[left]!=-1){
        // dbg(i)
        f1 = true;//it should have been the 0
        // return;
    }
    if(right<n && v[right]!=0 && v[right]!=-1){
        // dbg(i)
        // cout<<-1<<endl;//it should have been the 0
        f2 = true;
        // return;
    }
    if(f1==true && f2 == true){
        cout<<-1<<endl;return;
    }
    left = max(0LL,i-v[i]+1);
    right = min(n-1,i+v[i]-1);
    diff[left] +=1;
    diff[right+1] -=1;

   }
   
   for(int i = 1;i<n;i++){
    diff[i] += diff[i-1];
   }
//    dbg(diff)
   vector<ll> ans(n,-1);
   for (ll  i = 0; i < n ; i++)
   {
    if(diff[i]==0){
        ans[i] = 1;
    }
   }
//    dbg(ans)
   for (ll  i = 0; i < n ; i++)
   {
    if(v[i]==-1 || diff[i]==0) continue;
    if(v[i]==0 && diff[i]>0){
        cout<<-1<<endl;
        return;
    }
    int left = i-v[i];
    int right = i +v[i];
    bool flag1 = false, flag2 = false;
    if(left>=0 && diff[left]>0){
        // dbg(diff[left],i)
        flag1 = true;
    }
    else if(left<0) flag1 = true;
    
    if(right<n && diff[right]>0){
        // dbg(2,i)
        flag2 = true;
    }
    else if(right>=n) flag2 = true;
    // dbg(flag1,flag2,i)
    if(flag1==true && flag2==true){
        // dbg(2,i)
        cout<<-1<<endl;return;
    }
   }
   for(int i = 0;i<n;i++){
    if(ans[i]==-1) ans[i] =0;
   }
   for(auto val:ans){
    cout<<val;
   }
   
   cout<<endl;
   
   
   
   
   
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
