class Solution {
public:
    // bool stoneGame(vector<int>& piles) {
    //     return 1;
    // 
    //}

    // int solve(vector<int>&piles,int i,int j,vector<vector<int>>&dp){
    //     if(i>j) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if((j-i+1)%2==0){
    //         return dp[i][j]=max(piles[i]+solve(piles,i+1,j,dp),piles[j]+solve(piles,i,j-1,dp));
    //     }
    //     else{
    //         return dp[i][j]=min(-piles[i]+solve(piles,i+1,j,dp),-piles[j]+solve(piles,i,j-1,dp));
    //     }
    // }
    // bool stoneGame(vector<int>& piles) {
    //     int n=piles.size();
    //     vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    //     int ans=solve(piles,0,n-1,dp);
    //     return ans>0;
    // }



    int solve(vector<int>&piles,int i,int j,int flag,vector<vector<vector<int>>>&dp){
      if(i>j) return 0;
      if(dp[i][j][flag]!=-1) return dp[i][j][flag];
      if(!flag)
      return dp[i][j][flag]=max(piles[i]+solve(piles,i+1,j,!flag,dp),piles[j]+solve(piles,i,j-1,!flag,dp));
      else
      return dp[i][j][flag]=min(solve(piles,i+1,j,!flag,dp),solve(piles,i,j-1,!flag,dp));
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,vector<int>(2,-1)));
        auto ans=solve(piles,0,n-1,0,dp);
        auto t=accumulate(piles.begin(),piles.end(),0LL);
        return ans>t-ans;
    }
    
};