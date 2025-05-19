class Solution {
public:
    // int solve(vector<int>&nums,int target,int sum,int i,int t,vector<vector<int>>&dp){
    //     if(i==nums.size()){
    //         if(sum==target)
    //         return 1;
    //         return 0;
    //     }
    //     if(dp[i][sum+t]!=-1) return dp[i][sum+t];
    //     int a=solve(nums,target,sum-nums[i],i+1,t,dp);
    //     int b=solve(nums,target,sum+nums[i],i+1,t,dp);
    //     return dp[i][sum+t]=a+b;
    // }
    // int findTargetSumWays(vector<int>& nums, int target) {
    //     int t=accumulate(nums.begin(),nums.end(),0);
    //     vector<vector<int>>dp(nums.size()+1,vector<int>(2*t+1,-1));
    //     return solve(nums,target,0,0,t,dp);
    // }

     int solve(vector<int>&nums,int target,int i,map<pair<int,int>,int>&dp){
        if(i==nums.size()){
            if(target==0)
            return 1;
            return 0;
        }
        if(dp.find({i,target})!=dp.end()) return dp[{i,target}];
        int a=solve(nums,target-nums[i],i+1,dp);
        int b=solve(nums,target+nums[i],i+1,dp);
        return dp[{i,target}]=a+b;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int,int>,int>dp;
        return solve(nums,target,0,dp);
    }
};