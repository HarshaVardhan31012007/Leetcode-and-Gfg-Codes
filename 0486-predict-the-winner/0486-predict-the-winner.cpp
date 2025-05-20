class Solution {
public:
    // int solve(vector<int>&nums,int s,int e,vector<vector<int>>&dp){
    //   if(s==e) return nums[s];
    //   if(dp[s][e]!=-1) return dp[s][e];
    //   return dp[s][e]=max(nums[s]-solve(nums,s+1,e,dp),nums[e]-solve(nums,s,e-1,dp));
    // }
    // bool predictTheWinner(vector<int>& nums) {
    //     int n=nums.size();
    //     //if(n%2==0) return true;//optimization
    //     vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    //     int ans=solve(nums,0,n-1,dp);
    //     return ans>=0;
    // }



     int solve(vector<int>&nums,int n){
       vector<vector<int>>dp(n+1,vector<int>(n+1,0));
       for(int i=0;i<n;i++){
         dp[i][i]=nums[i];
       }
       for(int s=n-1;s>=0;s--){
        for(int e=s+1;e<n;e++){
           int l=nums[s]-dp[s+1][e];
           int r=nums[e]-dp[s][e-1];
           dp[s][e]=max(l,r);
        }
       }
       return dp[0][n-1];
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        if(n%2==0) return true;//optimization
        int ans=solve(nums,n);
        return ans>=0;
    }
};