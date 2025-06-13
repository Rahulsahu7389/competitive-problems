//recusion code
#include<bits/stdc++.h>
using namespace std;

int ans = -1;
int fun(int day , int last,vector<vector<int>> &points){
    if(day == 0){
        int maxi = -1;
        for(int i = 0 ;i<3;i++){
            if(i!=last){
                maxi = max(maxi,points[0][i]);
            }
        }
        return maxi;
    }
    int maxi = -1;
    for(int j = 0 ;j<3;j++){
        if(j!=last){
            maxi = max(points[day][j] + fun(day-1,j,points),maxi);
        }
    }
    return maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    return fun(n-1,3,points);
    // return ans;
}


// ###########with dp 
#include<bits/stdc++.h>
using namespace std;


int fun(int day , int last,vector<vector<int>> &points,vector<vector<int>>&dp){
    if(day == 0){
        int maxi = -1;
        for(int i = 0 ;i<3;i++){
            if(i!=last){
                maxi = max(maxi,points[0][i]);
            }
        }
        return maxi;
    }
    if(dp[day][last] != -1) return dp[day][last];
    int maxi = -1;
    for(int j = 0 ;j<3;j++){
        if(j!=last){
            dp[day][last] = max(points[day][j] + fun(day-1,j,points,dp),dp[day][last]);
        }
    }
    return dp[day][last];
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n,vector<int>(4,-1));//dp[i][j] it is the max merit from day 0 to day i and last perfomed activity is j
    // Write your code here.
    return fun(n-1,3,points,dp);
    // return ans;
}