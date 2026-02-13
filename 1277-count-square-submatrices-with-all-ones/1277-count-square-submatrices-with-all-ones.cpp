// class Solution {
// public:
//     int count;
//     int solve(vector<vector<int>>&matrix,int i,int j,int m,int n,vector<vector<int>>&dp){
//         if(i<0||j<0||i>=m||j>=n) return 0;
//         if(dp[i][j]!=-1) return dp[i][j];
//         int right=solve(matrix,i,j+1,m,n,dp);
//         int down=solve(matrix,i+1,j,m,n,dp);
//         int diagonal=solve(matrix,i+1,j+1,m,n,dp);
//         if(matrix[i][j]==1){
//             int mini=min(right,min(down,diagonal));
//             dp[i][j]=1+mini;
//             count+=dp[i][j];
//             return dp[i][j];
//         }
//         else
//         return dp[i][j]=0;
//     }
//     int countSquares(vector<vector<int>>& matrix) {
//         int m=matrix.size();int n=matrix[0].size();
//         vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
//         count=0;int i=0;int j=0;
//         solve(matrix,i,j,m,n,dp);
//         return count;
//     }
// };





class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size();int n=matrix[0].size();
        vector<vector<int>>prefix(m+1,vector<int>(n+1,0));\
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                prefix[i][j]=matrix[i-1][j-1]+prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
            }
        }
        int ans=0;
        for(int side=1;side<=min(n,m);side++){
            for(int i=1;i+side-1<=m;i++){
                for(int j=1;j+side-1<=n;j++){
                    int sum=prefix[i+side-1][j+side-1]-prefix[i+side-1][j-1]-prefix[i-1][j+side-1]+prefix[i-1][j-1];
                      if(side*side==sum)
                      ans++;
                }
            }
        }
        return ans;
    }
};