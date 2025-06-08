//my approach -- got me wrong
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack <char> st;
        int n = num.length();
        if(n ==k){
            return "0";
        }
        int i = 0;
        for(i;(i<n && k>0);i++){
            // else{
                while(k>0 && !st.empty()){
                    if(num[i]<=st.top()){

                    st.pop();
                    k--;
                    }
                    else{
                        break;
                    }
                }
                st.push(num[i]);
            }
        // }

        //checking if still left in stack 
        if(i<=n-1){
            while(i<=n-1){
                st.push(num[i]);
                i++;
            }
        }
        
        string ans = "";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        //now check if k>0
        if(k>0){
            while(k>0 && ans.length()>0){
                ans.pop_back();
                k--;
            }
        }
        //leading zeroes
        i = 0;

        while(ans[i]=='0'){
            i++;
        }
        cout<<ans<<endl;
        if(i >= ans.length()){
            return "0";
        }
        
        return ans.substr(i,n-i);

    }
};


// correct code
class Solution {
public:
    string removeKdigits(string num, long long k) {
        stack <char> st;
        long long n = num.length();
        long long i = 0;
        for(i;i<n;i++){
            // else{
                while(k>0 && !st.empty() && (st.top()-'0'>num[i]-'0')){

                    st.pop();
                    k--;
                    
                }
                st.push(num[i]);
            }
        // }
        cout<<"eys"<<endl;
        while(k>0){
            st.pop();
            k--;
        }
        cout<<"eys"<<endl;
        if(st.empty()){
            return "0";
        }
        string res = "";
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        cout<<"eys"<<endl;
        i = res.length() -1;
        while(res.length()>0){
            if(res.back()=='0'){
                res.pop_back();
            }
            else{
                break;
            }
            
        }
        cout<<"eys"<<endl;
        reverse(res.begin(),res.end());
        if(res.length()==0) return "0";
        else{
            return res;
        }

    }
};