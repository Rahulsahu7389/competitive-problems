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
   ll cntneg = 0;
   for (ll i = 0; i < n; i++)
   {
    cin>>v[i];
    if(v[i] ==-1) cntneg++;
   }
   bool flag = true;
   string ans(n,'0');
   for (ll i = 0; i < n; i++)
   {
    if(v[i]==0){
        ans[i] = '1';
        continue;
    }
    else if(v[i]==-1) continue;
    int left = i- v[i];
    int right = i+v[i];
    if(left>=0){
        if(v[left]==-1){
            ans[i] = '1';
        }
        else{
            if(v[left]!=0){
                cout<<-1<<endl;
                return;
            }
        }
    }
    if(right<n){
        if(v[right]==-1){
            ans[i] = '1';
        }
        else{
            if(v[right]!=0){
                cout<<-1<<endl;
                return;
            }
        }
    }
   }
   if(cntneg == 0){
    cout<<ans<<endl;
    return;
   }
   if(cntneg==n){
    string t(n,'0');
    t[0] = '1';
    cout<<t<<endl;
    return;
   }
//    dbg(ans)
   vector<ll> pre(n,-2),suff(n,-2);
   int cnt = -1;
   for (ll i = 0; i < n; i++)
   {
    if(cnt == -1 && ans[i]!='1') continue;
    if(ans[i]=='1'){
       cnt = 0;
       pre[i] = cnt;
    }
    else{
        cnt++;
        pre[i] =cnt;
    }
   }
   cnt = -1;
   for (ll i = n-1;i>=0;i--)
   {
    if(cnt == -1 && ans[i]!='1') continue;
    if(ans[i]=='1'){
       cnt = 0;
       pre[i] = cnt;
    }
    else{
        cnt++;
        pre[i] = cnt;
    }
   }
   for (ll i = 0; i < n; i++)
   {
    if(pre[i]==-2 || suff[i]==-2) continue;
    else{
        if(pre[i]!=suff[i]){
            cout<<-1<<endl;
            return;
        }
    }
   }
   cout<<ans<<endl;
   
   
   
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
