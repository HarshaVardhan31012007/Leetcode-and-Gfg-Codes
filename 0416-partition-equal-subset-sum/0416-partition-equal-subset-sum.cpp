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




    bool divide(vector<int>&nums,int k,int target,vector<vector<int>>&dp){
        if(k==nums.size()||target<0)
        return 0;
        if(target==0)
        return 1;
        if(dp[target][k]!=-1)
        return dp[target][k];
        int num=nums[k];
        bool includeAns=divide(nums,k+1,target-num,dp);
        bool excludeAns=divide(nums,k+1,target,dp);
        return dp[target][k]=includeAns||excludeAns;
    }
    bool canPartition(vector<int>& nums) {
        int total=accumulate(nums.begin(),nums.end(),0);
        if(total%2!=0)
        return 0;
        int target=total/2;
        int i=0;
        int n=nums.size();
        vector<vector<int>>dp(target+1,vector<int>(n+1,-1));
        bool ans=divide(nums,i,target,dp);
        return ans;
    }
};