class Solution {
public:
    // int solve(vector<vector<int>>&matrix,int i,int j,vector<vector<int>>&dp){
    //     if(i==matrix.size()-1) return  dp[i][j]=matrix[i][j];
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int one=1e4,two=1e4,three=1e4;
    //     if(j-1>=0)
    //     one=matrix[i][j]+solve(matrix,i+1,j-1,dp);
    //     two=matrix[i][j]+solve(matrix,i+1,j,dp);
    //     if(j+1<matrix[0].size())
    //     three=matrix[i][j]+solve(matrix,i+1,j+1,dp);
    //     return dp[i][j]=min(one,min(two,three));
    // }
    // int minFallingPathSum(vector<vector<int>>& matrix) {
    //     int m=matrix.size();int n=matrix[0].size();
    //     vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
    //     int ans=1e4;
    //     for(int j=0;j<n;j++){
    //         ans=min(ans,solve(matrix,0,j,dp));
    //     }
    //     return ans;
    // }



    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();int n=matrix[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int one=1e4,two=1e4,three=1e4;
                if(j-1>=0)
                one=matrix[i][j]+dp[i+1][j-1];
                two=matrix[i][j]+dp[i+1][j];
                if(j+1<matrix[0].size())
                three=matrix[i][j]+dp[i+1][j+1];
                dp[i][j]=min(one,min(two,three));
            }
        }
        return *min_element(dp[0].begin(),dp[0].begin()+n);
    }
};