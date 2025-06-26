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

bool fun(vector<ll> a , vector<ll>b , ll mid){
    if(*max_element(a.begin(),a.end())>mid){
        return false;
    }
    ll c1 = 0;//no of operations
    ll c2 = 0;///no of spaces
    for(int i =0 ; i<a.size();i++){
        if(a[i]+b[i] > mid){

            c1 += (a[i]+b[i] - mid);
        }
        else{

            c2 += (mid - a[i] - b[i])/2;
        }
    }
    if(c1>c2){
        return false;
    }
    return true;
}


void solve(){
  //your code starts from here
  ll n;
  cin>>n;
  vector<ll> a(n);
  vector<ll> b(n);
  for (ll i = 0; i < n; i++)
  {
    cin>>a[i];
  }
  for (ll i = 0; i < n; i++)
  {
    cin>>b[i];
  }
  ll st = *min_element(a.begin(),a.end());
  ll end = 2e9;
  ll ans = -1;
//   cout<<"end is : "<<end<<endl;
  while(st<=end){
    ll mid = st + (end - st)/2;
    bool val = fun(a,b,mid);
    // cout<<mid <<" "<<val<<endl;
    if(val){
        ans = mid;
        end = mid -1;
    }
    else{
        st = mid + 1;
    }
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