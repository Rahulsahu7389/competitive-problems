typedef long long ll;
class Solution {
public:
    vector<vector<int>> ans;
    void fun(vector<int>candidates , int target , int cs ,int n,vector<int>&temp,int idx){
        if(idx == n){
            if(cs == target){
                ans.push_back(temp);
            }
            return;
        }
        fun(candidates,target , cs,n ,temp,idx+1);
        temp.push_back(candidates[idx]);
        if(cs + candidates[idx]<=target){
            fun(candidates,target , cs +candidates[idx],n ,temp,idx);

        }
        temp.pop_back();
        

    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        fun(candidates,target,0,candidates.size(),temp,0);
        return ans;
    }
};