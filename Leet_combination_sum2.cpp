class Solution {
public:
    void fun(vector<vector<int>>&ans ,int idx , int target , int cs ,int n,vector<int>cdt,vector<int>&params){
            if(idx == n){
                if(cs == target && find(ans.begin(),ans.end(),params)==ans.end()){
                    ans.push_back(params);
                }
                return;
            }
            if(cs>target){
                return;
            }

            params.push_back(cdt[idx]);
            fun(ans,idx+1,target,cs+cdt[idx],n,cdt,params);
            params.pop_back();
            int start = idx;
            idx++;
            while(idx<n && cdt[idx]==cdt[start]){
                idx++;
            }
            fun(ans,idx,target,cs,n,cdt,params);//idx already plus hai
        }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> params;
        vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
        fun(ans,0,target,0,candidates.size(),candidates,params);
        return ans;
    }
};