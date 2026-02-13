class Solution {
public:
    int count;
    int solve(vector<vector<int>>&matrix,int i,int j,int m,int n,vector<vector<int>>&dp){
        if(i<0||j<0||i>=m||j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int right=solve(matrix,i,j+1,m,n,dp);
        int down=solve(matrix,i+1,j,m,n,dp);
        int diagonal=solve(matrix,i+1,j+1,m,n,dp);
        if(matrix[i][j]==1){
            int mini=min(right,min(down,diagonal));
            dp[i][j]=1+mini;
            count+=dp[i][j];
            return dp[i][j];
        }
        else
        return dp[i][j]=0;
    }
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size();int n=matrix[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        count=0;int i=0;int j=0;
        solve(matrix,i,j,m,n,dp);
        return count;
    }
};