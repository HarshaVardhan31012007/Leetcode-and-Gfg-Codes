class Solution {
public:
    // map<pair<int,int>,int>dp;
    // int solve(vector<int>&arr,int i,int b){
    //     if(i==arr.size()) return 0;
    //     if(dp.find({i,b})!=dp.end()) return dp[{i,b}];
    //     int ans=INT_MIN;
    //     if(b==-1)
    //     ans=max(ans,solve(arr,i+1,arr[i]));
    //     else if(arr[i]>b)
    //     ans=max(ans,arr[i]-b+solve(arr,i+1,-1));
    //     ans=max(ans,solve(arr,i+1,b));
    //     return dp[{i,b}]=ans;
    // }
    // int maxProfit(vector<int>& prices) {
    //     return solve(prices,0,-1);
    // }


    //  int solve(vector<int>&prices,int i,int flag,vector<vector<int>>&dp){
    //     if(i==prices.size()) return 0;
    //     if(dp[i][flag]!=-1) return dp[i][flag];
    //     int profit=0;
    //     if(flag)
    //      profit=max(profit,-prices[i]+solve(prices,i+1,0,dp));
    //      else
    //     profit=max(profit,prices[i]+solve(prices,i+1,1,dp));
    //     profit=max(profit,solve(prices,i+1,flag,dp));
    //     return dp[i][flag]=profit;
    //  }
    //  int maxProfit(vector<int>& prices) {
    //     vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
    //     return solve(prices,0,1,dp);
    //  }


    //  int solve(vector<int>&prices){
    //      vector<vector<int>>dp(prices.size()+1,vector<int>(2,0));
    //      for(int i=prices.size()-1;i>=0;i--){
    //         for(int flag=0;flag<=1;flag++){
    //             int profit=0;
    //             if(flag)
    //             profit=max(profit,-prices[i]+dp[i+1][0]);
    //             else
    //             profit=max(profit,prices[i]+dp[i+1][1]);
    //             profit=max(profit,dp[i+1][flag]);
    //             dp[i][flag]=profit;
    //         }
    //      }
    //      return dp[0][1];
    //  }
    //  int maxProfit(vector<int>& prices) {
    //     return solve(prices);
    //  }


    // int solve(vector<int>&prices){
    //      vector<int>curr(2,0);
    //      vector<int>next(2,0);
    //      for(int i=prices.size()-1;i>=0;i--){
    //         for(int flag=0;flag<=1;flag++){
    //             int profit=0;
    //             if(flag)
    //             profit=max(profit,-prices[i]+next[0]);
    //             else
    //             profit=max(profit,prices[i]+next[1]);
    //             profit=max(profit,next[flag]);
    //             curr[flag]=profit;
    //         }
    //         next=curr;
    //      }
    //      return curr[1];
    //  }
    //  int maxProfit(vector<int>& prices) {
    //     return solve(prices);
    //  }

    int maxProfit(vector<int>& prices) {
       int profit=0;
       for(int i=0;i<prices.size()-1;i++){
         if(prices[i]<prices[i+1])
         profit+=prices[i+1]-prices[i];
       }
       return profit;
    }

};