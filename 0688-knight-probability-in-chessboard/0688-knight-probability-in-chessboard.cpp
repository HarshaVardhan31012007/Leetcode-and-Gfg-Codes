class Solution {
public:
    // unordered_map<int,unordered_map<int,double>>mpp;
    // double solve(int n,int k,int row,int col){
    //     if(row<0||col<0||row>=n||col>=n) return 0;
    //     if(k==0) {
    //         return 1;
    //     }
    //     if(mpp[k][n*row+col]) return mpp[k][n*row+col];
    //     //if(mpp[k].count(n*row+col)) return mpp[k][n*row+col];// this is recommended as sometimes value is actually zero  ex:- in 3*3 marrix horse at centre
    //     return mpp[k][n*row+col]=(solve(n,k-1,row+1,col-2)+solve(n,k-1,row-1,col-2)+solve(n,k-1,row-2,col-1)+solve(n,k-1,row+2,col-1)+solve(n,k-1,row-2,col+1)+solve(n,k-1,row+2,col+1)+solve(n,k-1,row+1,col+2)+solve(n,k-1,row-1,col+2))/8.0;
    // }
    // double knightProbability(int n, int k, int row, int col) {
    //     double ans=solve(n,k,row,col);
    //     return ans;
    // }



    double solve(int n,int k,int row,int col,vector<vector<double>>&dp){
        if(row<0||col<0||row>=n||col>=n) return 0;
        if(k==0) {
            return 1;
        }
        if(dp[k][n*row+col]!=-1) return dp[k][n*row+col];
        return dp[k][n*row+col]=(solve(n,k-1,row+1,col-2,dp)+solve(n,k-1,row-1,col-2,dp)+solve(n,k-1,row-2,col-1,dp)+solve(n,k-1,row+2,col-1,dp)+solve(n,k-1,row-2,col+1,dp)+solve(n,k-1,row+2,col+1,dp)+solve(n,k-1,row+1,col+2,dp)+solve(n,k-1,row-1,col+2,dp))/8.0;
    }
    double knightProbability(int n, int k, int row, int col) {
        vector<vector<double>>dp(k+1,vector<double>(n*n,-1));
        double ans=solve(n,k,row,col,dp);
        return ans;
    }
};