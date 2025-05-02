class Solution {
public:
    // bool divide(vector<int>&nums,int k,int target){

    //     //base case
    //     if(k==nums.size()||target<0)
    //     return 0;
    //     if(target==0)
    //     return 1;
    //     int num=nums[k];
    //     bool includeAns=divide(nums,k+1,target-num);
    //     //exclude
    //     bool excludeAns=divide(nums,k+1,target);
    //     return includeAns||excludeAns;
    // }
    // bool canPartition(vector<int>& nums) {
    //     // int total=0;
    //     // for(int i=0;i<nums.size();i++){
    //     //   total+=nums[i];
    //     // }
    //     int total=accumulate(nums.begin(),nums.end(),0);
    //     if(total%2!=0)
    //     return 0;
    //     int target=total/2;
    //     int i=0;
    //     bool ans=divide(nums,i,target);
    //     return ans;

    // }




    // bool divide(vector<int>&nums,int k,int target,vector<vector<int>>&dp){
    //     // if(k==nums.size()||target<0)
    //     // return 0;
    //      if(k==nums.size())
    //     return 0;
    //     if(target==0)
    //     return 1;
    //     if(dp[target][k]!=-1)
    //     return dp[target][k];
    //     int num=nums[k];
    //     bool includeAns=0;
    //     if(num<=target)
    //     includeAns=divide(nums,k+1,target-num,dp);
    //     bool excludeAns=divide(nums,k+1,target,dp);
    //     return dp[target][k]=includeAns||excludeAns;
    // }
    // bool canPartition(vector<int>& nums) {
    //     int total=accumulate(nums.begin(),nums.end(),0);
    //     if(total%2!=0)
    //     return 0;
    //     int target=total/2;
    //     int i=0;
    //     int n=nums.size();
    //     vector<vector<int>>dp(target+1,vector<int>(n+1,-1));
    //     bool ans=divide(nums,i,target,dp);
    //     return ans;
    // }



    //  bool divide(vector<int>&nums,int target){
    //    int n=nums.size();
    //    vector<vector<int>>dp(target+1,vector<int>(n+1,0));
    //    for(int j=0;j<=n;j++)
    //    dp[0][j]=1;
    //    for(int i=1;i<=target;i++){
    //     for(int j=n-1;j>=0;j--){
    //         int l=0;
    //         if(nums[j]<=i)
    //         l=dp[i-nums[j]][j+1];
    //         int r=dp[i][j+1];
    //         dp[i][j]=l||r;
    //     }
    //    }
    //    return dp[target][0];
    // }

    // bool divide(vector<int>&nums,int target){
    //    int n=nums.size();
    //    vector<int>curr(target+1,-1);
    //    vector<int>next(target+1,0);
    //    next[0]=curr[0]=1;
    //     for(int j=n-1;j>=0;j--){
    //         for(int i=1;i<=target;i++){
    //         int l=0;
    //         if(nums[j]<=i)
    //         l=next[i-nums[j]];
    //         int r=next[i];
    //         curr[i]=l||r;
    //     }
    //     next=curr;
    //    }
    //    return next[target];
    // }


     bool divide(vector<int>&nums,int target){
       int n=nums.size();
       vector<int>curr(target+1,0);
       curr[0]=1;
        for(int j=n-1;j>=0;j--){
            for(int i=target;i>=1;i--){
            int l=0;
            if(nums[j]<=i)
            l=curr[i-nums[j]];
            int r=curr[i];
            curr[i]=l||r;
            }
       }
       return curr[target];
    }
    bool canPartition(vector<int>& nums) {
        int total=accumulate(nums.begin(),nums.end(),0);
        if(total%2!=0)
        return 0;
        int target=total/2;
        bool ans=divide(nums,target);
        return ans;
    }
};