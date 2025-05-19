class Solution {
public:
    //   int solve(vector<int>&prices,int k){
    //       vector<vector<int>>curr(2,vector<int>(k+1,0));
    //       vector<vector<int>>next(2,vector<int>(k+1,0));
    //     for(int i=prices.size()-1;i>=0;i--){
    //         for(int flag=0;flag<=1;flag++){
    //             for(int limit=1;limit<=k;limit++){
    //                 int profit=0;
    //                 if(flag)
    //                 profit=max(profit,-prices[i]+next[0][limit]);
    //                 else
    //                 profit=max(profit,prices[i]+next[1][limit-1]);
    //                 profit=max(profit,next[flag][limit]);
    //                 curr[flag][limit]=profit;
    //             }
    //         }
    //         next=curr;
    //     }
    //     return curr[1][k];
    //  }
    // int maxProfit(int k, vector<int>& prices) {
    //      return solve(prices,k);
    // }



    // int solve(vector<int>&prices,int op,int i,int k,vector<vector<int>>&dp){
    //     if(i==prices.size()||op==2*k) return 0;
    //     if(dp[i][op]!=-1) return dp[i][op];
    //     int profit=0;
    //     if(op%2==0)
    //     profit=max(profit,-prices[i]+solve(prices,op+1,i+1,k,dp));
    //     else
    //     profit=max(profit,prices[i]+solve(prices,op+1,i+1,k,dp));
    //     profit=max(profit,solve(prices,op,i+1,k,dp));
    //     return dp[i][op]=profit;
    // }
    // int maxProfit(int k, vector<int>& prices) {
    //      vector<vector<int>>dp(prices.size()+1,vector<int>(2*k+1,-1));
    //      return solve(prices,0,0,k,dp);
    // }


     int solve(vector<int>&prices,int k,vector<vector<int>>&dp){
        for(int i=prices.size()-1;i>=0;i--){
            for(int op=2*k-1;op>=0;op--){
        int profit=0;
        if(op%2==0)
        profit=max(profit,-prices[i]+dp[i+1][op+1]);
        else
        profit=max(profit,prices[i]+dp[i+1][op+1]);
        profit=max(profit,dp[i+1][op]);
        dp[i][op]=profit;
        }
        }
        return dp[0][0];
    }
    int maxProfit(int k, vector<int>& prices) {
         vector<vector<int>>dp(prices.size()+1,vector<int>(2*k+1,0));
         return solve(prices,k,dp);
    }
};