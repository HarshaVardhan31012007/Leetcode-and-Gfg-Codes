class Solution {
public:
    // const int mod=1e9+7;
    // int solve(int n,int k,int target,vector<vector<int>>&dp){
    //    if(target<0) return 0;
    //    if(n==0){
    //       if(target==0)
    //       return 1;
    //       else
    //       return 0;
    //    }
    //    if(dp[n][target]!=-1) return dp[n][target];
    //    int ans=0;
    //    for(int i=1;i<=k;i++){
    //         ans=(ans+solve(n-1,k,target-i,dp))%mod;
    //    } 
    //    return dp[n][target]=ans;
    // }
    // int numRollsToTarget(int n, int k, int target) {
    //     vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
    //     return solve(n,k,target,dp);
    // }



    const int mod=1e9+7;
    int solve(int n,int k,int target,vector<vector<int>>&dp){
       if(target<0) return 0;
       if(n==0){
          if(target==0)
          return 1;
          else
          return 0;
       }
       if(dp[n][target]!=-1) return dp[n][target];
       int ans=0;
       for(int i=1;i<=k;i++){
            ans=(ans+solve(n-1,k,target-i,dp))%mod;
       } 
       return dp[n][target]=ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=target;j>=0;j--){
                int ans=0;
                for(int p=1;p<=k;p++){
                        if(p<=j)
                        ans=(ans+dp[i-1][j-p])%mod;
                } 
                dp[i][j]=ans;
            }
        }
        return dp[n][target];
    }
};