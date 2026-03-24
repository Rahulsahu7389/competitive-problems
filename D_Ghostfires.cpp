// #include <bits/stdc++.h>
// using namespace std;

// #define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++) 
// #define FORLL(a, c) for (long long(a) = 0; (a) < (c); (a)++) 
// #define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--) 
// typedef long long int ll; 
// typedef vector<int> vi; 
// typedef pair<int, int> pi; 
// #define all(a) a.begin(),a.end()
// #define F first 
// #define S second 
// #define pb push_back 
// #define pob pop_back 
// ll MOD = 1e9 + 7;

// // ======== DEBUG SYSTEM ========
// bool DEBUG_MODE = true;  // toggle before submission

// template<typename T> void _print(const T &x) { cerr << x; }
// template<typename T1, typename T2> void _print(const pair<T1, T2> &p) { cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}"; }
// template<typename T> void _print(const vector<T> &v) { cerr << "["; for (auto &i : v) { _print(i); cerr << " "; } cerr << "]"; }
// template<typename T> void _print(const set<T> &s) { cerr << "{"; for (auto &i : s) { _print(i); cerr << " "; } cerr << "}"; }
// template<typename T> void _print(const multiset<T> &s) { cerr << "{"; for (auto &i : s) { _print(i); cerr << " "; } cerr << "}"; }
// template<typename K, typename V> void _print(const map<K, V> &m) { cerr << "{"; for (auto &p : m) { _print(p.first); cerr << "->"; _print(p.second); cerr << " "; } cerr << "}"; }

// // Variadic template for multiple args
// void dbg_out() { cerr << "\n"; }
// template<typename Head, typename... Tail>
// void dbg_out(Head H, Tail... T) { _print(H); if(sizeof...(T)) cerr << " | "; dbg_out(T...); }

// #define dbg(...) if(DEBUG_MODE){ cerr << "[" << __LINE__ << "] " << #__VA_ARGS__ << " = "; dbg_out(__VA_ARGS__); }

// // ======== UTILITY FUNCTIONS ========
// template<typename T>
// T mod(T a){ return (a<0)? -a : a; }

// template<typename T>
// T power(T x,T n){
//   T pro = 1;
//   while(n!=0){
//     if(n%2==1) pro *= x;
//     x *= x;
//     n /= 2;
//   }
//   return pro;
// }

// // FIXED BUG 3: Added casting (ll) to temp.size() to prevent unsigned integer 
// // underflow which happens if temp is empty, causing a Segmentation Fault.
// bool isValid(string &temp, ll a, ll b, ll c) {
//     ll x = 0, y = 0, z = 0;
//     for (ll i = 0; i < (ll)temp.size() - 1; i++) 
//     {
//         if(temp[i] == temp[i+1]){
//             return false;
//         }
//         if(temp[i] == 'R') x++;
//         if(temp[i] == 'G') y++;
//         if(temp[i] == 'B') z++;
//     }
    
//     // Safety check to ensure temp is not empty before checking the back
//     if (!temp.empty()) {
//         if(temp.back() == 'R') x++;
//         if(temp.back() == 'G') y++;
//         if(temp.back() == 'B') z++;
//     }
    
//     if(x > a || y > b || z > c){
//         return false;
//     }
//     return true;
// }

// bool custom(string &a , string &b){
//     return a.length() < b.length();
// }

// void solve(){
//     ll a, b, c;
//     cin >> a >> b >> c;
//     vector<char> ch = {'R', 'G', 'B'};
//     vector<string> st;
    
//     // Your original logic to generate prefixes of length 1, 2, and 3.
//     // I added storing lengths 1 and 2 inside the loops so we don't miss short answers.
//     for (ll i = 0; i < 3; i++) {
//         string temp = "";
//         temp.pb(ch[i]);
//         if(isValid(temp, a, b, c)) st.pb(temp); 
        
//         for (ll j = 0; j < 3; j++) {
//             temp.pb(ch[j]);
//             if(isValid(temp, a, b, c)) st.pb(temp); 
            
