//single number 2 by me 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int count = 1;
        sort(nums.begin(),nums.end());
        int val = nums[0];
        for(int i=1; i<nums.size();i++){
            if(count<3 && val!=nums[i]){
                return val;
            }
            if(val == nums[i]){
                count++;
            }
            if(val != nums[i] && count>=3){
                count = 1;
                val = nums[i];
            }
            
        }
        return val;
    }
};

//approach 2 using set bit in number 
/*
approach - we are checking each bit from 0 tp 31 bit for each element and vo vali bit se hogi jisme each number ka let say 
2nd bit and except one number all occur thrice so sum all set bit numbers from nums for second bit if modulo 3 gives one means 3 wale jo the vo nikl gye 
but remainder zero because of not repeating value
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i<32;i++){
            int sum = 0;
            for(auto val:nums){
                if((1<<i)&val){
                    sum++;
                }
            }
            if(sum%3==1){
                ans = (1<<i) | ans;
            }
        }
        return ans;
    }
};
//in this tc n*32 no matter what but now write nlogn + n/3 and nlogn will be smaller than that
/*
pseudocode
sort(arr)
for(i =1 to i<n and i+=3){sbhi k bich wale values ko i-1 se compare if not equal so return i-1 element
    if(nums[i]!=nums[i-1]){
    return nums[i-1]
    }
}
    return nums[n-1]//iska mtlb anser last me lie krta hai
*/