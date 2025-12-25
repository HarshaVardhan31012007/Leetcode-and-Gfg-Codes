class Solution {
public:
    bool isSafe(vector<vector<int>>&cuboids,int c,int p){
        return cuboids[c][0]>=cuboids[p][0]&&cuboids[c][1]>=cuboids[p][1]&&cuboids[c][2]>=cuboids[p][2];
    }
    int solve(vector<vector<int>>&cuboids,int i,int prev,vector<vector<int>>&dp){
        if(i>=cuboids.size()) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int inc=0;
        if(prev==-1||isSafe(cuboids,i,prev)){
            inc=cuboids[i][2]+solve(cuboids,i+1,i,dp);
        }
        int exc=solve(cuboids,i+1,prev,dp);
        return dp[i][prev+1]=max(inc,exc);
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &each:cuboids)
        sort(each.begin(),each.end());
        sort(cuboids.begin(),cuboids.end());
        vector<vector<int>>dp(cuboids.size()+1,vector<int>(cuboids.size()+1,-1));
        return solve(cuboids,0,-1,dp);
    }
};