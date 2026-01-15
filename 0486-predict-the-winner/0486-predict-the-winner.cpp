class Solution {
public:
    int solve(vector<int>&nums,int i,int j,vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=max(nums[i]-solve(nums,i+1,j,dp),nums[j]-solve(nums,i,j-1,dp)); 
    }
    bool predictTheWinner(vector<int>& nums) {
       vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
       int ans=solve(nums,0,nums.size()-1,dp);
       return ans>=0;
    }
};