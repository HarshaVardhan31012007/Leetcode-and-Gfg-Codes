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
    
    //  int solve(vector<int>&nums,int target){
    //     int t=accumulate(nums.begin(),nums.end(),0);
    //     vector<vector<int>>dp(nums.size()+1,vector<int>(2*t+1,0));
    //     for(int sum=-t;sum<=t;sum++){
    //         if(sum==target)
    //         dp[nums.size()][sum+t]=1;
    //     }
    //     for(int i=nums.size()-1;i>=0;i--){
    //         for(int sum=-t;sum<=t;sum++){
    //     int a=0;
    //     if(sum-nums[i]>=-t)
    //     a=dp[i+1][sum-nums[i]+t];
    //     int b=0;
    //     if(sum+nums[i]<=t)
    //     b=dp[i+1][sum+nums[i]+t];
    //     dp[i][sum+t]=a+b;
    //         }
    //     }
    //     return dp[0][0+t];
    // }
    // int findTargetSumWays(vector<int>& nums, int target) {
    //     return solve(nums,target);
    // }


    //   int solve(vector<int>&nums,int target){
    //     int t=accumulate(nums.begin(),nums.end(),0);
    //     vector<int>curr(2*t+1,0);
    //     vector<int>next(2*t+1,0);
    //     for(int sum=-t;sum<=t;sum++){
    //         if(sum==target)
    //         next[sum+t]=1;
    //     }
    //     for(int i=nums.size()-1;i>=0;i--){
    //         for(int sum=-t;sum<=t;sum++){
    //     int a=0;
    //     if(sum-nums[i]>=-t)
    //     a=next[sum-nums[i]+t];
    //     int b=0;
    //     if(sum+nums[i]<=t)
    //     b=next[sum+nums[i]+t];
    //     curr[sum+t]=a+b;
    //         }
    //         next=curr;
    //     }
    //     return curr[0+t];
    // }
    // int findTargetSumWays(vector<int>& nums, int target) {
    //     return solve(nums,target);
    // }

    //  int solve(vector<int>&nums,int target,int i,map<pair<int,int>,int>&dp){
    //     if(i==nums.size()){
    //         if(target==0)
    //         return 1;
    //         return 0;
    //     }
    //     if(dp.find({i,target})!=dp.end()) return dp[{i,target}];
    //     int a=solve(nums,target-nums[i],i+1,dp);
    //     int b=solve(nums,target+nums[i],i+1,dp);
    //     return dp[{i,target}]=a+b;
    // }
    // int findTargetSumWays(vector<int>& nums, int target) {
    //     map<pair<int,int>,int>dp;
    //     return solve(nums,target,0,dp);
    //}


    //  int solve(vector<int>&nums,int target){
    //    map<pair<int,int>,int>dp;
    //    int t=accumulate(nums.begin(),nums.end(),0);
    //    dp[{nums.size(),0}]=1;
    //    for(int i=nums.size()-1;i>=0;i--){
    //     for(int sum=-t;sum<=t;sum++){
    //         int a=dp[{i+1,sum-nums[i]}];
    //         int b=dp[{i+1,sum+nums[i]}];
    //         dp[{i,sum}]=a+b;
    //     }
    //    }
    //    return dp[{0,target}];
    // }
    // int findTargetSumWays(vector<int>& nums, int target) {
    //     return solve(nums,target);
    // }




     int solve(vector<int>&nums,int target,int i,int t,vector<vector<int>>&dp){
        if(i==nums.size()){
            if(target==0)
            return 1;
            return 0;
        }
        if(dp[i][target+2000]!=-1) return dp[i][target+2000];
        int a=solve(nums,target-nums[i],i+1,t,dp);
        int b=solve(nums,target+nums[i],i+1,t,dp);
        return dp[i][target+2000]=a+b;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int t=accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>>dp(nums.size()+1,vector<int>(4001,-1));
        return solve(nums,target,0,t,dp);
    }
};