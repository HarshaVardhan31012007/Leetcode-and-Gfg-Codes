class Solution {
public:
    // const int mod=1e9+7;
    // int solve(vector<int>&nums,int i,int flag,int t1,int t2,vector<vector<int>>&dp){
    //     if(i>=nums.size()) return 1;
    //     if(dp[i][flag]!=-1) return dp[i][flag];
    //     int xo=0;int ans=0;int t=(flag==0)?t1:t2;
    //     for(int j=i;j<nums.size();j++){
    //          xo=xo^nums[j];
    //          if(xo==t)
    //          ans=(ans+solve(nums,j+1,!flag,t1,t2,dp))%mod;
    //     }
    //     return dp[i][flag]=ans;
    // }
    // int alternatingXOR(vector<int>& nums, int target1, int target2) {
    //    vector<vector<int>>dp(nums.size()+1,vector<int>(2,-1));
    //    return solve(nums,0,0,target1,target2,dp);
    // }

    const int mod=1e9+7;
    int alternatingXOR(vector<int>& nums, int target1, int target2) {
        vector<int>dp1(nums.size(),0);
        vector<int>dp2(nums.size(),0);
        unordered_map<int,int>cnt1,cnt2;
        int xo=0;
        cnt1[0]=1;
        for(int i=0;i<nums.size();i++){
            xo=xo^nums[i];
            dp1[i]=cnt1[xo^target1];
            dp2[i]=cnt2[xo^target2];
            cnt1[xo]=(cnt1[xo]+dp2[i])%mod;
            cnt2[xo]=(cnt2[xo]+dp1[i])%mod;
        }
        return (dp1[nums.size()-1]+dp2[nums.size()-1])%mod;
    }
};