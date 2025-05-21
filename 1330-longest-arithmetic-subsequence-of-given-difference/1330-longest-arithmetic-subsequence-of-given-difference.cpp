class Solution {
public:
    // int solve(vector<int>&nums,int d,int i,int p,vector<vector<int>>&dp){
    //     if(i==nums.size()) return 0;
    //     if(dp[i][p+1]!=-1) return dp[i][p+1];
    //     int l=0;
    //     if(p==-1||nums[i]-nums[p]==d)
    //     l=1+solve(nums,d,i+1,i,dp);
    //     int r=solve(nums,d,i+1,p,dp);
    //     return dp[i][p+1]=max(l,r);
    // }
    // int longestSubsequence(vector<int>& nums, int difference) {
    //   vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
    //   return solve(nums,difference,0,-1,dp);
    // }


    int longestSubsequence(vector<int>& nums, int difference) {
     unordered_map<int,int>dp;
     int ans=0;
     for(int i=0;i<nums.size();i++){
        int temp=nums[i]-difference;
        int tempAns=0;
        if(dp.count(temp))
        tempAns=dp[temp];
        dp[nums[i]]=1+tempAns;
        ans=max(ans,dp[nums[i]]);
     }
     return ans;
    }
};