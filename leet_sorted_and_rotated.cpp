class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> v = nums;
        
        sort(v.begin(),v.end());
        for(int i = 1;i<=v.size();i++){
            vector<int> b = nums;
            for(int j = 0;j<v.size();j++){
                b[j] =  v[(j+i)%v.size()];
            }
            if(b ==nums ){
                return true;
            }
        }
        return false;
    }
};