class Solution {
public:
    // int solve(vector<int>& stones,int i,int sum,vector<vector<int>>&dp,int t){
    //     if(i==stones.size()){
    //         if(sum<0) return INT_MAX;
    //         return sum;
    //     }
    //     if(dp[i][sum+t]!=-1)
    //     return dp[i][sum+t];
    //     int pos=solve(stones,i+1,sum+stones[i],dp,t);
    //     int neg=solve(stones,i+1,sum-stones[i],dp,t);
    //     return dp[i][sum+t]=min(pos,neg);
    // }
    // int lastStoneWeightII(vector<int>& stones) {
    //     int n=stones.size();
    //     int t=accumulate(stones.begin(),stones.end(),0);
    //     vector<vector<int>>dp(n+1,vector<int>(2*t+1,-1));
    //     return solve(stones,0,0,dp,t);
    // }


    int solve(vector<int>& stones){
        int n=stones.size();
        int t=accumulate(stones.begin(),stones.end(),0);
        vector<vector<int>>dp(n+1,vector<int>(2*t+1,0));
        for(int i=-t;i<=t;i++)
        dp[n][i+t]=(i<0)?INT_MAX:i;
        
        for(int i=n-1;i>=0;i--){
            for(int j=t;j>=-t;j--){
                int pos=INT_MAX;int neg=INT_MAX;
                if(j-stones[i]>=-t)
                neg=dp[i+1][j-stones[i]+t];
                if(j+stones[i]<=t)
                pos=dp[i+1][j+stones[i]+t];
                dp[i][j+t]=min(pos,neg);
            }
        }
        return dp[0][t];
    }
    int lastStoneWeightII(vector<int>& stones) {
        return solve(stones);
    }
};