class Solution {
public:
    int solve(vector<vector<char>>& matrix,int i,int j,int row,int col,vector<vector<int>>&dp,int &maxi){
       if(i>=row||j>=col) return 0;
       if(dp[i][j]!=-1) return dp[i][j];
       int right=solve(matrix,i,j+1,row,col,dp,maxi);
       int diagonal=solve(matrix,i+1,j+1,row,col,dp,maxi);
       int down=solve(matrix,i+1,j,row,col,dp,maxi);
       if(matrix[i][j]=='1'){
           dp[i][j]=1+min(right,min(diagonal,down));
           maxi=max(maxi,dp[i][j]);
           return dp[i][j];
       }
       else{
        return dp[i][j]=0;
       }
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>>dp(matrix.size()+1,vector<int>(matrix[0].size()+1,-1));
        int maxi=0;
        solve(matrix,0,0,matrix.size(),matrix[0].size(),dp,maxi);
        return maxi*maxi;
    }
};