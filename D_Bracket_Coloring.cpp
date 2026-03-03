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
   string v;
   cin>>v;
   ll cnto = 0;
   ll cntc = 0;
   for (ll i = 0; i < n; i++)
   {
    if(v[i] == '('){
        cnto++;
    }
    else{
        cntc++;
    }
   }
   if(cntc != cnto){
    cout<<-1<<endl;
    return;
   }
   stack<pair<char,ll>> st;
   vector<ll> ans(n);
   ll temp = 0;
   bool flag = false;
   for (ll i = 0; i < n; i++)
   {
    char t = v[i];
    if(st.empty()){
        st.push({t,i});
        ans[i] = 1;
        // dbg(i,"push")
    }
    else{
        // dbg(i,"pop")
        if(t == ')' && st.top().first == '('){
            ans[i] = 1;
            flag = true;
            st.pop();
        }
        else{
            st.push({t,i});
            ans[i] = 1;
        }
    }



   }
   ll para = 1;
   if(flag) temp++;
   if(!st.empty()) temp++;
   if(temp == 1){
    para = 1;
   }
   else{
    para = 2;
   }
   while (!st.empty())
   {
    flag = true;
    auto val = st.top();
    ans[val.second] = para;
    st.pop();
   }
   cout<<temp<<endl;
   
   for(auto val:ans){
    cout<<val<<" ";
   }
   cout<<endl;
   
   

   
}
void solve(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll cnto = 0;
    ll cntc = 0;
    for (ll i = 0; i < n; i++)
    {
        if(s[i]=='('){
            cnto++;
        }
        else{
            cntc++;
        }
    }
    if(cnto!=cntc){
        cout<<-1<<endl;
        return;
    }

    vector<ll> ans(n);
    ll balance = 0;
    bool flag1 = true;
    bool flag2 = true;
    ll sm = 0;
    for (ll i = 0; i < n; i++)
    {
        if(s[i] == '('){
            balance++;
        }
        else{
            balance--;
        }
        if(balance >0){
            if(flag1){
                flag1 = false;
                sm++;
            }
            ans[i] = 1;
        }
        else if(balance <0){
            if(flag2){
                flag2 = false;
                sm++;
            }
            ans[i] = 2;

        }
        else{
            if(i!=0){
                if(ans[i-1]==1){
                    ans[i] = 1;
                }
                else{
                    ans[i] = 2;
                }
            }
        }
    }
    cout<<sm<<endl;
    for(auto val:ans){
        if(sm == 1 && val==2){

            cout<<val-1<<" ";
        }
        else{

            cout<<val<<" ";
        }
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
