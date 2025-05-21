class Solution {
public:
    // int solve(vector<int>&nums,int target,vector<int>&dp){
    //     if(target==0) return 1;
    //     if(target<0) return 0;
    //     if(dp[target]!=-1) return dp[target];
    //     int ans=0;
    //     for(auto &num:nums){
    //       ans=ans+solve(nums,target-num,dp);
    //     }
    //     return dp[target]=ans;
    // }
    // int combinationSum4(vector<int>& nums, int target) {
    //     vector<int>dp(target+1,-1);
    //     return solve(nums,target,dp);
    // }

    int solve(vector<int>&nums,int t,vector<int>&dp){
        for(int target=1;target<=t;target++){
         long ans=0;
        for(auto &num:nums){
          if(num<=target)
          ans=ans+dp[target-num];
        }
        dp[target]=ans;
        }
        return dp[t];
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,0);
        dp[0]=1;
        return solve(nums,target,dp);
    }
};