class Solution {
public:
    // int solve(int n,vector<int>&dp,vecor<int>&cost){
    //     if(n==0||n==1)
    //     return cost[n];
    //     if(dp[n]!=-1)
    //     return dp[n];
    //     int t=(n==cost.size())?0:cost[n];
    //     return dp[n]=t+min(solve(n-1,dp,cost),solve(n-2,dp,cost));
    // }
    // int minCostClimbingStairs(vector<int>& cost) {
    //    int n=cost.size();
    //    vector<int>dp(n+1,-1);
    //    return solve(n,dp,cost);
    // }

     int solve(vector<int>&cost){
       int n=cost.size();
       vector<int>dp(n+1,0);
       dp[0]=cost[0];dp[1]=cost[1];
       for(int i=2;i<=n;i++){
              int t=(i==n)?0:cost[i];
              dp[i]=t+min(dp[i-1],dp[i-2]);
       }
       return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
       return solve(cost);
    }
};