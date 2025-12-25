class Solution {
public:
    bool solve(vector<int>&nums,int i,int target,vector<vector<int>>&dp){
        if(i>=nums.size()) return target==0;
        if(target==0) return 1;
        if(dp[i][target]!=-1) return dp[i][target];
        bool inc=false;
        if(nums[i]<=target) 
        inc=solve(nums,i+1,target-nums[i],dp);
        int exc=solve(nums,i+1,target,dp);
        return dp[i][target]=inc||exc;
    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if((sum&1)) return false;
        vector<vector<int>>dp(nums.size()+1,vector<int>(sum/2+1,-1));
        return solve(nums,0,sum/2,dp);
    }
};