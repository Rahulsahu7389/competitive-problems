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
   ll n,q;
   cin>>n>>q;
   vector<ll> v(n);
   vector<pair<ll,ll>> unique;
   set<ll> s;
   for (ll i = 0; i < n; i++)
   {
    cin>>v[i];
    if(s.count(v[i])==0){
      unique.pb({v[i],i});
    }
    s.insert(v[i]);
   }
//    dbg(v)
   vector<ll> query(q);
  //  dbg(unique)

   for (ll i = 0; i < q; i++)
   {
    ll t;
    cin>>t;
    
    vector<pair<ll,ll>> temp(unique.size());

    //finding in unique the element
    ll idx;
    // ll val;
    ll outeridx ;
    for (ll k = 0; k < unique.size(); k++)
    {
      if(unique[k].first == t){
        idx = unique[k].second;
        outeridx = k;
        break;
      }
    
    }
    // dbg(idx,outeridx)
    cout<<(idx+1)<<" ";
    ll ind = 1;
    temp[0] = {unique[outeridx].first,0};
    for (ll j = 0; j < unique.size(); j++)
    {
      if(outeridx!=j){
        if(unique[j].second<unique[outeridx].second){
          temp[ind] = {unique[j].first,unique[j].second + 1};
        }
        else{
          temp[ind] = {unique[j].first,unique[j].second};

        }
        ind++;
      }
    }
    unique = temp;
    // dbg(temp);
    


    

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
