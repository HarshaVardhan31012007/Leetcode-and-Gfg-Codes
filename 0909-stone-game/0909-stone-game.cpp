class Solution {
public:
    //for even and odd no of piles

    // int solve(vector<int>&piles,int i,int j,vector<vector<int>>&dp){
    //    if(i>j) return 0;
    //    if(dp[i][j]!=-1) return dp[i][j];
    //    if((j-i+1)%2==0){
    //     return dp[i][j]=max(piles[i]+solve(piles,i+1,j,dp),piles[j]+solve(piles,i,j-1,dp));
    //    }
    //    else{
    //     return dp[i][j]=min(-piles[i]+solve(piles,i+1,j,dp),-piles[j]+solve(piles,i,j-1,dp));
    //    }
    // }
    // bool stoneGame(vector<int>& piles) {
    //     int n=piles.size();
    //     vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    //     return solve(piles,0,n-1,dp)>0;
    // }


    
     int solve(vector<int>&piles){
       int n=piles.size();
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=n-1;j++){
                if(i>j) continue;
                    if((j-i+1)%2==0){
        dp[i+1][j+1]=max(piles[i]+dp[i+2][j+1],piles[j]+dp[i+1][j]);
       }
       else{
        dp[i+1][j+1]=min(-piles[i]+dp[i+2][j+1],-piles[j]+dp[i+1][j]);
            }
        }
        }
        return dp[1][n];
    }
    bool stoneGame(vector<int>& piles) {
        return solve(piles)>0;
    }

    //for even piles only

    // bool stoneGame(vector<int>&piles){
    //     return 1;
    // }
};