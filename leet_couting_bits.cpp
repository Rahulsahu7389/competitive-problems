//brute force approach without dp
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0;i<=n;i++){
            int value = __builtin_popcount(i);
            ans.push_back(value);

        }
        return ans;
    }
};

//with dp
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1,0);//dp[i] - it is the number of 1 bits in i
        dp[0] = 0;
        int offset = 1;
        int newoffset = offset*2;
        for(int i = 1;i<=n;i++){
            if(i == newoffset){
                offset = newoffset;
                newoffset *= 2;

            }
            dp[i] += 1 + dp[i - offset];
        } 
        return dp;

    }
};