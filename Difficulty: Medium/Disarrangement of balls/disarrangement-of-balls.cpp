// User function Template for C++

class Solution {
  public:
    int solve(int n,vector<int>&dp){
        if(n==1||n==2)
        return n-1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=(n-1)*(solve(n-1,dp)+solve(n-2,dp));
    }
    int countDer(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};