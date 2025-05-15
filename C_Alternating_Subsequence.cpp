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


void solve(){
  //your code starts from here
  ll n;
  cin>>n;
  vector <ll> v(n);
  vector <ll> arr;
  for (ll i = 0; i < n; i++)
  {
    cin>>v[i];
  }
  ll ans = 0;
  for (ll i = 0; i < n; i++)
  {
    ll sum = -2e18;
    ll j = i;
    while((j<n) && ((v[j]>0 && v[i]>0) || (v[j]<0 && v[i]<0)) ){
        sum = max(sum,v[j]);
        j++;
    }
    ans += sum;
    i = j -1;
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


///this code gave out of bound error and above code is the simplest way to write how i wrote it complexively
/*
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


void solve(){
    //your code starts from here
    ll n;
    cin>>n;
    vector <ll> v(n);
    vector <ll> arr;
    for (ll i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    
    for (ll i = 0; i <n; i++)
    {
        if(i == n-1){
            arr.pb(v[i]);
            break;
        }
        ll x = v[i];
        if(x<0){
            ll sum = x;
            i++;
            x = v[i];
            while(x<0){
                
            sum = max(sum,x);
            i++;
            x = v[i];
        }
        arr.pb(sum);
        i--;
    }
    else{
        ll sum = x;
        i++;
        x = v[i];
        while(x>0){
            
        sum = max(sum,x);
        i++;
        x = v[i];
    }
    arr.pb(sum);
    i--;
}
}
ll ans = 0;
for (auto val: arr){
    // cout<<val<<endl;
    ans+= val;
}
cout<<ans<<endl;
//   ll ans = accumulate(arr.begin(),arr.end(),0);


//   cout<<accumulate(arr.begin(),arr.end(),0)<<endl;



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
*/