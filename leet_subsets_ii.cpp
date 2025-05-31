// #this is of shraddha maam

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

        int idx = i +1;
        while((idx < nums.size()) && (nums[idx]== nums[idx-1])){
            idx++;
        }
        getSub(nums , ans,  idx, grand);// exclusion

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector <int>> grand;
        vector <int> ans;
        int i = 0;
        sort(nums.begin(),nums.end());
        getSub(nums , ans,i,grand);
        return grand;
        
    }
};
// ###approach 2 by me
class Solution {
public:
    void fun(vector<vector<int>>&ans , vector<int> nums , int i , int n,vector<int>&curr){
        if(i==n){
            if(find(ans.begin(),ans.end(),curr)==ans.end()){
                ans.push_back(curr);
            }
            return;
        }
        curr.push_back(nums[i]);
        fun(ans,nums,i+1,n,curr);
        curr.pop_back();
        fun(ans,nums,i+1,n,curr);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector <int> curr;
        fun(ans,nums,0,n,curr);
        return ans;
    }
};