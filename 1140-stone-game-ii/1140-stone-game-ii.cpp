class Solution {
public:
    // int solve(vector<int>&piles,int i,int M,int flag,vector<vector<vector<int>>>&dp){
    //     if(i>=piles.size()) return 0;
    //     if(dp[i][M][flag]!=-1) return dp[i][M][flag];
    //     int sum=0;
    //     int ans=(flag?INT_MAX:0);
    //     for(int j=1;j<=min(2*M,(int)piles.size()-i);j++){
    //        sum+=piles[i+j-1];
    //        if(!flag)
    //        ans=max(ans,sum+solve(piles,i+j,max(M,j),!flag,dp));
    //        else
    //        ans=min(ans,solve(piles,i+j,max(M,j),!flag,dp));
    //     }
    //     return dp[i][M][flag]=ans;
    // }
    // int stoneGameII(vector<int>& piles) {
    //     int n=piles.size();
    //     vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,vector<int>(2,-1)));
    //     return solve(piles,0,1,0,dp);
    // }




    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,vector<int>(2,0)));
        for(int i=n-1;i>=0;i--){
            for(int M=n;M>=1;M--){
                for(int flag=1;flag>=0;flag--){
                        int sum=0;
                        int ans=(flag?INT_MAX:0);
                        for(int j=1;j<=min(2*M,(int)piles.size()-i);j++){
                        sum+=piles[i+j-1];
                        if(!flag)
                        ans=max(ans,sum+dp[i+j][max(M,j)][!flag]);
                        else
                        ans=min(ans,dp[i+j][max(M,j)][!flag]);
                        }
                        dp[i][M][flag]=ans;
                }
            }
        }
        return dp[0][1][0];
    }
};