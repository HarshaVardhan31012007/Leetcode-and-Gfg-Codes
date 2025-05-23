class Solution {
public:
    // map<pair<pair<vector<int>,vector<int>>,pair<int,int>>,int>dp;
    // int solve(vector<int>& nums1, vector<int>& nums2,int p,int i){
    //     if(i==nums1.size()) return 0;
    //     if(dp.find({{nums1,nums2},{p,i}})!=dp.end()) return dp[{{nums1,nums2},{p,i}}];
    //     int ans=INT_MAX;
    //     if(p==-1||(nums1[p]<nums1[i]&&nums2[p]<nums2[i]))
    //     ans=min(ans,solve(nums1,nums2,i,i+1));
    //     swap(nums1[i],nums2[i]);
    //     if(p==-1||(nums1[p]<nums1[i]&&nums2[p]<nums2[i]))
    //     ans=min(ans,1+solve(nums1,nums2,i,i+1));
    //     swap(nums1[i],nums2[i]);
    //     return dp[{{nums1,nums2},{p,i}}]=ans;
    // }
    // int minSwap(vector<int>& nums1, vector<int>& nums2) {
    //     return solve(nums1,nums2,-1,0);
    // }



    // int solve(vector<int>& nums1, vector<int>& nums2,int p1,int p2,int i,int isswap,vector<vector<int>>&dp){
    //    if(i==nums1.size()) return 0;
    //    if(dp[i][isswap]!=-1) return dp[i][isswap];
    //    int ans=INT_MAX;
    //    if(p1<nums2[i] && p2<nums1[i])
    //    ans=min(ans,1+solve(nums1,nums2,nums2[i],nums1[i],i+1,1,dp));
    //    if(p1<nums1[i] && p2<nums2[i])
    //    ans=min(ans,solve(nums1,nums2,nums1[i],nums2[i],i+1,0,dp));
    //    return dp[i][isswap]=ans;
    // }
    // int minSwap(vector<int>& nums1, vector<int>& nums2) {
    //     vector<vector<int>>dp(nums1.size()+1,vector<int>(2,-1));
    //     return solve(nums1,nums2,-1,-1,0,0,dp);
    // }


    // int solve(vector<int>& nums1, vector<int>& nums2,int i,int isswap,vector<vector<int>>&dp){
    //    if(i==nums1.size()) return 0;
    //    if(dp[i][isswap]!=-1) return dp[i][isswap];
    //    int ans=INT_MAX;
    //    int p1=nums1[i-1];
    //    int p2=nums2[i-1];
    //    if(isswap)
    //    swap(p1,p2);
    //    if(p1<nums2[i] && p2<nums1[i])
    //    ans=min(ans,1+solve(nums1,nums2,i+1,1,dp));
    //    if(p1<nums1[i] && p2<nums2[i])
    //    ans=min(ans,solve(nums1,nums2,i+1,0,dp));
    //    return dp[i][isswap]=ans;
    // }
    // int minSwap(vector<int>& nums1, vector<int>& nums2) {
    //     nums1.insert(nums1.begin(),-1);
    //     nums2.insert(nums2.begin(),-1);
    //     vector<vector<int>>dp(nums1.size()+1,vector<int>(2,-1));
    //     return solve(nums1,nums2,1,0,dp);
    // }


    //  int solve(vector<int>& nums1, vector<int>& nums2){
    //    vector<vector<int>>dp(nums1.size()+1,vector<int>(2,0));
    //    for(int i=nums1.size()-1;i>=1;i--){
    //     for(int isswap=1;isswap>=0;isswap--){
    //             int ans=INT_MAX;
    //             int p1=nums1[i-1];
    //             int p2=nums2[i-1];
    //             if(isswap)
    //             swap(p1,p2);
    //             if(p1<nums2[i] && p2<nums1[i])
    //             ans=min(ans,1+dp[i+1][1]);
    //             if(p1<nums1[i] && p2<nums2[i])
    //             ans=min(ans,dp[i+1][0]);
    //             dp[i][isswap]=ans;
    //     }
    //    }
    //    return dp[1][0];
    // }
    // int minSwap(vector<int>& nums1, vector<int>& nums2) {
    //     nums1.insert(nums1.begin(),-1);
    //     nums2.insert(nums2.begin(),-1);
    //     return solve(nums1,nums2);
    // }

     int solve(vector<int>& nums1, vector<int>& nums2){
      vector<int>curr(2,0);
      vector<int>next(2,0);
       for(int i=nums1.size()-1;i>=1;i--){
        for(int isswap=1;isswap>=0;isswap--){
                int ans=INT_MAX;
                int p1=nums1[i-1];
                int p2=nums2[i-1];
                if(isswap)
                swap(p1,p2);
                if(p1<nums2[i] && p2<nums1[i])
                ans=min(ans,1+next[1]);
                if(p1<nums1[i] && p2<nums2[i])
                ans=min(ans,next[0]);
                curr[isswap]=ans;
        }
        next=curr;
       }
       return curr[0];
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        return solve(nums1,nums2);
    }
};