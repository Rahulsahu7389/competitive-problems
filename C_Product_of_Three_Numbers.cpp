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
//    vector<ll> v;
    map<ll,ll> mp;
   ll x = n;
   ll totalcnt = 0;
    for (int i = 2; i*i <=n; i++)
    {
        while(n%i == 0){
            // cout<<i<<endl;
            totalcnt++;
            mp[i]++;
            n /= i;
        }
    }

    if(n!=1){
        // cout<<n<<endl;
        // v.pb(n);
        mp[n]++;
        totalcnt++;
    }
    // dbg(mp)
    if(mp.size()==0 ){
        cout<<"NO\n";
    }
    else if(mp.size()==1){
        if(totalcnt<=5){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
            auto it = mp.begin();
            ll val = (*it).first;
            cout<<(val)<<" "<<val*val<<" "<<(x/(val*val*val))<<endl;
        }
    }
    else if(mp.size() ==2){
        if(totalcnt<4){
            cout<<"NO\n";
            
        }
        else{
            cout<<"YES\n";
            ll temp = x;
            for(auto val:mp){
                temp /= val.first;
                cout<<val.first<<" ";
            }
            cout<<temp<<endl;
        }
    }
    else if(mp.size()>=3){
        cout<<"YES\n";
        ll cnt = 0;
        ll temp = x;
        for(auto val:mp){
            if(cnt==2){
                break;
            }
            cout<<val.first<<" ";
            temp /= val.first;
            cnt++;
        }
        cout<<temp<<endl;
    }

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
