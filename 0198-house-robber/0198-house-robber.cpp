class Solution {
public:
    // int solve(vector<int>&nums,int i,vector<int>&dp){
    //     if(i>=nums.size()) return 0;
    //     if(dp[i]!=-1) return dp[i];
    //     int inc=nums[i]+solve(nums,i+2,dp);
    //     int exc=solve(nums,i+1,dp);
    //     return dp[i]=max(inc,exc);
    // }
    // int rob(vector<int>& nums) {
    //     vector<int>dp(nums.size()+1,-1);
    //     return solve(nums,0,dp);
    // }


    
    // int rob(vector<int>& nums) {
    //     vector<int>dp(nums.size()+2,0);
    //     for(int i=nums.size()-1;i>=0;i--){
    //         int inc=nums[i]+dp[i+2];
    //         int exc=dp[i+1];
    //         dp[i]=max(inc,exc);
    //     }
    //     return dp[0];
    // }


    int rob(vector<int>& nums) {
        int next1=0;
        int next2=0;
        for(int i=nums.size()-1;i>=0;i--){
            int inc=nums[i]+next2;
            int exc=next1;
            int curr=max(inc,exc);
            next2=next1;
            next1=curr;
        }
        return next1;
    }
};