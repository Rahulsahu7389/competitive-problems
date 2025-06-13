class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = 0;
        for(int i = 0 ;i<31;i++){
            if(((1<<i)&start) !=0){//bit is set
                // cout<<"upper\n";
                if(((1<<i)&goal) ==0){
                    ans++;
                }
            }
            else{//bit is not set
                // cout<<"lower\n";
                if(((1<<i)&goal) != 0){
                    ans++;
                }
            }
        }
        return ans;
    }
};