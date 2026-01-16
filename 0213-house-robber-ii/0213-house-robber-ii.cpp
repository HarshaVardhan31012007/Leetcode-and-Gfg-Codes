class Solution {
public:
    int solve(vector<int>&nums,int i,int end,vector<int>&dp){
        if(i>end) return 0;
        if(dp[i]!=-1) return dp[i];
        int inc=nums[i]+solve(nums,i+2,end,dp);
        int exc=solve(nums,i+1,end,dp);
        return dp[i]=max(inc,exc);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp1(n+1,-1);
        vector<int>dp2(n+1,-1);
        return max(nums[0]+solve(nums,2,n-2,dp1),solve(nums,1,n-1,dp2));
    }
};