class Solution {
public:
    // void findSubsequences(vector<int>& nums,vector<int>&res,int i,int &maxi){
    //     if(i>=nums.size()){
    //     int n=res.size();
    //     maxi=max(maxi,n);
    //     return;
    //     }
    //     if(res.empty()||res.back()<nums[i]){
    //     res.push_back(nums[i]);
    //     findSubsequences(nums,res,i+1,maxi);
    //     res.pop_back();
    //     }
    //     findSubsequences(nums,res,i+1,maxi);
    // }
    // int lengthOfLIS(vector<int>& nums) {
    //     int i=0;
    //     vector<int>res;
    //     int maxi=INT_MIN;
    //     findSubsequences(nums,res,i,maxi);
    //     return maxi;
    // }


    // int findSubsequences(vector<int>& nums,int i,int prev){
    //     if(i>=nums.size()){
    //     return 0;
    //     }
    //     int l=0;
    //     if(prev<nums[i]){
    //     l=1+findSubsequences(nums,i+1,nums[i]);
    //     }
    //     int r=findSubsequences(nums,i+1,prev);
    //     return max(l,r);
    // }
    // int lengthOfLIS(vector<int>& nums) {
    //     int i=0;
    //     int n=nums.size();
    //     return findSubsequences(nums,i,INT_MIN);
    // }


    // int findSubsequences(vector<int>& nums,int i,int prev,vector<vector<int>>&dp){
    //     if(i>=nums.size()){
    //     return 0;
    //     }
    //     if(dp[prev+1][i]!=-1)
    //     return dp[prev+1][i];
    //     int l=0;
    //     if(prev==-1||nums[prev]<nums[i]){
    //     l=1+findSubsequences(nums,i+1,i,dp);
    //     }
    //     int r=findSubsequences(nums,i+1,prev,dp);
    //     return dp[prev+1][i]=max(l,r);
    // }
    // int lengthOfLIS(vector<int>& nums) {
    //     int i=0;
    //     int n=nums.size();
    //     vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    //     return findSubsequences(nums,i,-1,dp);
    // }


    int findSubsequences(int n,vector<int>&nums){
       vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
       for(int i=0;i<n+1;i++)
       dp[i][n]=0;
       for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
        int l=0;
        if(i==0||nums[i-1]<nums[j]){
        l=1+dp[j+1][j+1];
        }
        int r=dp[i][j+1];
        dp[i][j]=max(l,r);
        }
       }
       return dp[0][0];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        return findSubsequences(n,nums);
    }
};