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


    //int findSubsequences(int n,vector<int>&nums){
    //      vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    //      for(int j=0;j<n+1;j++){
    //         dp[n][j]=0;
    //      }
    //     for(int curr=n-1;curr>=0;curr--){
    //       for(int prev=curr-1;prev>=-1;prev--){
    //         int l=0;
    //         if(prev==-1||nums[prev]<nums[curr])
    //         l=1+dp[curr+1][curr+1];
    //         int r=dp[curr+1][prev+1];
    //         dp[curr][prev+1]=max(l,r);
    //       }
    //     }
    //     return dp[0][0];
    // }
    // int lengthOfLIS(vector<int>& nums) {
    //     int n=nums.size();
    //     return findSubsequences(n,nums);
    // }

    // int findSubsequences(int n,vector<int>&nums){
    //      vector<int>c(n+1,-1);
    //      vector<int>next(n+1,0);
    //     for(int curr=n-1;curr>=0;curr--){
    //       for(int prev=curr-1;prev>=-1;prev--){
    //         int l=0;
    //         if(prev==-1||nums[prev]<nums[curr])
    //         l=1+next[curr+1];
    //         int r=next[prev+1];
    //         c[prev+1]=max(l,r);
    //       }
    //       next=c;
    //     }
    //     return c[0];
    // }
    // int lengthOfLIS(vector<int>& nums) {
    //     int n=nums.size();
    //     return findSubsequences(n,nums);
    // }
     


      int findSubsequences(int n,vector<int>&nums){
         vector<int>c(n+1,0);
        for(int curr=n-1;curr>=0;curr--){
        //   for(int prev=curr-1;prev>=-1;prev--){
             for(int prev=-1;prev<=curr-1;prev++){
            int l=0;
            if(prev==-1||nums[prev]<nums[curr])
            l=1+c[curr+1];
            int r=c[prev+1];
            c[prev+1]=max(l,r);
          }
        }
        return c[0];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        return findSubsequences(n,nums);
    }


    // int lengthOfLIS(vector<int>&nums){
    //     int n=nums.size();
    //     vector<int>dp(n,1);
    //     for(int curr=0;curr<n;curr++){
    //         for(int prev=0;prev<curr;prev++){
    //             if(nums[prev]<nums[curr]&&dp[curr]<dp[prev]+1){
    //                 dp[curr]=dp[prev]+1;
    //             }
    //         }
    //     }
    //     return *max_element(dp.begin(),dp.end());
    // }
};