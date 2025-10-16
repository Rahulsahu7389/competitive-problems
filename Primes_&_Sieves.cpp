#include<bits/stdc++.h>
using namespace std;

int find_prime1(int n){
    for (int i = 2; i < n; i++)
    {
        bool flag = true;
        for (int j = 2; j < i; j++)
        {
            if(i%j == 0){
                flag = false;
            }
        }
        if(flag){
            cout<<i<<endl;
        }
        
    }
    
}
int find_prime2(int n){
    for (int i = 2; i <=n; i++)
    {
        bool flag = true;
        for (int j = 2; j*j <= i; j++)
        {
            if(i%j == 0){
                flag = false;
            }
           
        }
        if(flag){
            cout<<i<<endl;
        }
        
    }
    
}
void seives1(int n){
    vector<bool> prime(n+1,true);
    for (int i = 2; i <=n; i++)
    {
        if(prime[i]){
            for (int j = i*2; j <=n; j+=i)//start from its double as it would always divide itself
            {
                if((j%i==0)){
                    prime[j] = false;
                }
            }
        }
        
    }
    for (int i = 2; i <=n; i++)
    {
        if(prime[i]){
            cout<<i<<endl;
        }
    }
    
    
}

void seives2(int n){//good for only generating the sieves array
    vector<bool> prime(n+1,true);
    for (int i = 2; i*i <=n; i++)
    {
        if(prime[i]){
            for (int j = i*i; j <=n; j+=i)//start from its square as other are already done
            {
                if((j%i==0)){
                    prime[j] = false;
                }
            }
        }
        
    }
    for (int i = 2; i <=n; i++)
    {
        if(prime[i]){
            cout<<i<<endl;
        }
    }
}

void primeFactorisation(int n){
    for (int i = 2; i*i <=n; i++)
    {
        while(n%i == 0){
            cout<<i<<endl;
            n /= i;
        }
    }
    
    if(n!=1){
        cout<<n<<endl;
    }
}

int main(){
    // find_prime1(20);
    // find_prime2(20);
    // seives1(20);
    // seives2(20);
    primeFactorisation(120);
    return 0;
}