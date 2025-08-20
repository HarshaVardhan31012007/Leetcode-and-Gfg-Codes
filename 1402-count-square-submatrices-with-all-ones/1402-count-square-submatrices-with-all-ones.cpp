class Solution {
public:
    int count;
    int solve(vector<vector<int>>&matrix,int row,int col,vector<vector<int>>&dp){
        if(row<0||col<0||row>=matrix.size()||col>=matrix[0].size()) return 0;
        if(dp[row][col]!=-1) return dp[row][col];
        int down=solve(matrix,row+1,col,dp);
        int right=solve(matrix,row,col+1,dp);
        int diagonal=solve(matrix,row+1,col+1,dp);
        if(matrix[row][col]==1){
            int mini=1+min(down,min(right,diagonal));
            count+=mini;
            return dp[row][col]=mini;
        }
        else
        return dp[row][col]=0;
    }
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),-1));
        count=0;
        solve(matrix,0,0,dp);
        return count;
    }
};