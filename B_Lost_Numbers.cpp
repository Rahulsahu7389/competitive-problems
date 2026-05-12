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
   ll n = 6;
   vector<ll> v = {15,23,42};
   vector<ll> num = {4,8,15,16,23,42};
   vector<ll> temp;
   for (ll i = 0; i < 4; i++)
   {
    cout<<"? "<<i+1<<" "<<i+2<<endl;
    fflush(stdout);
    ll st;
    cin>>st;
    temp.push_back(st);
   }

   vector<ll> ans(6);
   ll idx =-1;
   ll tempid =-1;
   for(auto val:v){
    bool ok = false;
    for (ll i = 0; i < temp.size()-1; i++)
    {
        if(temp[i]%val == 0 && temp[i+1]%val == 0){
            idx = i+1;//for answer
            tempid = i;//for temp
            ans[idx] = val;
            dbg(idx,tempid,val)
            ok = true;
            break;
        }
    }
    if(ok) break;
    
   }
   if(idx == -1){
    ll m = temp[temp.size()-1];
    if(m%23==0){
        idx = temp.size();
        tempid = idx-1;
        ans[idx] = 23;
    }
    else if(m%42==0){
        idx = temp.size();
        tempid = idx-1;
        ans[idx] = 42;
    }
   }
   
   
   
   ll val = ans[idx];
   ll id = idx+1;
   ll temp2 = tempid + 1;
   while(id<5 && temp2<temp.size()){
    ll sum = temp[temp2]/val;
    temp2++;
    ans[id] = sum;
    id++;
    val = sum;
   }
//    dbg(idx)
   val = ans[idx];
   id = idx-1;
   temp2 = tempid;
   while(id>=0 && temp2>=0){
    // dbg(id,temp2)
    ll sum = temp[temp2]/val;
    temp2--;
    ans[id] = sum;
    id--;
    val = sum;
   }
//    dbg("here")
   
   set<ll> st;
   for (ll i = 0; i < 5; i++)
   {
    st.insert(ans[i]);
   }
   for(auto cal:num){
    if(st.count(cal)==0){
        ans[5] = cal;
        break;
    }
   }
   cout<<"! ";
   for(auto cal:ans){
    cout<<cal<<" ";
   }
   cout<<endl;


   
   
   
}

int main() 
{ 
    // ios::sync_with_stdio(0); 
    // cin.tie(0); 
    // ll T; 
    // cin >> T; 
    // while (T--) { 
        solve(); 
    // } 
    return 0; 
}
