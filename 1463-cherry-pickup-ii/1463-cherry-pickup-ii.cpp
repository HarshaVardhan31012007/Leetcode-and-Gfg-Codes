class Solution {
public:
    int solve(vector<vector<int>>&grid,int i,int j1,int j2,vector<vector<vector<int>>>&dp){
        if(i==grid.size()-1) return grid[i][j1]+grid[i][j2];
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int ans=0;
        for(int k=-1;k<=1;k++){
            for(int p=-1;p<=1;p++){
                int j3=j1+k;int j4=j2+p;
                if(j3<0||j4<0||j3>=grid[0].size()||j4>=grid[0].size()) continue;
                if(j3!=j4)
                ans=max(ans,grid[i][j1]+grid[i][j2]+solve(grid,i+1,j3,j4,dp));
            }
        }
        return dp[i][j1][j2]=ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();int n=grid[0].size();
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(n+1,-1)));
        return solve(grid,0,0,n-1,dp);
    }
};