class Solution {
public:
    // int solve(vector<int>&stones,int i,int sum,int t,vector<vector<int>>&dp){
    //     if(i==stones.size()){
    //         if(sum<0) return INT_MAX;
    //         return sum;
    //     }
    //     if(dp[i][sum+t]!=-1) return dp[i][sum+t];
    //     int pos=solve(stones,i+1,sum+stones[i],t,dp);
    //     int neg=solve(stones,i+1,sum-stones[i],t,dp);
    //     return dp[i][sum+t]=min(pos,neg);
    // }
    // int lastStoneWeightII(vector<int>& stones) {
    //     int n=stones.size();
    //     int t=accumulate(stones.begin(),stones.end(),0);
    //     vector<vector<int>>dp(n+1,vector<int>(2*t+1,-1));
    //     return solve(stones,0,0,t,dp);
    // }


    // int solve(vector<int>& stones){
    //     int n=stones.size();
    //     int t=accumulate(stones.begin(),stones.end(),0);
    //     vector<vector<int>>dp(n+1,vector<int>(2*t+1,INT_MAX));
    //     for(int j=0;j<=t;j++)
    //     dp[n][j+t]=j;
    //     for(int i=n-1;i>=0;i--){
    //         for(int j=t;j>=-t;j--){
    //             int pos=INT_MAX;
    //             if(j+stones[i]<=t)
    //             pos=dp[i+1][j+stones[i]+t];
    //             int neg=INT_MAX;
    //             if(j-stones[i]>=-t)
    //             neg=dp[i+1][j-stones[i]+t];
    //             dp[i][j+t]=min(pos,neg);
    //         }
    //     }
    //     return dp[0][t];
    // }
    // int lastStoneWeightII(vector<int>& stones) {
    //     return solve(stones);
    // }



    //  int solve(vector<int>& stones){
    //     int n=stones.size();
    //     int t=accumulate(stones.begin(),stones.end(),0);
    //     vector<int>next(2*t+1,INT_MAX);
    //     vector<int>curr(2*t+1,INT_MAX);
    //     for(int j=0;j<=t;j++)
    //     next[j+t]=j;
    //     for(int i=n-1;i>=0;i--){
    //         for(int j=t;j>=-t;j--){
    //             int pos=INT_MAX;
    //             if(j+stones[i]<=t)
    //             pos=next[j+stones[i]+t];
    //             int neg=INT_MAX;
    //             if(j-stones[i]>=-t)
    //             neg=next[j-stones[i]+t];
    //             curr[j+t]=min(pos,neg);
    //         }
    //         next=curr;
    //     }
    //     return next[t];
    // }
    // int lastStoneWeightII(vector<int>& stones) {
    //     return solve(stones);
    // }


  //METHOD 2



    //   int solve(vector<int>&stones,int i,int sum,int &t,vector<vector<int>>&dp){
    //      if(i==stones.size()){
    //         return abs(sum-t+sum);
    //      }
    //      if(dp[i][sum]!=-1) return dp[i][sum];
    //      int inc=solve(stones,i+1,sum+stones[i],t,dp);
    //      int exc=solve(stones,i+1,sum,t,dp);
    //      return dp[i][sum]=min(inc,exc);
    //   }
    //   int lastStoneWeightII(vector<int>& stones) {
    //       int n=stones.size();
    //       int t=accumulate(stones.begin(),stones.end(),0);
    //       vector<vector<int>>dp(n+1,vector<int>(t+1,-1));
    //       return solve(stones,0,0,t,dp);
     // }



      int solve(vector<int>&stones){
         int n=stones.size();
         int t=accumulate(stones.begin(),stones.end(),0);
         vector<vector<int>>dp(n+1,vector<int>(t+1,INT_MAX));
         for(int i=0;i<=t;i++){
            dp[n][i]=abs(i-t+i);
         }
         for(int i=n-1;i>=0;i--){
            for(int j=t;j>=0;j--){
                int inc=INT_MAX;
                if(j+stones[i]<=t){
                    inc=dp[i+1][j+stones[i]];
                }
                int exc=dp[i+1][j];
                dp[i][j]=min(inc,exc);
            }
         }
         return dp[0][0];
      }
      int lastStoneWeightII(vector<int>& stones) {
        return solve(stones);
      }


    //   int solve(vector<int>&nums){
    //    int n=nums.size();
    //     int t=accumulate(nums.begin(),nums.end(),0);
    //     vector<int>curr(t+1,0);
    //     vector<int>next(t+1,0);
    //     for(int j=0;j<=t;j++){
    //         next[j]=abs(j-t+j);
    //     }
    //     for(int i=n-1;i>=0;i--){
    //         // for(int j=t-1;j>=0;j--){// or
    //             for(int j=t;j>=0;j--){
    //                  int l=INT_MAX;
    //                  if(j+nums[i]<=t)
    //                 l=next[j+nums[i]];
    //                 int r=next[j];
    //                 curr[j]=min(l,r);
    //         }
    //         next=curr;
    //     }
    //     return next[0];
    //   }
    //   int lastStoneWeightII(vector<int>& stones) {
    //     return solve(stones);
    //   }


    //    int solve(vector<int>&nums){
    //    int n=nums.size();
    //     int t=accumulate(nums.begin(),nums.end(),0);
    //     vector<int>curr(t+1,0);
    //     for(int j=0;j<=t;j++){
    //         curr[j]=abs(j-t+j);
    //     }
    //     for(int i=n-1;i>=0;i--){
    //         // for(int j=t-1;j>=0;j--){// or
    //             for(int j=0;j<=t;j++){
    //                  int l=INT_MAX;
    //                  if(j+nums[i]<=t)
    //                 l=curr[j+nums[i]];
    //                 int r=curr[j];
    //                 curr[j]=min(l,r);
    //         }
    //     }
    //     return curr[0];
    //   }
    //   int lastStoneWeightII(vector<int>& stones) {
    //     return solve(stones);
    //   }
};