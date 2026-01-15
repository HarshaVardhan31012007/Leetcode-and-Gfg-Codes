class Solution {
public:
    int solve(vector<int>&nums1,vector<int>&nums2,int i,int flag,vector<vector<int>>&dp){
        if(i>=nums1.size()) return 0;
        if(dp[i][flag]!=-1) return dp[i][flag];
        int prev1=-1;
        int prev2=-1;
        if(flag==0){
           prev1=(i>0?nums1[i-1]:-1);
           prev2=(i>0?nums2[i-1]:-1);
        }
        else{
           prev1=(i>0?nums2[i-1]:-1);
           prev2=(i>0?nums1[i-1]:-1);
        }
        int one=1e6;
        if(prev1<nums1[i]&&prev2<nums2[i])
        one=solve(nums1,nums2,i+1,0,dp);
        int two=1e6;
        if(prev1<nums2[i]&&prev2<nums1[i])
        two=1+solve(nums1,nums2,i+1,1,dp);
        return dp[i][flag]=min(one,two);
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(nums1.size()+1,vector<int>(2,-1));
        return solve(nums1,nums2,0,0,dp);
    }
};