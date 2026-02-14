class Solution {
public:
    int solve(vector<int>&obstacles,int i,int lane,vector<vector<int>>&dp){
        if(i==obstacles.size()-1) return 0;
        if(dp[i][lane]!=-1) return dp[i][lane];
        int ans=1e9;
        if(obstacles[i+1]!=lane)
        ans=min(ans,solve(obstacles,i+1,lane,dp));
        if(lane!=1&&obstacles[i]!=1&&obstacles[i+1]!=1){
            ans=min(ans,1+solve(obstacles,i+1,1,dp));
        }
        if(lane!=2&&obstacles[i]!=2&&obstacles[i+1]!=2){
            ans=min(ans,1+solve(obstacles,i+1,2,dp));
        }
        if(lane!=3&&obstacles[i]!=3&&obstacles[i+1]!=3){
            ans=min(ans,1+solve(obstacles,i+1,3,dp));
        }
        return dp[i][lane]=ans;
    }
    int minSideJumps(vector<int>& obstacles) {
        vector<vector<int>>dp(obstacles.size()+1,vector<int>(4,-1));
        return solve(obstacles,0,2,dp);
    }
};