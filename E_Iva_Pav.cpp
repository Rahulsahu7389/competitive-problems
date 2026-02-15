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

void build(ll ind, ll l ,ll r,vector<ll>& v, vector<ll> &seg){//here ind = 0 as root 0 se start hota and l and r is the range of root node
    if(l == r){
        seg[ind] = v[l];//here both l and r are index of v also but ind is of seg only
        return;
    }
    ll mid = (l+r)/2;
    build(2*ind+1,l,mid,v,seg);
    build(2*ind+2,mid+1,r,v,seg);
    seg[ind] = (seg[2*ind+1]&seg[2*ind+2]);

}

ll findidx(ll ind ,ll l ,ll r , vector<ll> & seg , ll x){
    if(l == r){
        if(seg[ind]>=x){
            return l;
        }
        else{
            return -1;
        }
    }
    ll mid = (l + r)/2;
    ll left = findidx(2*ind+1,l,mid,seg,x);
    ll right = findidx(2*ind+2,mid+1,r,seg,x);
    ll curr = -1;
    if(seg[ind]>=x){
        curr = r;
    }
    return max({left,right,curr});

}

int a[200000];
int pre[30][200001];

int range_and(int l ,int r){
    int ans = 0;
    for(int i = 0;i<30;i++){
        if(pre[i][r+1] - pre[i][l] == 0){
            ans += (1<<i);
        }
    }
    return ans;
}

void solve(){
   //your code starts from here
   ll n;
   cin>>n;
//    vector<ll> v(n);
   for (ll i = 0; i < n; i++)
   {
    cin>>a[i];
   }

   for (int j = 0; j < 30; j++)
   {
    pre[j][0] = 0;
    for (ll i = 0; i < n; i++)
    {
        if((1<<j)&a[i]){//if bit 1 ho
            pre[j][i+1] = pre[j][i];
        }
        else{
            pre[j][i+1] = pre[j][i] + 1;
        }
    }
    
   }
   ll q;
   cin>>q;
   while(q--){
    int l,k;
    cin>>l>>k;
    l--;
    if(a[l]<k){
        cout<<-1<<" ";//if l me hi km hai to aage bhi less hoga
        continue;
    }
    int low = l,high = n-1;
    while(low<high){
        int mid = (low + high+1)/2;
        if(range_and(l,mid)>=k){
            low = mid;
        }
        else{
            high = mid - 1;
        }
    }
    cout<<low + 1<<" ";
    

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
