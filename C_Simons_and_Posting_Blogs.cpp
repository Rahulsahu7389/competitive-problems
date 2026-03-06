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

bool cust(vector<ll> &a , vector<ll> &b){
    if(a[0]!=b[0]){
        return a[0]<b[0];
    }
    int i = 1;
    int j = 1;
    while(i<a.size() && j<b.size() && a[i]==b[j]){
        i++;
        j++;
    }
    if(i == a.size()){
        return a.size() < b.size();
    }
    else if(j == b.size()){
        return b.size() < a.size();

    }
    return a[i]<b[j];

}


// Global array to track visited elements. 
// Much faster than allocating a vector of size 10^6 inside solve()
bool visited[1000005];

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> v(n);
    
    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        vector<int> temp(d);
        for (int j = 0; j < d; j++) {
            cin >> temp[j];
        }
        reverse(temp.begin(), temp.end());
        
        // Deduplicate elements within this specific blog
        set<int> seen;
        for (int x : temp) {
            if (seen.find(x) == seen.end()) {
                v[i].push_back(x);
                seen.insert(x);
            }
        }
    }
    
    vector<int> Q;
    
    // Greedily build the sequence
    while (true) {
        vector<int> best_U;
        bool found_any = false;
        
        // Find the lexicographically smallest remaining sequence
        for (int i = 0; i < n; i++) {
            vector<int> current_U;
            
            // Get unvisited elements of the current blog
            for (int x : v[i]) {
                if (!visited[x]) {
                    current_U.push_back(x);
                }
            }
            
            // If it has elements, compare it to our best so far
            if (!current_U.empty()) {
                if (!found_any || current_U < best_U) {
                    best_U = current_U;
                    found_any = true;
                }
            }
        }
        
        // If all blogs are fully visited, we're done
        if (!found_any) break;
        
        // Append the best sequence to our answer and mark as visited
        for (int x : best_U) {
            Q.push_back(x);
            visited[x] = true;
        }
    }
    
    for (int x : Q) {
        cout << x << " ";
    }
    cout << "\n";
    
    // Clean up only the indices we used in the global visited array for the next test case
    // This prevents Time Limit Exceeded (TLE)
    for (int x : Q) {
        visited[x] = false;
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
