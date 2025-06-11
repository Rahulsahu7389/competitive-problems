//hint from striver and rest done by me
#include <bits/stdc++.h> 

int fun(int idx ,vector<int> &nums,vector<int> &dp ){
    if(idx == 0) return nums[idx];
    if(idx<0) return 0;
    if(dp[idx]!=0) return dp[idx];

    dp[idx] = max((nums[idx] + fun(idx-2,nums,dp)),fun(idx-1,nums,dp));
    
    return dp[idx];

}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    vector<int>dp(nums.size(),0);//dp[i] - it is the max non adjacent element sum till index i
    dp[0] = nums[0];
    return fun(nums.size()-1,nums,dp);

}