//             for (ll k = 0; k < 3; k++) {
//                 temp.pb(ch[k]);
//                 if(isValid(temp, a, b, c)) {
//                     st.pb(temp); 
//                 }
//                 temp.pop_back();
//             }
//             temp.pop_back();
//         }
//     }

//     // FIXED BUG 1: Completely removed the `if(a>=1 && b>=1 && c>=1)` wrapper.
//     // We MUST try to greedily extend strings even if one color count is 0.

//     string ans = "";
//     ll len = 0;
    
//     // Initialize our answer with the longest valid prefix found so far (handles cases where max length < 3)
//     for (string& s : st) {
//         if ((ll)s.length() > len) {
//             ans = s;
//             len = s.length();
//         }
//     }

//     ll m = st.size();
//     for (ll i = 0; i < m; i++) {
//         string temp = st[i];
//         if(temp.size() < 3) continue; 
        
//         vector<pair<ll,ll>> val = {{a, 0}, {b, 1}, {c, 2}};
//         for (ll j = 0; j < (ll)temp.size(); j++) {
//             if(temp[j] == 'R') val[0].first--;
//             if(temp[j] == 'G') val[1].first--;
//             if(temp[j] == 'B') val[2].first--;
//         }
        
//         while(true) {
//             sort(all(val)); 
//             char t1 = temp[temp.size()-1];
//             char t2 = temp[temp.size()-3];
//             ll cntway = 0;
//             bool ok = true;
//             ll idx = -1;
            
//             for (int k = 2; k >= 0; k--) { 
//                 if(val[k].first > 0) {
//                     if(ch[val[k].second] != t1 && ch[val[k].second] != t2) {
//                         cntway++;
//                         if (idx == -1) idx = k; // Capture the highest available valid count
//                         ok = false;
//                     }
//                 }
//             }
            
//             if(ok) {
//                 break; 
//             }
            
//             if(cntway > 1) {
//                 char t3 = temp[temp.size()-2];
//                 bool pushed_t3 = false;
                
//                 // FIXED BUG 2: Only push t3 if its remaining count is strictly greater than 0!
//                 for (ll k = 0; k < 3; k++) {
//                     if(ch[val[k].second] == t3 && val[k].first > 0) {
//                         temp.push_back(t3);
//                         val[k].first--;
//                         pushed_t3 = true;
//                         break;
//                     }
//                 }
                
//                 // If t3 was out of stock, fall back to pushing the highest available valid color
//                 if (!pushed_t3) {
//                     temp.push_back(ch[val[idx].second]);
//                     val[idx].first--;
//                 }
//             }
//             else {
//                 temp.push_back(ch[val[idx].second]);
//                 val[idx].first--;
//             }
//         }
        
//         if(len < (ll)temp.length()) {
//             ans = temp;
//             len = temp.length();
//         }
//     }
    
//     cout << ans << "\n";
// }

// int main() 
// { 
//     ios::sync_with_stdio(0); 
//     cin.tie(0); 
//     ll T; 
//     cin >> T; 
//     while (T--) { 
//         solve(); 
//     } 
//     return 0; 
// }


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
   
   vector<pair<ll,char>> a = {{0,'R'},{0,'G'},{0,'B'}};
   for(auto &val:a){
    cin>>val.first;
   }

   string ans = "";int n = 0;
   while (true)
   {
    sort(a.rbegin(),a.rend());
    int pick = -1;
    for(auto j:{0,1,2}){
        if(!a[j].first)  continue;
        if(n>=1 && a[j].second == ans[n-1]) continue;
        if(n>=3 && a[j].second == ans[n-3]) continue;
        if(pick == -1){
            pick = j;
            continue;
        }
        if(n>=2 && a[pick].first == a[j].first && a[j].second == ans[n-2]){
            pick = j;
        }
    }
    if(pick == -1) break;
    ans.pb(a[pick].second); n++;
    a[pick].first--;
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
