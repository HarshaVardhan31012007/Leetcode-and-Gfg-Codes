class Solution {
public:
    // int solve(vector<int>&nums,int i,int xo,vector<vector<int>>&dp){
    //     if(i==nums.size()){
    //         if(xo)
    //         return 0;
    //         else
    //         return INT_MIN;
    //     }
    //     if(dp[i][xo]!=-1) return dp[i][xo];
    //     int l=1+solve(nums,i+1,xo^nums[i],dp);
    //     int r=solve(nums,i+1,xo,dp);
    //     return dp[i][xo]=max(l,r);
    // }
    // int longestSubsequence(vector<int>& nums) {
    //     int total=accumulate(nums.begin(),nums.end(),0);
    //     vector<vector<int>>dp(nums.size()+1,vector<int>(total+1,-1));
    //     return solve(nums,0,0,dp);
    // }


    //  int solve(vector<int>&nums){
    //       int total=accumulate(nums.begin(),nums.end(),0);
    //     vector<vector<int>>dp(nums.size()+1,vector<int>(total+1,0));
    //     dp[nums.size()][0]=INT_MIN;
    //     for(int i=nums.size()-1;i>=0;i--){
    //         for(int j=total;j>=0;j--){
    //             if(j^nums[i]>total) continue;
    //         int l=1+dp[i+1][j^nums[i]];
    //         int r=dp[i+1][j];
    //         dp[i][j]=max(l,r);
    //         }
    //     }
    //      return dp[0][0];
    // }
    // int longestSubsequence(vector<int>& nums) {
    //     return solve(nums);
    // }



    // int solve(vector<int>&nums,int i,int xo,map<pair<int,int>,int>&dp){
    //     if(i==nums.size()){
    //         if(xo)
    //         return 0;
    //         else
    //         return INT_MIN;
    //     }
    //     if(dp.find({i,xo})!=dp.end()) return dp[{i,xo}];
    //     int l=1+solve(nums,i+1,xo^nums[i],dp);
    //     int r=solve(nums,i+1,xo,dp);
    //     return dp[{i,xo}]=max(l,r);
    // }
    // int longestSubsequence(vector<int>& nums) {
    //     map<pair<int,int>,int>dp;
    //     return solve(nums,0,0,dp);
    // }



    int longestSubsequence(vector<int>& nums) {
         bool isAllZero=true;
         int xo=0;
         for(int i=0;i<nums.size();i++){
             xo=xo^nums[i];
             if(nums[i]!=0)
             isAllZero=false;
         }
         if(isAllZero) return 0;
         else if(xo) return nums.size();
         return nums.size()-1;
    }
};