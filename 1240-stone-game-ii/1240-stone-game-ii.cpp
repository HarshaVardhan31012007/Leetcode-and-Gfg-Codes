class Solution {
public:
    // int solve(vector<int>&piles,int m,int k,int flag,vector<vector<vector<int>>>&dp){
    //     if(k==piles.size()) return 0;
    //     if(dp[m][k][flag]!=-1) return dp[m][k][flag];
    //     int ans=flag==1?INT_MIN:INT_MAX;
    //     int total=0;
    //     for(int i=1;i<=2*m;i++){
    //         if((k+i-1)>=piles.size()) break;
    //         total+=piles[k+i-1];
    //         if(flag)
    //         ans=max(ans,total+solve(piles,max(m,i),k+i,!flag,dp));
    //         else
    //         ans=min(ans,solve(piles,max(m,i),k+i,!flag,dp));
    //     }
    //     return dp[m][k][flag]=ans;
    // }
    // int stoneGameII(vector<int>& piles) {
    //     int m=1;
    //     vector<vector<vector<int>>>dp(piles.size()+1,vector<vector<int>>(piles.size()+1,vector<int>(2,-1)));
    //     return solve(piles,m,0,1,dp);
    // }



     int solve(vector<int>&piles){
      int m=1;
      vector<vector<vector<int>>>dp(piles.size()+1,vector<vector<int>>(piles.size()+1,vector<int>(2,0)));
      for(int k=piles.size()-1;k>=0;k--){
        for(int m=piles.size();m>=1;m--){
            for(int flag=0;flag<=1;flag++){
                    int ans=flag==1?INT_MIN:INT_MAX;
                    int total=0;
                    for(int i=1;i<=2*m;i++){
                        if((k+i-1)>=piles.size()) break;
                        total+=piles[k+i-1];
                        if(flag)
                        ans=max(ans,total+dp[k+i][max(m,i)][!flag]);
                        else
                        ans=min(ans,dp[k+i][max(m,i)][!flag]);
                    }
                    dp[k][m][flag]=ans;
            }
        }
      }
      return dp[0][1][1];
    }
    int stoneGameII(vector<int>& piles) {
        return solve(piles);
    }
};