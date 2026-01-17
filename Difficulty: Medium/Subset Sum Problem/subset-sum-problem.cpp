class Solution {
  public:
    bool solve(vector<int>&arr,int i,int target,vector<vector<int>>&dp){
        if(target==0) return 1;
        if(i>=arr.size()) return 0;
        if(dp[i][target]!=-1) return dp[i][target];
        bool inc=false;
        if(target>=arr[i])
        inc=solve(arr,i+1,target-arr[i],dp);
        bool exc=solve(arr,i+1,target,dp);
        return dp[i][target]=inc||exc;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        vector<vector<int>>dp(arr.size()+1,vector<int>(sum+1,-1));
        return solve(arr,0,sum,dp);
    }
};