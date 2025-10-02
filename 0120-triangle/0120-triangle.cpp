class Solution {
public:
    // int solve(vector<vector<int>>& triangle,int i,int j,vector<vector<int>>&dp){
    //     if(i==triangle.size()) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int l=triangle[i][j]+solve(triangle,i+1,j,dp);
    //     int r=triangle[i][j+1]+solve(triangle,i+1,j+1,dp);
    //     return dp[i][j]=min(l,r);
    // }
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int i=1;
    //     int j=0;
    //     vector<vector<int>>dp(triangle.size()+1,vector<int>(triangle.size()+1,-1));
    //    return triangle[0][0]+solve(triangle,i,j,dp);
    // }


     int solve(vector<vector<int>>&dp,vector<vector<int>>& triangle){
        for(int i=triangle.size()-1;i>=0;i--){
            for(int j=i;j>=0;j--){
                int l=triangle[i][j]+dp[i+1][j];
                int r=triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(l,r);
            }
        }
        return dp[0][0];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>dp(triangle.size()+1,vector<int>(triangle.size()+1,0));
       return solve(dp,triangle);
    }
};