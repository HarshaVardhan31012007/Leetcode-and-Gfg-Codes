class Solution {
public:
    int solve(vector<int>&stones,int i,int sum,int t,vector<vector<int>>&dp){
        if(i==stones.size()){
            if(sum<0) return INT_MAX;
            return sum;
        }
        if(dp[i][sum+t]!=-1) return dp[i][sum+t];
        int pos=solve(stones,i+1,sum+stones[i],t,dp);
        int neg=solve(stones,i+1,sum-stones[i],t,dp);
        return dp[i][sum+t]=min(pos,neg);
    }
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        int t=accumulate(stones.begin(),stones.end(),0);
        vector<vector<int>>dp(n+1,vector<int>(2*t+1,-1));
        return solve(stones,0,0,t,dp);
    }


    // int solve(vector<int>& stones){
    //     int n=stones.size();
    //     int t=accumulate(stones.begin(),stones.end(),0);
    //     vector<vector<int>>dp(n+1,vector<int>(2*t+1,0));
    //     for(int i=-t;i<=t;i++)
    //     dp[n][i+t]=(i<0)?INT_MAX:i;
        
    //     for(int i=n-1;i>=0;i--){
    //         for(int j=t;j>=-t;j--){
    //         // for(int j=t-1;j>=-t+1;j--){
    //             int pos=INT_MAX;int neg=INT_MAX;
    //             if(j-stones[i]>=-t)
    //             neg=dp[i+1][j-stones[i]+t];
    //             if(j+stones[i]<=t)
    //             pos=dp[i+1][j+stones[i]+t];
    //             dp[i][j+t]=min(pos,neg);
    //         }
    //     }
    //     return dp[0][t];
    //}


    //  int solve(vector<int>& stones){
    //     int n=stones.size();
    //     int t=accumulate(stones.begin(),stones.end(),0);
    //     vector<int>curr(2*t+1,0);
    //     vector<int>next(2*t+1,0);
    //     for(int i=-t;i<=t;i++)
    //     next[i+t]=(i<0)?INT_MAX:i;
        
    //     for(int i=n-1;i>=0;i--){
    //         for(int j=t;j>=-t;j--){
    //             int pos=INT_MAX;int neg=INT_MAX;
    //             if(j-stones[i]>=-t)
    //             neg=next[j-stones[i]+t];
    //             if(j+stones[i]<=t)
    //             pos=next[j+stones[i]+t];
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



    //   int solve(vector<int>&nums,int i,int sum,int t,vector<vector<int>>&dp){
    //     if(i==nums.size()){
    //        return abs(sum-t+sum);
    //     }
    //     if(dp[i][sum]!=-1)
    //     return dp[i][sum];
    //     int l=solve(nums,i+1,sum+nums[i],t,dp);
    //     int r=solve(nums,i+1,sum,t,dp);
    //     return dp[i][sum]=min(l,r);
    //   }
    //   int lastStoneWeightII(vector<int>& stones) {
    //     int n=stones.size();
    //     int t=accumulate(stones.begin(),stones.end(),0);
    //     vector<vector<int>>dp(n+1,vector<int>(t+1,-1));
    //     return solve(stones,0,0,t,dp);
    //   }



    //   int solve(vector<int>&nums){
    //    int n=nums.size();
    //     int t=accumulate(nums.begin(),nums.end(),0);
    //     vector<vector<int>>dp(n+1,vector<int>(t+1,0));
    //     for(int j=0;j<=t;j++){
    //         dp[n][j]=abs(j-t+j);
    //     }
    //     for(int i=n-1;i>=0;i--){
    //         // for(int j=t-1;j>=0;j--){// or
    //             for(int j=t;j>=0;j--){
    //                  int l=INT_MAX;
    //                  if(j+nums[i]<=t)
    //                 l=dp[i+1][j+nums[i]];
    //                 int r=dp[i+1][j];
    //                 dp[i][j]=min(l,r);
    //         }
    //     }
    //     return dp[0][0];
    //   }
    //   int lastStoneWeightII(vector<int>& stones) {
    //     return solve(stones);
    //   }


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