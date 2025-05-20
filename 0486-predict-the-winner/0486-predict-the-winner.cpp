class Solution {
public:
    int solve(vector<int>&nums,int s,int e,vector<vector<int>>&dp){
      if(s==e) return nums[s];
      if(dp[s][e]!=-1) return dp[s][e];
      return dp[s][e]=max(nums[s]-solve(nums,s+1,e,dp),nums[e]-solve(nums,s,e-1,dp));
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        //if(n%2==0) return true;//optimization
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans=solve(nums,0,n-1,dp);
        return ans>=0;
    }
};