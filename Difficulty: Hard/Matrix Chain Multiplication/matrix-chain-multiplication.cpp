class Solution {
  public:
    int solve(vector<int>&arr,int s,int e,vector<vector<int>>&dp){
        if(s==e) return 0;
        if(dp[s][e]!=-1) return dp[s][e];
        int mini=INT_MAX;
        for(int i=s;i<=e-1;i++){
            mini=min(mini,arr[s-1]*arr[i]*arr[e]+solve(arr,s,i,dp)+solve(arr,i+1,e,dp));
        }
        return dp[s][e]=mini;
    }
    int matrixMultiplication(vector<int> &arr) {
        vector<vector<int>>dp(arr.size()+1,vector<int>(arr.size()+1,-1));
         return solve(arr,1,arr.size()-1,dp);
    }
};