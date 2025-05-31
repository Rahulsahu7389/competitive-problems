class Solution {
public:
    vector <string> key = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector <string> ans;
    void fun(string digits,int idx , int n , string temp){
        if(idx == n){
            ans.push_back(temp);
            return;
        }
        for(auto val: key[digits[idx] - '0']){
            temp.push_back(val);
            fun(digits,idx+1,n,temp);
            temp.pop_back();

        }
    }
    vector<string> letterCombinations(string digits) {
        int idx = 0;
        int n = digits.length();
        if(n==0){
            return ans;
        }
        string temp = "";
        fun(digits,idx,n,temp);
        return ans;
        
    }
};