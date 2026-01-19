class Solution {
  public:
    int t;
    int solve(vector<int>&arr,int i,int sum,int diff,vector<vector<int>>&dp){
        if(i>=arr.size()) return (sum-(t-sum))==diff;
        if(dp[i][sum]!=-1) return dp[i][sum];
        int inc=solve(arr,i+1,sum+arr[i],diff,dp);
        int exc=solve(arr,i+1,sum,diff,dp);
        return dp[i][sum]=inc+exc;
    }
    int countPartitions(vector<int>& arr, int diff) {
        t=accumulate(arr.begin(),arr.end(),0);
        vector<vector<int>>dp(arr.size()+1,vector<int>(t+1,-1));
        return solve(arr,0,0,diff,dp);
    }
};