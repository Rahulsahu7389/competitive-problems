//this is o(mn)*o(n+m) t.c and o(mn) space complexity approach
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<bool>>v(matrix.size(),vector<bool>(matrix[0].size(),true));

        for(int i = 0;i<matrix.size();i++){
            for(int j = 0;j<matrix[0].size();j++){
                if(matrix[i][j]==0 && v[i][j] == true){
                    v[i][j] = false;
                    for(int k = 0;k < matrix.size();k++){
                        if(v[k][j] == true && matrix[k][j]!=0){

                            matrix[k][j] = 0;
                            v[k][j] = false;
                        }
                    }
                    for(int k = 0;k <matrix[0].size() ;k++){
                        if(v[i][k] == true && matrix[i][k]!=0){

                            matrix[i][k] = 0;
                            v[i][k] = false;
                        }
                    }
                }
            }
        }
    }
};

//this one takes o(mn) t.c and o(n + m) space complexity
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // vector<vector<bool>>v(matrix.size(),vector<bool>(matrix[0].size(),true));
        vector<int> hori(matrix[0].size(),-1);
        vector<int> vert(matrix.size(),-1);

        for(int i = 0;i<matrix.size();i++){
            for(int j = 0;j<matrix[0].size();j++){
                if(matrix[i][j] == 0){
                    hori[j] = 1;
                    vert[i] = 1;
                }
            }
        }
        for(int i = 0;i<matrix.size();i++){
            for(int j = 0;j<matrix[0].size();j++){
                if(hori[j] == 1 || vert[i]==1){
                    matrix[i][j] = 0;
                }
            }
        }
    
    }
};

//t.c = O(nm) & space.c = O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col = -1;

        for(int i = 0;i<matrix.size();i++){
            for(int j = 0;j<matrix[0].size();j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    if(j!=0){
                        matrix[0][j] = 0;
                    }
                    else{
                        col = 0;
                    }
                }
            }
        }
         for(int i = 1;i<matrix.size();i++){
            for(int j = 1;j<matrix[0].size();j++){
                if(matrix[0][j]==0 || matrix[i][0] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        //if your first element zero then entire 1 row
        if(matrix[0][0] == 0){
            for(int i = 0;i<matrix[0].size();i++){
                matrix[0][i] = 0;
            }
        }
        //if col =0 then entire first column is zero
        if(col == 0){
            for(int i = 0;i<matrix.size();i++){
                matrix[i][0] = 0;
            }
        }
        
        
    
    }
};