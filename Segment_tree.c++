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

int a[100005] , seg[4*100005];

void build(int ind , int low , int high){
    if(low == high){
        seg[ind] = a[low];//base case leaf node
        return;
    }
    int mid = (low + high)/2;
    build(2*ind+1,low,mid);
    build(2*ind+2,mid+1,high);
    seg[ind] = max(seg[2*ind+1],seg[2*ind+2]);//storing the max into the parent
}

int query(int ind,int low,int high,int l , int r){
    if(low>=l && high<=r){//if completely lies in range
        return seg[ind];
    }
    if(high< l || low>r){//if doesnt lie at all
        return  INT_MIN;
    }
    int mid = (low + high)/2;
    int left = query(2*ind+1,low ,mid,l,r);
    int right = query(2*ind+2,mid+1,high,l,r);
    return max(left,right);
}

// call by pointUpdate(0,0,n-1,node,val)
void pointUpdate(int ind , int low , int high ,int node, int val){
    if(low == high){
        seg[low] += val;//leaf node
    }
    else{
        int mid = (low + high)/2;
        if(node<=mid && node>=low){//if lies on the left
            pointUpdate(2*ind+1,low,mid,node,val);
        }
        else{//lies on the right
            pointUpdate(2*ind+2,mid+1,high,node,val);
        }
        seg[ind] = seg[2*ind+1]+seg[2*ind+2];//once updatation done now update the parent
    }
}

void solve(){
   //your code starts from here
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
