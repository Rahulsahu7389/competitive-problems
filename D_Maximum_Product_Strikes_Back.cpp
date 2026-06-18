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
bool DEBUG_MODE = false;  // toggle before submission

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
   vector<ll> v(n+1);
   ll cntz = 0;
   for (ll i = 1; i <=n; i++)
   {
    cin>>v[i];
    if(v[i]==0){
        cntz++;
    }
   }
   if(cntz==n){
    cout<<n<<" "<<0<<endl;
    return;
   }
   vector<pair<ll,ll>> pre(n+1);//cnt of twos , no of neg
   for (ll i = 1; i <=n; i++)
   {
    if(v[i] == 0){
        pre[i] = {0,0};

    }
    else{
        if(v[i]<0){
            pre[i].second = pre[i-1].second + 1;
        }
        else pre[i].second = pre[i-1].second;

        if(abs(v[i])==2){
            pre[i].first = pre[i-1].first + 1;
        }
        else  pre[i].first = pre[i-1].first;
    }
   }
   vector<pair<ll,ll>> stend,stendneg;
   ll st = 1;
   ll end = 1;
   ll negst = -1;
   ll negend = -1;
   dbg(v)
   for (ll i = 1; i <=n; i++)
   {
    if(v[i]==0){
        if(end>n) continue;
        
        stendneg.push_back({negst,negend});
        stend.push_back({st,end});
        
        st = i+1;
        end = st;
        negst = -1;
        negend = -1;
    }
    else{
        if(v[i]<0){
            if(negst==-1){
                negst = i;
            }
            negend = i;
        }
        end = i;
    }
   }
//    dbg(st,end)
   if(end<=n){

       stendneg.push_back({negst,negend});
       stend.push_back({st,end});
    }
    vector<vector<ll>> p;//no of two , st ,end
   dbg(stend)
   dbg(stendneg)
   dbg(pre)
   for (ll i = 0; i < stend.size(); i++)
   {
       ll st1 = stend[i].first;
       ll end1 = stend[i].second;
       ll sneg = stendneg[i].first;
       ll eneg = stendneg[i].second;
    
       if(sneg==-1 || (pre[end1].second - pre[st1-1].second)%2==0){
        //no neg elements
        dbg("hre",i+1)
        ll tot2 = pre[end1].first - pre[st1-1].first;
        p.push_back({tot2,st1,end1});
       }
       else{
        //contains odd neg
        ll tot2 = pre[end1].first - pre[st1-1].first;
        ll afterright = tot2 - (pre[end1].first - pre[eneg-1].first);
        ll afterleft = tot2 - (pre[sneg].first - pre[st1-1].first);
        if(afterright>afterleft){
            p.push_back({afterright,st1,eneg-1});
        }
        else{
            p.push_back({afterleft,sneg+1,end1});
        }
       }
    
   }
   dbg(p)
   sort(p.rbegin(),p.rend());
   auto it = p[0];
   if(it[0]==0){
    cout<<n<<" "<<0<<endl;
    return;
   }
   cout<<(it[1]-1)<<" "<<(n - it[2])<<endl;



   
   
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
