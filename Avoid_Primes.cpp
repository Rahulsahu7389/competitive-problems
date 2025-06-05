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
long long modl(ll a)
{
    if (a < 0)
    {
        return -a;
    }
    return a;
}

int modl(int a)
{
    if (a < 0)
    {
        return -a;
    }
    return a;
}




void solve()
{
    
    ll n;
    cin >> n;
    
    if(n==2){
        cout<<"1 2"<<endl;
        return;
    }
    if(n==3){
        cout<<"3 1 2"<<endl;
        return;
    }
    if(n == 4){
        cout<<"3 2 1 4"<<endl;
        return;
    }
    if(n == 5){
        cout<<"3 2 1 5 4"<<endl;
        return;
    }
    if(n == 6){
        cout<<"3 2 1 5 4 6"<<endl;
        return;
    }
    // cout<<isPrime(4)<<endl;
    cout<<"3 2 1 5 4 ";
    bool flag = true; // for j = 6;
    
    ll i = 5;
    ll j = 7;

    while(i<=n){
        // i = j+1;
        // cout<<"yes"<<endl;
       if(flag){
        flag = false;
        if(j<=n){

            cout<<j<<" ";
        }
        
       }
       else{
        flag = true;
        if((j-1)<=n){

            cout<<(j-1)<<" ";
            j += 2;
        }
       }
       i++;
       
    }
    cout<<endl;

    
    
    

    

    // seive(n, prime, not_prime);
    // for (auto val : not_prime)
    // {
    //     cout << val << endl;
    // }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}