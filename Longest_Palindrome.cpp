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
const int mod = 1e9 + 7;

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



int add(int a , int b){
    int res= (a + b)%mod;
    if(res<0){
        res += mod;
    }
    return res;
}

int mul(int a ,int b){
    int res = (a*1LL*b)%mod;
    if(res<0){
        res += mod;
    }
    return res;
}


int power(int x,int n){
  int pro = 1;
  while(n!=0){
    if(n%2==1) pro = mul(pro,x);
    x = mul(x,x);
    n /= 2;
  }
  return pro;
}

const int N = 1e6+3;
int base = 30;
int pw[N];
int inv[N];

void precalculate(){
    pw[0] = 1;
    for (int i = 1; i < N; i++)
    {
        pw[i] = mul(pw[i-1],base);
    }
    int invpw = power(base,mod-2);
    inv[0] = 1;
    for (int i = 1; i < N; i++)
    {
        inv[i] = mul(inv[i-1],invpw);
    }
    
    
}
class RollingHash{
    public:
    vector<int> h;
    int n;
    RollingHash(string &s){
        n = s.length();
        h.assign(n+1,0);
        build(s);

    }
    void build(string &s){
        for (int i = 0; i < n; i++)
        {
            h[i] = add((i==0)?0:h[i-1],mul(s[i]-'a'+1,pw[i]));
        }
        
    }
    int gethash(int x,int y){
        int res = add(h[y],(x==0)?0:-h[x-1]);
        res = mul(res,(x==0)?1:inv[x]);
        return res;
    }
};

void solve(){
   //your code starts from here
   precalculate();
   string s;
   cin>>s;
   int n = s.length();
   string temp = s;
   reverse(all(temp));
   RollingHash r1(s),r2(temp);

   auto valid = [&](ll mid)->pair<int,int> {
    ll nl = 0;
    ll nr = mid-1;
    while(nr<n){
        int val = r1.gethash(nl,nr);
        int rr = n-nl-1;
        int rl = n-nr-1;
        int val2 = r2.gethash(rl,rr);
        // if(mid == 3) dbg(val,val2,nl,nr,rl,rr);
        if(val == val2) return {nl,nr};
        nl++;
        nr++;
    }
    return {-1,-1};
   };

   int l = 1;
   int r = (n+1)/2;
   int bestlen = 1;
   int besta = 0;
   //for even length
   while(l<=r){
    ll mid = (l+r)/2;
    int len = 2*mid;
    auto it = valid(2*mid);//making it even
    bool ok = true;
    if(it.first==-1 || it.second == -1) ok = false;
    if(ok){
        if(len>bestlen){
           besta = it.first;
           bestlen = len;
        }
        l = mid+1;
    }
    else r = mid-1;
   }
   l = 0;
   r = n;
   while(l<=r){
    ll mid = (l+r)/2;
    int len = 2*mid-1;
    auto it = valid(2*mid-1);//making it odd
    bool ok = true;
    if(it.first==-1 || it.second == -1) ok = false;
    if(ok){
        if(len>bestlen){
           besta = it.first;
           bestlen = len;
        }
        l = mid+1;
    }
    else r = mid-1;
   }
   cout<<s.substr(besta,bestlen)<<endl;
   
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
