class Solution {
public:
    int solve(vector<vector<int>>&grid,int i,int j,int m,int n,int k,vector<vector<vector<int>>>&dp){
        int r=INT_MIN,d=INT_MIN;
        int cost;
        if(grid[i][j]==0) cost=0;
        else cost=1;
        if(i==m-1&&j==n-1&&k>=cost) return grid[i][j];
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        if(j+1<n&&k>=cost){
           r=grid[i][j]+solve(grid,i,j+1,m,n,k-cost,dp);
        }
        if(i+1<m&&k>=cost){
           d=grid[i][j]+solve(grid,i+1,j,m,n,k-cost,dp);
        }
        return dp[i][j][k]=max(r,d);
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m=grid.size();int n=grid[0].size();
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(k+1,-1)));
        int ans=solve(grid,0,0,m,n,k,dp);
        return ans<0?-1:ans;
    }
};