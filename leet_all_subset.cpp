//recusive approach
class Solution {
public:

    void getSub(vector <int> &nums , vector<int>& ans, int i,vector<vector<int>>& grand){
        if(i == nums.size()){
            grand.push_back({ans});
            return;
        }
        ans.push_back(nums[i]);
        getSub(nums , ans, i+1,grand);
        ans.pop_back();
        getSub(nums , ans,  i+1, grand);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector <int>> grand;
        vector <int> ans;
        int i = 0;
        getSub(nums , ans,i,grand);
        return grand;
        
    }
};

//bit manipulation method 
class Solution {
public:

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        for(int i = 0;i<((1<<nums.size()));i++){
            vector<int> temp;
            for(int j = 0;j<nums.size();j++){
                if(((1<<j)&i)!=0){
                    temp.push_back(nums[j]);
                }
            }
            ans.push_back(temp);
        }
        // ans.push_back(nums);
        return ans;
        
    }
};