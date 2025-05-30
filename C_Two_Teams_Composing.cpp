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
//   cout<<"inside\n";
    ll n;
    cin>>n;
    vector <ll> v(n+1,0);
    ll cnt = 0;
    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin>>a;
        // cout<<a<<endl;
        if(v[a]==0){
            cnt++;
        }
        v[a]++;
    }
    if(n==1){
        cout<<0<<endl;
        return;
    }
    sort(v.rbegin(),v.rend());
    if(v[0] == 1){
        cout<<1<<endl;
        return;
    }

    //a==b
    if(cnt == v[0]){
        //one is virtually not present
        cout<<(cnt-1)<<endl;
        return;
    }
    else if(cnt>v[0]){
        cout<<min(cnt,v[0])<<endl;
        return;
    }
    else{
        cout<<min(cnt,v[0])<<endl;
        return;
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