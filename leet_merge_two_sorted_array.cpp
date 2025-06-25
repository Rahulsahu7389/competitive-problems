// ny approach:
void merge(vector<int>&ans , vector<int> a , vector<int>b){
        int i = 0;
        int j = 0;
        if(a.size()>0 && b.size()>0){
            while(i<=a.size()-1 && j<=b.size()-1){
                if(a[i]<=b[j]){
                    ans.push_back(a[i]);
                    i++;
                }
                else{
                    ans.push_back(b[j]);
                    j++;
                }
            }
        }
        if(a.size()>0){
            while(i<=a.size()-1){
            ans.push_back(a[i]);
            i++;
        }
        }
        if(b.size()>0){

        while(j<=b.size()-1){
            ans.push_back(b[j]);
            j++;
        }
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> ans;

        merge(ans , nums1 , nums2);
        // for(auto val:ans){
        //     cout<<val<<endl;
        // }
        int n = ans.size();
        if(n%2==0){
            return ((double)(ans[n/2 -1]+ans[(n/2)])/2);
        }
        return ((double)ans[n/2]);
    }