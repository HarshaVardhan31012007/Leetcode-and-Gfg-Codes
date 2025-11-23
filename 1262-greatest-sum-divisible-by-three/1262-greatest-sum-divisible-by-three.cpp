class Solution {
public:
    // bool check(vector<int>&nums,int i,int t){
    //     if(i>=nums.size()){
    //         if(t==0)
    //         return true;
    //         return false;
    //     }
    //     bool l=false;
    //     if(t>=nums[i])
    //     l=check(nums,i+1,t-nums[i]);
    //     bool e=check(nums,i+1,t);
    //     return l||e;
    // }
    // int maxSumDivThree(vector<int>& nums) {
    //     int sum=accumulate(nums.begin(),nums.end(),0);
    //     int rem=sum%3;
    //     if(rem==0) return sum;
    //     while(rem<=sum){
    //         if(check(nums,0,rem))
    //           return sum-rem;
    //         rem+=3;
    //     }
    //     return 0;
    // }





    //  bool check(vector<int>&nums,vector<vector<int>>&dp,int t){
    //     for(int i=nums.size()-1;i>=0;i--){
    //         for(int j=0;j<=t;j++){
    //             bool l=false;
    //             if(j>=nums[i])
    //             l=dp[i+1][j-nums[i]];
    //             bool e=dp[i+1][j];
    //             dp[i][j]=l||e;
    //         }
    //     }
    //     return dp[0][t];
    // }
    // int maxSumDivThree(vector<int>& nums) {
    //     int sum=accumulate(nums.begin(),nums.end(),0);
    //     int rem=sum%3;
    //     if(rem==0) return sum;
    //     while(rem<=sum){
    //         vector<vector<int>>dp(nums.size()+1,vector<int>(rem+1,0));
    //         dp[nums.size()][0]=1;
    //         if(check(nums,dp,rem))
    //           return sum-rem;
    //         rem+=3;
    //     }
    //     return 0;
    // }






    // bool check(vector<int>&nums,vector<int>&curr,int &t){
    //     for(int i=nums.size()-1;i>=0;i--){
    //         for(int j=t;j>=0;j--){
    //             bool l=false;
    //             if(j>=nums[i])
    //             l=curr[j-nums[i]];
    //             bool e=curr[j];
    //             curr[j]=l||e;
    //         }
    //     }
    //     return curr[t];
    // }
    // int maxSumDivThree(vector<int>& nums) {
    //     int sum=accumulate(nums.begin(),nums.end(),0);
    //     int rem=sum%3;
    //     if(rem==0) return sum;
    //     while(rem<=sum){
    //         vector<int>curr(rem+1,0);
    //         curr[0]=1;
    //         if(check(nums,curr,rem))
    //           return sum-rem;
    //         rem+=3;
    //     }
    //     return 0;
    // }





    // void update(int &x,int &y,int &num){
    //         if(num<x){
    //              y=x;
    //              x=num;
    //         }
    //         else if(num<y){
    //             y=num;
    //         }   
    // }
    // int maxSumDivThree(vector<int>& nums) {
    //     int sum=0;
    //     int a=INT_MAX;int b=INT_MAX;int c=INT_MAX;int d=INT_MAX;
    //     for(int i=0;i<nums.size();i++){
    //          sum+=nums[i];
    //          int rem=nums[i]%3;
    //          if(rem==1){
    //             update(a,b,nums[i]);
    //          }
    //          else if(rem==2){
    //             update(c,d,nums[i]);
    //          }
    //     }
    //     if(sum%3==0) return sum;
    //     if(sum%3==1){
    //         int mini=min(a,c<INT_MAX&&d<INT_MAX?c+d:INT_MAX);
    //         if(mini!=INT_MAX)
    //         return sum-mini;
    //     }
    //     if(sum%3==2){
    //         int mini=min(c,a<INT_MAX&&b<INT_MAX?a+b:INT_MAX);
    //         if(mini!=INT_MAX)
    //         return sum-mini;
    //     }
    //     return 0;
    // }



    int solve(vector<int>&nums,int i,int rem,vector<vector<int>>&dp){
        if(i>=nums.size()){
            if(rem==0) return 0;
            return INT_MIN;
        }
        if(dp[i][rem]!=-1)
        return dp[i][rem];
        int inc=nums[i]+solve(nums,i+1,(rem%3+nums[i]%3)%3,dp);
        int exc=solve(nums,i+1,rem,dp);
        return dp[i][rem]=max(inc,exc);
    }
    int maxSumDivThree(vector<int>& nums) {
        vector<vector<int>>dp(nums.size()+1,vector<int>(3,-1));
        return solve(nums,0,0,dp);
    }
};