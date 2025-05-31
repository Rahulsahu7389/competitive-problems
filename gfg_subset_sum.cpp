class Solution {
  public:
    void fun(vector <int> &ans , vector<int> arr , int i , int cs,int n){
        if(i == n){
            ans.push_back(cs);
            return;
        }
        fun(ans , arr, i+1 , cs+arr[i],n);
        fun(ans , arr, i+1 , cs,n);
    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        int n = arr.size();
        unordered_set <int> ans;
        vector<int> v;
        fun(v,arr,0,0,n);
        // for(auto val:ans){
        //     v.push_back(val);
        // }
        // return v;
        return v;
    }
};