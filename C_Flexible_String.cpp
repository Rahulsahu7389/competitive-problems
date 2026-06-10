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

void fun(ll i , vector<char> & ch , vector<vector<char>>&ans,vector<char> &temp,ll k){
    if(i ==ch.size()){
        if(temp.size()==k){

            ans.push_back(temp);
        }
        return;
    }
    //take
    temp.push_back(ch[i]);
    fun(i+1,ch,ans,temp,k);
    temp.pop_back();
    fun(i+1,ch,ans,temp,k);
}

ll calc(ll n){
    return ((n)*(n+1))/2;
}

void solve(){
   //your code starts from here
   ll n,k;
   cin>>n>>k;
   string a,b;
   cin>>a;
   cin>>b;
   //first find all the subset for q
   vector<ll> freq(26);
   vector<char> ch;
   for (ll i = 0; i < n; i++)
   {
    if(freq[a[i]-'a']==0){
        freq[a[i]-'a']++;
        ch.push_back(a[i]);
    }
   }
   if(ch.size()<=k){
    ll val = ((n)*(n+1))/2;
    cout<<val<<endl;
    return;
   }

   
    vector<vector<char>> subset;
    vector<char> temp;
    fun(0,ch,subset,temp,k);

   //cal for each
   ll ans = 0;
   for(auto &val:subset){
    vector<ll> newfreq(26);
    for (ll i = 0; i < val.size(); i++)
    {
        newfreq[val[i]-'a']++;
    }
    vector<ll> vis(n);
    // dbg(val)
    
    // dbg(newfreq)
    for (ll i = 0; i < n; i++)
    {
        if(newfreq[a[i]-'a']>0 || a[i] == b[i]){
            vis[i] = 1;
        }
    }
    // dbg(vis)
    ll cnt = 0;
    ll currans = 0;
    for (ll i = 0; i < n; i++)
    {
        if(vis[i] == 1){
            cnt++;
        }
        else{
            currans += calc(cnt);
            cnt = 0;
        }
    }
    currans += calc(cnt);
    ans = max(ans,currans);
    

    
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
