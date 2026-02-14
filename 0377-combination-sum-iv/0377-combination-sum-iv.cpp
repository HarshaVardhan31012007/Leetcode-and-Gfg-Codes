// class Solution {
// public:
//     int solve(vector<int>&nums,int i,int target,vector<vector<int>>&dp){
//         if(target==0) return 1;
//         if(i>=nums.size()) return 0;
//         if(dp[i][target]!=-1) return dp[i][target];
//         int inc=0;
//         if(target>=nums[i]){
//            inc=solve(nums,i,target-nums[i],dp);
//         }
//         int exc=solve(nums,i+1,target,dp);
//         return dp[i][target]=inc+exc;
//     }
//     int combinationSum4(vector<int>& nums, int target) {
//         vector<vector<int>>dp(nums.size()+1,vector<int>(target+1,-1));
//         return solve(nums,0,target,dp);
//     }
// };



class Solution {
public:
    int solve(vector<int>&nums,int target,vector<int>&dp){
        if(target==0) return 1;
        if(dp[target]!=-1) return dp[target];
        int ans=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]<=target){
                ans+=solve(nums,target-nums[j],dp);
            }
        }
        return dp[target]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,-1);
        return solve(nums,target,dp);
    }
};