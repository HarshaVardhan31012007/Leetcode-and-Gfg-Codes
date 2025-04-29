class Solution {
public:
    int solveusingMem(int n,vector<int>&dp){
        if(n==1||n==0)
        return n;
        if(dp[n]!=-1)
        return dp[n];
        return dp[n]=solveusingMem(n-1,dp)+solveusingMem(n-2,dp);
    }
    int fib(int n) {
        vector<int>dp(n+1,-1);
        return solveusingMem(n,dp);
    }
};