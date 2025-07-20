class Solution {
public:
    int solve(vector<int>&nums,int i,vector<int>&dp){
    if(i==nums.size()-1) return 0;
    if(i>=nums.size()) return INT_MAX;
    if(dp[i]!=-1) return dp[i];
    int ans=INT_MAX;
    for(int jump=1;jump<=nums[i];jump++){
    int recAns=solve(nums,i+jump,dp);
    if(recAns!=INT_MAX)
    ans=min(ans,1+recAns);
    }
    return dp[i]=ans;
    }
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return solve(nums,0,dp);
    }
};