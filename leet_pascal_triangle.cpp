//my approach  accepted
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1){
            return {{1}};
        }
        if(numRows == 2){
            return {{1},{1,1}};
        }
        
        vector<vector<int>> ans = {{1},{1,1}};
        int idx = 1;
        for (int i = 0; i < (numRows - 2); i++)
        {
            vector<int> temp ;
            temp.push_back(1);
            for (int j = 1; j < ans[idx].size(); j++)
            {
            temp.push_back(ans[idx][j]+ans[idx][j-1]);
            }
            temp.push_back(1);
            ans.push_back(temp);
            idx++;
            
        }
        return ans;
    }
};

// #types of questions in pascals triangle by striver
/*
1.given row r and column c give the number at that point(value is : (r-1)C(c-1))
2.print the given row
3.print upto n rows(above code)
*/
//for first type
int nCr(int n , int r){
    ll res = 1;
    for(int i = 0;i<r;i++){
        res = res * (n - i);
        res = res / (i+1);
    }
    return res;
}

//type 2
//brute force - in this use the ncr function above with loop
//now optimised - in copy also
int secondtypeOptimised(){
    int ans = 1;
    print(ans);
    for (int i = 1; i < n; i++)
    {
        ans = ans*(n-i);
        ans = ans/i;
        print(ans);
    }
    
}