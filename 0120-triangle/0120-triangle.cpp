class Solution {
public:
    // int solve(vector<vector<int>>& triangle,int i,int j,vector<vector<int>>&dp){
    //     if(i==triangle.size()) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int l=triangle[i][j]+solve(triangle,i+1,j,dp);
    //     int r=triangle[i][j]+solve(triangle,i+1,j+1,dp);
    //     return dp[i][j]=min(l,r);
    // }
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     vector<vector<int>>dp(triangle.size()+1,vector<int>(triangle.size()+1,-1));
    //    return solve(triangle,0,0,dp);
    //}
     


    //  int solve(vector<vector<int>>&dp,vector<vector<int>>& triangle){
    //     for(int i=triangle.size()-1;i>=0;i--){
    //         for(int j=i;j>=0;j--){
    //             int l=triangle[i][j]+dp[i+1][j];
    //             int r=triangle[i][j]+dp[i+1][j+1];
    //             dp[i][j]=min(l,r);
    //         }
    //     }
    //     return dp[0][0];
    // }
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     vector<vector<int>>dp(triangle.size()+1,vector<int>(triangle.size()+1,0));
    //    return solve(dp,triangle);
    // }


    //  int solve(vector<vector<int>>& triangle){
    //     vector<int>curr(triangle.size()+1,0);
    //     vector<int>next(triangle.size()+1,0);
    //     for(int i=triangle.size()-1;i>=0;i--){
    //         for(int j=i;j>=0;j--){
    //             int l=triangle[i][j]+next[j];
    //             int r=triangle[i][j]+next[j+1];
    //             curr[j]=min(l,r);
    //         }
    //         next=curr;
    //     }
    //     return curr[0];
    // }
    // int minimumTotal(vector<vector<int>>& triangle) {
    //    return solve(triangle);
    // }


    int solve(vector<vector<int>>& triangle){
        vector<int>curr(triangle.size()+1,0);
        for(int i=triangle.size()-1;i>=0;i--){
            for(int j=0;j<=i;j++){
                int l=triangle[i][j]+curr[j];
                int r=triangle[i][j]+curr[j+1];
                curr[j]=min(l,r);
            }
        }
        return curr[0];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
       return solve(triangle);
    }
};