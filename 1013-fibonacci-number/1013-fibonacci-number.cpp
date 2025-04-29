class Solution {
public:
    // int solveusingMem(int n,vector<int>&dp){
    //     if(n==1||n==0)
    //     return n;
    //     if(dp[n]!=-1)
    //     return dp[n];
    //     return dp[n]=solveusingMem(n-1,dp)+solveusingMem(n-2,dp);
    // }
    // int fib(int n) {
    //     vector<int>dp(n+1,-1);
    //     return solveusingMem(n,dp);
    // }

    int solveusingTab(int n){
        vector<int>dp(n+1,-1);
         if(n==0||n==1) return n;
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    int fib(int n){
        return solveusingTab(n);
    }
};