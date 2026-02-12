class Solution {
  public:
    int solve(vector<int>&arr,int s,int e,vector<vector<int>>&dp){
        if(s==e) return 0;
        if(dp[s][e]!=-1) return dp[s][e];
        int ans=INT_MAX;
        for(int k=s;k<e;k++){
             ans=min(ans,arr[s]*arr[k+1]*arr[e+1]+solve(arr,s,k,dp)+solve(arr,k+1,e,dp));
        }
        return dp[s][e]=ans;
    }
    int matrixMultiplication(vector<int> &arr) {
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(arr,0,n-2,dp);
    }
};