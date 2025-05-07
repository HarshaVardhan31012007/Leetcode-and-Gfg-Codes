class Solution {
public:
    int solve(int n,vector<int>&dp,vector<int>&cost){
        if(n==0||n==1)
        return cost[n];
        if(dp[n]!=-1)
        return dp[n];
        return dp[n]=min(((n==cost.size())?0:cost[n])+solve(n-1,dp,cost),((n==cost.size())?0:cost[n])+solve(n-2,dp,cost));
    }
    int minCostClimbingStairs(vector<int>& cost) {
       int n=cost.size();
       vector<int>dp(n+1,-1);
       return solve(n,dp,cost);
    }
};