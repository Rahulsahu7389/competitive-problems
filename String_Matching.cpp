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
const ll mod = 1e9 + 7;

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
// template<typename T>
// T mod(T a){ return (a<0)? -a : a; }




int add(int a, int b){
    int res = (a + b)%mod;
    if(res<0){
        res += mod;
    }
    return res;
}
int mul(int a , int b){
    int res = (a*1LL*b)%mod;
    if(res<0){
        res += mod;
    }
    return res;
}
int power(int x,int n){
  int pro = 1;
  while(n!=0){
    if(n%2==1) pro = mul(x,pro);
    x = mul(x,x);
    n /= 2;
  }
  return pro;
}

const int N = 1e6+3;
int base = 30;
int pw[N];
int inv[N];


void precalc(){
    pw[0] = 1;
    for (int i = 1; i < N; i++)
    {
        pw[i] = mul(pw[i-1],base);
    }
    int pw_inv = power(base,mod-2);
    inv[0] = 1;
    for (int i = 1; i < N; i++)
    {
        inv[i] = mul(inv[i-1],pw_inv);
    }
    
    
}


class Roll{
    public:
    vector<int> Hash;
    int n;
    Roll(string &s){
        n = s.length();
        Hash.assign(n+1,0);
        build(s);
    }
    void build(string &s){
        
        for (ll i = 0; i < n; i++)
        {
            Hash[i] = add((i==0)?0:Hash[i-1],mul(pw[i],s[i]-'a' + 1));
        }
        
    }
    int gethash(int x,int y){
        int res = add(Hash[y],(x==0)?0:-Hash[x-1]);
        res = mul(res,inv[x]);
        return res;
    }

};

void solve(){
   //your code starts from here
   precalc();
   string s,tar;
   cin>>s;
   cin>>tar;
   int n = s.length();
   Roll s1(s);
//    Roll s2(tar);
//    int tarval = s2.gethash(0,tar.length()-1);
//    int r = tar.length()-1;
//    int l = 0;
//    ll ans =0;
//    while (r<n)
//    {
//     ll val = s1.gethash(l,r);
//     if(val == tarval) ans++;
//     l++;
//     r++;
//    }
//    cout<<ans<<endl;
    cout<<s1.gethash(0,1)<<endl;
   

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
