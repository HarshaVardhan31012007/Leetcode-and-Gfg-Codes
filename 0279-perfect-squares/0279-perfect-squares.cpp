class Solution {
public:
    // int solve(int n,vector<int>&dp){
    //     if(n==0) return 0;
    //     if(dp[n]!=-1) return dp[n];
    //     int ans=INT_MAX;
    //     for(int i=1;i<=sqrt(n);i++){
    //         if(i*i<=n){
    //             int recans=solve(n-i*i,dp);
    //              if(recans!=INT_MAX)
    //             ans=min(ans,1+recans);
    //         }
    //     }
    //     return dp[n]=ans;
    // }
    // int numSquares(int n) {
    //     vector<int>dp(n+1,-1);
    //     return solve(n,dp);
    // }



  
    int numSquares(int n) {
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=n;i++){
             int ans=INT_MAX;
             for(int j=1;j<=sqrt(i);j++){
                 ans=min(ans,1+dp[i-j*j]);
             }
             dp[i]=ans;
        }
        return dp[n];
    }
};