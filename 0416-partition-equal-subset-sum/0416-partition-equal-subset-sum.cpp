class Solution {
public:
    // bool solve(vector<int>&nums,int i,int target,vector<vector<int>>&dp){
    //     if(i>=nums.size()) return target==0;
    //     if(target==0) return 1;
    //     if(dp[i][target]!=-1) return dp[i][target];
    //     bool inc=false;
    //     if(nums[i]<=target) 
    //     inc=solve(nums,i+1,target-nums[i],dp);
    //     int exc=solve(nums,i+1,target,dp);
    //     return dp[i][target]=inc||exc;
    // }
    // bool canPartition(vector<int>& nums) {
    //     int sum=accumulate(nums.begin(),nums.end(),0);
    //     if((sum&1)) return false;
    //     vector<vector<int>>dp(nums.size()+1,vector<int>(sum/2+1,-1));
    //     return solve(nums,0,sum/2,dp);
    // }


   
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if((sum&1)) return false;
        vector<vector<int>>dp(nums.size()+1,vector<int>(sum/2+1,0));
        dp[nums.size()][0]=1;
        for(int i=0;i<nums.size();i++)
        dp[i][0]=1;
        for(int i=nums.size()-1;i>=0;i--){
            for(int target=sum/2;target>=0;target--){
                    bool inc=false;
                    if(nums[i]<=target) 
                    inc=dp[i+1][target-nums[i]];
                    int exc=dp[i+1][target];
                    dp[i][target]=inc||exc;
            }
        }
        return dp[0][sum/2];
    }
};