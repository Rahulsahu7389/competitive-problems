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
   ll n ,m;
   cin>>n>>m;
   vector<ll> totalchar(26);
   vector<ll> totalcost(26);
   vector<vector<ll>> eachchar(n,vector<ll> (26));
   for (ll i = 0; i < n; i++)
   {
    string s;
    cin>>s;
    
    ll len = s.length();
    for (ll j = 0; j < len; j++)
    {
        totalchar[s[j]-'A']++;
        eachchar[i][s[j]-'A']++;
        totalcost[s[j]-'A'] += m;
    }
    
   }
   for (ll i = 0; i < n; i++)
   {
    vector<ll> tempchar(26);
    vector<ll> tempcost(26);
    //removing the lost items char and cost
    for (ll j = 0; j < 26; j++)
    {
        tempchar[j] = totalchar[j] - eachchar[i][j];
        tempcost[j] = totalcost[j] - eachchar[i][j]*m;
    }
    // dbg(tempchar,tempcost)
    //check if we can make the 1 lost item
    bool cont = false;
    for (ll j = 0; j < 26; j++)
    {   
        // if(tempchar[j]>=eachchar[i][j]){

        //     tempchar[j] -= eachchar[i][j];
        // }
        // else{
        //     cout<<-1<<endl;
        //     return;
        // }
        if(tempcost[j]>=eachchar[i][j]){

            tempcost[j] -= eachchar[i][j];
        }
        else{
            cout<<-1<<" ";
            cont = true;
            break;
        }
    }
    if(cont){
        continue;
    }
    // dbg(i,tempchar,tempcost)
    ll ans = 1e15;
    for (ll j = 0; j < 26; j++)
    {
        if(tempchar[j]>0){
            ll val = (tempcost[j]/tempchar[j]);
            ans = min(val,ans);
        }
    }
    cout<<ans<<" ";
    
    
   }
   cout<<endl;
   
   
   
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
