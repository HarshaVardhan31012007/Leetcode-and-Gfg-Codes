class Solution {
public:
    int solve(vector<int>&stoneValue,int i,int flag,vector<vector<int>>&dp){
        if(i>=stoneValue.size()) return 0;
        if(dp[i][flag]!=-1) return dp[i][flag];
        int sum=0;
        int ans=(flag?INT_MAX:INT_MIN);
        for(int j=1;j<=min(3,(int)stoneValue.size()-i);j++){
           sum+=stoneValue[i+j-1];
           if(!flag)
           ans=max(ans,sum+solve(stoneValue,i+j,!flag,dp));
           else
           ans=min(ans,solve(stoneValue,i+j,!flag,dp));
        }
        return dp[i][flag]=ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        int alice=solve(stoneValue,0,0,dp);
        int t=accumulate(stoneValue.begin(),stoneValue.end(),0);
        int bob=t-alice;
        if(alice>bob) return "Alice";
        else if(bob>alice) return "Bob";
        return "Tie";
    }
};