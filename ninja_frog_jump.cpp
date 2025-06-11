#include <bits/stdc++.h> 
#include<iostream>
#include<vector>
using namespace std;

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1,INT_MAX);//dp[i] - it is the min energy required to go from idx 1 to idx i
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = abs(heights[0] - heights[1]);
    for(int i=3;i<=n;i++){
        for(int j = 1;j<=2;j++){
            dp[i] = min((dp[i-j]+abs(heights[i-1] - heights[i-j-1])),dp[i]);
        }
    }
    return dp[n];

}

/*approach 2 recursive code*/
// vector<int> dp(100001,INT_MAX);//dp[i] - it is the min energy required to go from idx 1 to idx i
int fun(int n,vector<int> &heights,vector<int>&dp){
    if(dp[n]!=INT_MAX){
        return dp[n];
    }
    if(n == 1 || n == 0 || n==2) return dp[n];
    for(int j = 1;j<=2;j++){
        // cout<<" n is "<<n<<endl;
        dp[n] = min((fun(n-j,heights,dp)+abs(heights[n-1] - heights[n-j-1])),dp[n]);
    }
    return dp[n];

}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1,INT_MAX);//dp[i] - it is the min energy required to go from idx 1 to idx i
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = abs(heights[0] - heights[1]);
    // for(int i=3;i<=n;i++){
    //     for(int j = 1;j<=2;j++){
    //         dp[i] = min((dp[i-j]+abs(heights[i-1] - heights[i-j-1])),dp[i]);
    //     }
    // }
    // return dp[n];
    return fun(n,heights,dp);

}