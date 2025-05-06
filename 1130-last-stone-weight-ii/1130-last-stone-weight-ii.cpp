class Solution {
public:
    int solve(vector<int>& stones,int i,int sum,vector<vector<int>>&dp,int t){
        if(i==stones.size()){
            if(sum<0) return INT_MAX;
            return sum;
        }
        if(dp[i][sum+t]!=-1)
        return dp[i][sum+t];
        int pos=solve(stones,i+1,sum-stones[i],dp,t);
        int neg=solve(stones,i+1,sum+stones[i],dp,t);
        return dp[i][sum+t]=min(pos,neg);
    }
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        int t=accumulate(stones.begin(),stones.end(),0);
        vector<vector<int>>dp(n+1,vector<int>(2*t+1,-1));
        return solve(stones,0,0,dp,t);
    }
};