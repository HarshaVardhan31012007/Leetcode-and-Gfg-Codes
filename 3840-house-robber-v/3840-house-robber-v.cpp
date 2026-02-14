class Solution {
public:
    // long long solve(vector<int>&nums,vector<int>&colors,int i,vector<long long>&dp){
    //     if(i>=nums.size()) return 0;
    //     if(i==nums.size()-1) return nums[i];
    //     if(dp[i]!=-1) return dp[i];
    //     long long inc=0;
    //     if(colors[i]!=colors[i+1])
    //     inc=max(inc,nums[i]+solve(nums,colors,i+1,dp));
    //     else
    //     inc=max(inc,nums[i]+solve(nums,colors,i+2,dp));
    //     long long exc=solve(nums,colors,i+1,dp);
    //     return dp[i]=max({inc,exc});
    // }
    // long long rob(vector<int>& nums, vector<int>& colors) {
    //     vector<long long>dp(nums.size()+1,-1);
    //     return solve(nums,colors,0,dp);
    // }



    long long rob(vector<int>& nums, vector<int>& colors) {
        vector<long long>dp(nums.size()+1,0);
        dp[nums.size()-1]=nums.back();
        for(int i=nums.size()-2;i>=0;i--){
            long long inc=0;
            if(colors[i]!=colors[i+1])
            inc=nums[i]+dp[i+1];
            else
            inc=nums[i]+dp[i+2];
            long long exc=dp[i+1];
            dp[i]=max(inc,exc);
        }
        return dp[0];
    }
};