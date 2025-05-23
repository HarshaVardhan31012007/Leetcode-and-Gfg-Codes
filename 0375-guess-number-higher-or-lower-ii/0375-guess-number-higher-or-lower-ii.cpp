class Solution {
public:
    // int solve(int s,int e,vector<vector<int>>&dp){
    //  if(s>=e)
    //  return 0;
    //  if(dp[s][e]!=-1)
    //  return dp[s][e];
    //  int ans=INT_MAX;
    //  for(int i=s;i<=e;i++){
    //    ans=min(ans,i+max(solve(s,i-1,dp),solve(i+1,e,dp)));
    //  }
    //  return dp[s][e]=ans;
    // }
    // int getMoneyAmount(int n) {
    //     vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    //     return solve(1,n,dp);
    // }



    // int solve(int n){
    //  vector<vector<int>>dp(n+2,vector<int>(n+1,0));
    //  for(int s=n;s>=1;s--){
    //     for(int e=1;e<=n;e++){   
    //         if(s>=e)
    //         continue;
    //         else{
    //  int ans=INT_MAX;
    //  for(int i=s;i<=e;i++){
    //    ans=min(ans,i+max(dp[s][i-1],dp[i+1][e]));
    //  }
    //  dp[s][e]=ans;
    //         }
    //     }
    //  }
    //  return dp[1][n];
    // }


    int solve(int n){
     vector<vector<int>>dp(n+2,vector<int>(n+1,0));
     for(int s=n;s>=1;s--){
        for(int e=s+1;e<=n;e++){  //s<e means e starts from s+1 
     int ans=INT_MAX;
     for(int i=s;i<=e;i++){
       ans=min(ans,i+max(dp[s][i-1],dp[i+1][e]));
     }
     dp[s][e]=ans;
        }
     }
     return dp[1][n];
    }
    int getMoneyAmount(int n) {
        return solve(n);
    }
};