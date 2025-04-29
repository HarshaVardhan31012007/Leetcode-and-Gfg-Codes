class Solution {
public:
    // void solve(vector<int>&nums,int i,int ans,int &maxi,vector<int>&dp){
    //     if(i>=nums.size()) {
    //         maxi=max(maxi,ans);
    //         return;
    //     }
    //     solve(nums,i+2,ans+nums[i],maxi);
    //     solve(nums,i+1,ans,maxi);
    // }
    // int rob(vector<int>& nums) {
    //     if(nums.size()==1) return nums[0];
    //     vector<int>dp(n,-1);
    //     int ans=0;int maxi=INT_MIN;
    //     solve(nums,0,ans,maxi,dp);
    //     return maxi;
    // }


    int solve(vector<int>&nums,int i,vector<int>&dp){
        if(i>=nums.size()) {
            return 0;
        }
        if(dp[i]!=-1)
        return dp[i];
        int l=nums[i]+solve(nums,i+2,dp);
        int r=solve(nums,i+1,dp);
        return dp[i]=max(l,r);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(nums,0,dp);
    }
};