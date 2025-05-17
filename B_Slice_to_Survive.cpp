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
  ll r , c , a, b;
  cin>>r>>c>>a>>b;
  ll noBox = r*c;
  
  if((a==r && b == c) && noBox==1){
        cout<<1<<endl;
        return;
    }
  ll ans = 0;
  //   r--;c--;a--;b--;
  
  while(true){
    ll mx = -1e9;
      if((a==r && b == c) && noBox==1){
          break;
        }
        ll order;
    //top
    if(((a-1)*c)>mx){
        // cout<<"top"<<endl;
        mx = max(mx , ((a-1)*c));
        order = 1;
    }
    //bottom
    if(((r-a)*c)>mx){
        // cout<<"bottom"<<endl;

        mx = max(mx , ((r-a)*c));
        order = 2;
    }
    //left
    if(((b-1)*r)>mx){
        // cout<<"left"<<endl;
        mx = max(mx , ((b-1)*r));
        order = 3;
    }
    //right
    if(((c - b)*r)>mx){
        // cout<<"rght"<<endl;
        mx = max(mx , ((c-b)*r));
        order = 4;
    }

    if(order==1){
        // cout<<"top cut"<<endl;
        //top cut
        r= (r - a)+1;
        ans++;
    }
    if(order==2){
        // cout<<"bottom cut"<<endl;
        r= (a -1 )+1;
        ans++;
    }
    if(order == 3){
        // cout<<"left cut"<<endl;
        c = (c-b)+1;
        ans++;
    }
    if(order == 4){
        // cout<<"right cut"<<endl;
        c = b;
        ans++;
    }

    // cout<<"value of a and b: before"<<a<<" "<<b<<endl;
    // cout<<"value of r and c: before"<<r<<" "<<c<<endl;
    a = (r+1)/2;
    b = (c+1)/2;
    noBox = r*c;
    // cout<<"value of a and b:"<<a<<" "<<b<<endl;

    


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