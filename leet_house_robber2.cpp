class Solution {
public:
    recursion + dp- tle
    // int fun(vector<int>& nums,int idx , vector<int>& dp){
    //     if(idx ==0){
    //         return dp[0];
    //     }
    //     if(idx<0) return 0;
    //     if(dp[idx]!=0) return dp[idx];

    //     dp[idx] = max((nums[idx]+fun(nums,idx-2,dp)),fun(nums,idx-1,dp));
    //     return dp[idx];
    // }
    iterative code submitted
    // int fun(vector<int>& nums){
    //     int n = nums.size();
    //     // vector<int> dp(n,0);
    //     dp[0] = nums[0];
    //     dp[1] = max(nums[0], nums[1]);

    //     int var1 = nums[0];
    //     int var2 = max(nums[0], nums[1]);
        
    //     for(int i = 2;i<n;i++){
    //         dp[i] = max(dp[i-1],(nums[i] + dp[i-2]));
    //         var2 = var1;
    //         var1 = dp[i];
    //     }
    //     return dp[n-1];
    // }
    iterative and space optimisation
    int fun(vector<int>& nums){
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return  max(nums[0], nums[1]);

        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);
        
        
        for(int i = 2;i<n;i++){
            int ans = max(prev1,(nums[i] + prev2));
            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        if(nums.size() == 2){
            return max(nums[0],nums[1]);
        }
        // vector<int> dp(nums.size()+1,0);//dp[i] - it is the max money stolen till index i
        // vector<int> dp2(nums.size()+1,0);//dp[i] - it is the max money stolen till index i
        // vector<int> temp;
        // for(int i = 1;i<nums.size();i++){
        //     temp.push_back(nums[i]);
        // }
        // dp[0] = nums[0];
        // dp2[0] = temp[0];
        vector<int> v1(nums.begin()+1,nums.end());
        vector<int> v2(nums.begin(),nums.end()-1);
        return max(fun(v1),fun(v2));
    }
};