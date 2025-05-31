#include "bits/stdc++.h" 
using namespace std; 

#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++) 
#define FORLL(a, c) for (long long(a) = 0; (a) < (c); (a)++) 
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--) 
#define INF 1000000000000000003 
typedef long long int ll; 
typedef vector<int> vi; 
typedef pair<int, int> pi; 
#define F first 
#define S second 
#define pb push_back 
#define pob pop_back 
long long modl(ll a){
  if(a<0){return -a;}
  return a;
}

int modl(int a){
  if(a<0){return -a;}
  return a;
}
bool ans = false;

void fun(ll csum , vector<ll>&arr,ll idx,ll n){
    if(idx == n){
        if(csum%3== 0 && csum!=0){
            ans = true;
            // cout<<csum<<endl;
        }
        
        return;
    }
    fun(csum+arr[idx],arr,idx+1,n);
    fun(csum,arr,idx+1,n);

}


void solve(){
  //your code starts from here
//   4
// 1 5 1 5
// 2
// 3 3
  ans = false;
  ll n;
  cin>>n;
  vector <ll> arr(n);
  
  for (ll i = 0; i < n; i++)
  {
    cin>>arr[i];
  }
//   fun(0,arr,0,n,ans);

  if(n==1){
    if(arr[0]%3==0){
        cout<<"YES"<<endl;
        return;
    }
    else{
        cout<<"NO"<<endl;
        return;
    }
  }
  ll idx = 0;
  ll csum = 0;
  fun(csum,arr,idx,n);
  if(ans ==true){
    cout<<"YES"<<endl;
    return;
  }
  cout<<"NO"<<endl;
  


}
int main() 
{ 
    // ios::sync_with_stdio(0); 
    // cin.tie(0); 
    ll T; 
    cin >> T; 
    while (T--) { 
        solve(); 
    } 
    return 0; 
} 