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

     int solve(vector<int>&nums,int target){
       map<pair<int,int>,int>dp;
       int t=accumulate(nums.begin(),nums.end(),0);
       dp[{nums.size(),0}]=1;
       for(int i=nums.size()-1;i>=0;i--){
        for(int sum=-t;sum<=t;sum++){
            int a=dp[{i+1,sum-nums[i]}];
            int b=dp[{i+1,sum+nums[i]}];
            dp[{i,sum}]=a+b;
        }
       }
       return dp[{0,target}];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums,target);
    }
};