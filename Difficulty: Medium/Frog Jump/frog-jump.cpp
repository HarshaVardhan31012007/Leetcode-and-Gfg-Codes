class Solution {
  public:
    int frogJump1(int n, vector<int> &heights,vector<int>&dp)
{
    if(n==1) return 0;
    if(n==2) return abs(heights[1]-heights[0]);
    if(dp[n]!=-1) return dp[n];
    return dp[n]=min(abs(heights[n-1]-heights[n-2])+frogJump1(n-1,heights,dp),abs(heights[n-1]-heights[n-3])+frogJump1(n-2,heights,dp));
}
    int minCost(vector<int>& height) {
        int n=height.size();
        vector<int>dp(n+1,-1);
        return frogJump1(n,height,dp);
    }
};