class Solution {
public:
   const int mod=1000000007;
    // long long int solve(int n,int k,int target,vector<vector<int>>&dp){
    //   if(target==0&&n==0)
    //   return 1;
    //   if(n==0||target==0)
    //   return 0;
    //   if(dp[n][target]!=-1)
    //   return dp[n][target]%mod;
    //     long long int ans=0;
    //     for(int i=1;i<=k;i++){
    //        if(i<=target)
    //        ans=(ans+(solve(n-1,k,target-i,dp))%mod)%mod;
    //     }
    //    return dp[n][target]=ans%mod;
    // }
    // long long int numRollsToTarget(int n, int k, int target) {
    //     vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
    //    return  solve(n,k,target,dp);
    // }


    // long long int solve(int n,int k,int target){
    //  vector<vector<long long int>>dp(n+1,vector<long long int>(target+1,0));
    //  dp[0][0]=1;
    //  for(int i=1;i<=n;i++){
    //     // for(int j=target;j>=1;j--){
    //         for(int j=1;j<=target;j++){
    //         long long ans=0;
    //         for(int p=1;p<=k;p++){
    //             if(p<=j)
    //             ans=((ans+dp[i-1][j-p])%mod)%mod;
    //         }
    //         dp[i][j]=ans%mod;
    //     }
    //  }
    //  return dp[n][target];
    // }
    // long long int numRollsToTarget(int n, int k, int target) {
    //    return  solve(n,k,target);
    // }



    //  long long int solve(int n,int k,int target){
    //  vector<long long int>curr(target+1,0);
    //  vector<long long int>prev(target+1,0);
    //   prev[0]=1;
    //  for(int i=1;i<=n;i++){
    //     for(int j=1;j<=target;j++){
    //         long long ans=0;
    //         for(int p=1;p<=k;p++){
    //             if(p<=j)
    //             ans=(ans+prev[j-p])%mod;
    //         }
    //         curr[j]=ans%mod;
    //     }
    //     prev=curr;
    //  }
    //  return prev[target]%mod;
    // }
    // long long int numRollsToTarget(int n, int k, int target) {
    //    return  solve(n,k,target);
    // } 

      long long int solve(int n,int k,int target){
     vector<int>curr(target+1,0);
     curr[0]=1;
     for(int i=1;i<=n;i++){
        for(int j=target;j>=0;j--){
            long long int ans=0;
            for(int p=1;p<=k;p++){
                long long int temp=0;
                if(p<=j)
                temp=curr[j-p];
                ans=ans%mod+temp%mod;
            }
            curr[j]=ans%mod;
        }
     }
     return curr[target]%mod;
    }
    long long int numRollsToTarget(int n, int k, int target) {
       return  solve(n,k,target);
    } 
};