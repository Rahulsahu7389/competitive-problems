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

vector<ll> seg;
vector<ll> v;
vector<ll> lazy;

void build(ll ind, ll l ,ll r){//here ind = 0 as root 0 se start hota and l and r is the range of root node
    if(l == r){
        seg[ind] = v[l];//here both l and r are index of v also but ind is of seg only
        return;
    }
    ll mid = (l+r)/2;
    build(2*ind+1,l,mid);
    build(2*ind+2,mid+1,r);
    seg[ind] = seg[2*ind+1] + seg[2*ind+2];

}

// call by pointUpdate(0,0,n-1,node,val) ---- O(logn)
void pointUpdate(int ind , int low , int high ,int idx, int val){//ind is for seg and low and high which range it starts and idx is the index in a where value to be udpated is val
    if(low == high){
        seg[ind] += val;//leaf node -- it can be = only also
    }
    else{
        int mid = (low + high)/2;
        if(idx<=mid && idx>=low){//if lies on the left
            pointUpdate(2*ind+1,low,mid,idx,val);
        }
        else{//lies on the right
            pointUpdate(2*ind+2,mid+1,high,idx,val);
        }
        seg[ind] = seg[2*ind+1]+seg[2*ind+2];//once updatation done now update the parent
    }
}

// runs in logn -- call by (0,0,n-1,l,r)
int querySum(int ind,int low,int high,int l , int r){// here ind is for seg and low and high is the inital and l to r me ka range ka sum chaiye
    if(low>r || high<l){//to avoid unnecessary calculations
        return 0;
    }
    if(low>=l && high<=r){//if completely lies in range
        return seg[ind];
    }
    if(high< l || low>r){//if doesnt lie at all
        return  0;
    }
    int mid = (low + high)/2;
    int left = querySum(2*ind+1,low ,mid,l,r);
    int right = querySum(2*ind+2,mid+1,high,l,r);
    return (left + right);
}


// ind is for seg and you want to update into range l to r with value val ---- works for logn
void rangeUpdate(int ind , int low , int high , int l , int r ,int val){//here l and r is the range into which you want to update and low and high chnage hoga
    //seeing if any update pending
    if(lazy[ind]!=0){
        seg[ind] += (high - low + 1)*lazy[ind];
        if(low !=high){
            //if not leaf node so update the lazy of its children for later updates
            lazy[2*ind+1] += lazy[ind];
            lazy[2*ind + 2] += lazy[ind];
        }
        lazy[ind ]= 0;
    }
    if(r<low || l > high || low > high) return;//if completely outside

    //if overlaps completely so update the value and propagate the update to its childs for later
    if(low >= l && high <=r){
        seg[ind]+= (high - low + 1)*val;
        if(low !=high){
            lazy[2*ind + 1] += val;
            lazy[2*ind+2] += val;
        }
        return;
    }

    //if it partially overlaps with the range
    int mid = (low + high)>>1;
    rangeUpdate(2*ind + 1,low,mid,l,r,val);
    rangeUpdate(2*ind+2,mid+1,high,l,r,val);
    seg[ind] = seg[2*ind+1] + seg[2*ind +2];//updating the parent after updating its childs

    
}

int querySumLazy(int ind , int low , int high , int l , int r ){
    //seeing if any update pending
    if(lazy[ind]!=0){
        seg[ind] += (high - low + 1)*lazy[ind];
        if(low !=high){
            //if not leaf node so update the lazy of its children for later updates
            lazy[2*ind+1] += lazy[ind];
            lazy[2*ind + 2] += lazy[ind];
        }
        lazy[ind ]= 0;
    }
    if(r<low || l > high || low > high) return 0;//if completely outside

    if(low>=l && high<=r){
        return seg[ind];
    }
    int mid = (low + high) >> 1;
    //if there is the partial overlaps
    return querySumLazy(2*ind+1,low,mid,l,r) + querySumLazy(2*ind+2,mid+1,high,l,r);
}

void solve(){
   //your code starts from here
   ll n ;
   cin>>n;
   seg.assign(4*n,0);
   v.assign(n,0);
   lazy.assign(4*n,0);
   for (ll i = 0; i < n; i++)
   {
    cin>>v[i];
   }
   build(0,0,n-1);
   rangeUpdate(0,0,n-1,1,3,2);
   cout<<querySumLazy(0,0,n-1,1,3);


   
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
