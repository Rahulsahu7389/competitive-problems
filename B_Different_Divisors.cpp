/*
approach - we know that two fators 1 and the number itself so we now try to find the numbers with 1+d iss just bda prime to keep it min
similarly let the previous number is a so now for next use a + d isse just bda prime number 
*/

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
    // your code starts from here
    ll d;
    cin >> d;

    ll a,b;
    for (ll i = 1+d; ; i++)
    {
        ll cnt = 0;
        for (ll j = 2; j*j<= i; j++)
        {
            //checking prime or not
            if(i%j==0){
                cnt++;
            }
        }
        if(cnt == 0){
            //its a prime number 
            // cout<<"ran"<<endl;
            a = i;
            break;
        }
        
    }
    for (ll i = a+d; ; i++)
    {
        ll cnt = 0;
        for (ll j = 2; j*j<= i; j++)
        {
            if(i%j==0){
                cnt++;
            }
        }
        if(cnt == 0){
            //its a prime number 
            b = i;
            break;
        }
        
    }

    cout<<min(a*b,a*a*b)<<endl;
    

    
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
/*
###########my tle getting solutions in one i used sieves and map to store the number with factors greater and equal to 4 and their factors in map
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

vector <ll> v(10001,1);
unordered_map <ll , vector<ll>> m;

void solve(){
  //your code starts from here
  ll d;
  cin>>d;

  for (ll i = 1; i < 10001; i++)
  {
    ll mn = 1e9;
    if(v[i]>=4){
        for (ll j = 1; j < m[i].size(); j++)
        {
            mn = min(modl(m[i][j]-m[i][j-1]),mn);
        }
        if(mn >=d){
            cout<<i<<endl;
            return;
        }
    }
  }
  
  

}
int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 

    
    for (ll i = 2; i*i < 10001; i++)
    {   
        for (ll j = i; j <10001; j+=i)
        {
            if(j%i==0){
                v[j]++;
                if(m.find(j)==m.end()){
                    m[j] = {1,i};
                }
                else{
                    m[j].pb(i);
                }
            }
        }
        
    }
    




    ll T; 
    cin >> T; 
    while (T--) { 
        solve(); 
    } 
    return 0; 
} 


##########method 2 but got the tle 
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

vector<ll> v(10001, 1);
// unordered_map <ll , vector<ll>> m;

void solve()
{
    // your code starts from here
    ll d;
    cin >> d;

    for (ll i = 2; i < 10001; i++)
    {
        ll mn = 1e9;
        ll prev = 1;
        ll n = i;
        if (v[i] >= 4)
        {

            for (ll j = 2; j * j <= n; j++)
            {
                while (n % j == 0)
                {

                    mn = min(modl(j - prev), mn);
                    prev = j;
                    n /=j;
                }
            }
            if (n != 1)
            {
                mn = min(modl(n - prev), mn);
            }
            if (mn >= d)
            {
                cout << i << endl;
                return;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (ll i = 2; i * i < 10001; i++)
    {
        for (ll j = i; j < 10001; j += i)
        {
            if (j % i == 0)
            {
                v[j]++;
                // if(m.find(j)==m.end()){
                //     m[j] = {1,i};
                // }
                // else{
                //     m[j].pb(i);
                // }
            }
        }
    }

    ll T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}



*/
