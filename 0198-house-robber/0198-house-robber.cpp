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

    
    // int solve(vector<int>&nums,int i,int ans){
    //     if(i>=nums.size()) {
    //         return ans;
    //     }
    //     int l=solve(nums,i+2,ans+nums[i]);
    //     int r=solve(nums,i+1,ans);
    //     return max(l,r);
    // }
    // int rob(vector<int>& nums) {
    //     if(nums.size()==1) return nums[0];
    //     int ans=0;
    //     return solve(nums,0,ans);
    // }

     
    // int solve(vector<int>&nums,int i,vector<int>&dp){
    //     if(i>=nums.size()) {
    //         return 0;
    //     }
    //     if(dp[i]!=-1)
    //     return dp[i];
    //     int l=nums[i]+solve(nums,i+2,dp);
    //     int r=solve(nums,i+1,dp);
    //     return dp[i]=max(l,r);
    // }
    // int rob(vector<int>& nums) {
    //     if(nums.size()==1) return nums[0];
    //     int n=nums.size();
    //     vector<int>dp(n,-1);
    //     return solve(nums,0,dp);
    // }


    // int solve(vector<int>&nums,int n){
    //     vector<int>dp(n+2,-1);
    //     dp[n]=0;
    //     dp[n+1]=0;
    //     for(int i=n-1;i>=0;i--){
    //         dp[i]=max(nums[i]+dp[i+2],dp[i+1]);
    //     }
    //     return dp[0];
    // }
    // int rob(vector<int>& nums) {
    //     if(nums.size()==1) return nums[0];
    //     int n=nums.size();
    //     return solve(nums,n);
    // }


    int solve(vector<int>&nums,int n){
        int prev1=0;
        int prev2=0;
        int curr;
        for(int i=n-1;i>=0;i--){
           curr=max(nums[i]+prev2,prev1);
           prev2=prev1;
           prev1=curr;
        }
        return curr;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int n=nums.size();
        return solve(nums,n);
    }
};