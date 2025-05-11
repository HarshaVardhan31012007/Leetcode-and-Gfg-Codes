class Solution {
public:
    //for even and odd no of piles

    int solve(vector<int>&piles,int i,int j,vector<vector<int>>&dp){
       if(i>j) return 0;
       if(dp[i][j]!=-1) return dp[i][j];
       if((j-i+1)%2==0){
        return dp[i][j]=max(piles[i]+solve(piles,i+1,j,dp),piles[j]+solve(piles,i,j-1,dp));
       }
       else{
        return dp[i][j]=min(-piles[i]+solve(piles,i+1,j,dp),-piles[j]+solve(piles,i,j-1,dp));
       }
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(piles,0,n-1,dp)>0;
    }


    //    int flag=1;
    //   int solve(vector<int>&piles,int i,int j,vector<vector<int>>&dp){
    //    if(i>j) return 0;
    //    if(dp[i][j]!=-1) return dp[i][j];
    //    if(flag){
    //    int l=piles[i]+piles(piles,i+1,j);
    //    int r=piles[j]+solve(piles,i,j-1);
    //    return dp[i][j]=max(l,r);
    //    }
    //    else{
    //      int l=piles[i]+piles(piles,i+1,j);
    //    int r=piles[j]+solve(piles,i,j-1);
    //    return dp[i][j]=max(l,r);
    //    }
    // }
    // bool stoneGame(vector<int>& piles) {
    //     int n=piles.size();
    //     int sum=accumulate(piles.begin(),piles.end(),0);
    //     vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    //     int ans=solve(piles,0,n-1,dp);
    //     return ans>sum-ans;
    //}
    
    //  int solve(vector<int>&piles){
    //     int n=piles.size();
    //     int sum=accumulate(piles.begin(),piles.end(),0);
    //     vector<vector<int>>dp(n+2,vector<int>(n+2,0));
    //     for(int i=n-1;i>=0;i--){
    //         for(int j=0;j<=n-1;j++){
    //         if(i>j) continue;
    //         int l=piles[i]+max(dp[i+2][j],dp[i+1][j-1]);
    //         int r=piles[j]+max(dp[i+1][j-1],dp[i][j-2]);
    //         dp[i][j]=max(l,r);
    //         }
    //     }
    //     return sum>sum-dp[0][n-1];
    // }
    // bool stoneGame(vector<int>& piles) {
    //     return solve(piles);
    // }

    //for even piles only

    // bool stoneGame(vector<int>&piles){
    //     return 1;
    // }
};