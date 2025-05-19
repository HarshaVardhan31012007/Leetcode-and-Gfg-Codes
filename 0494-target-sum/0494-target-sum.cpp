class Solution {
public:
    int solve(vector<int>&nums,int target,int sum,int i,int t,vector<vector<int>>&dp){
        if(i==nums.size()){
            if(sum==target)
            return 1;
            return 0;
        }
        if(dp[i][sum+t]!=-1) return dp[i][sum+t];
        int a=solve(nums,target,sum-nums[i],i+1,t,dp);
        int b=solve(nums,target,sum+nums[i],i+1,t,dp);
        return dp[i][sum+t]=a+b;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int t=accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>>dp(nums.size()+1,vector<int>(2*t+1,-1));
        return solve(nums,target,0,0,t,dp);
    }
};