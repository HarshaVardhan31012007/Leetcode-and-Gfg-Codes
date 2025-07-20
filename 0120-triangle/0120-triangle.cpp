class Solution {
public:
    // void solve(vector<vector<int>>&triangle,int &ans,int sum,int i,int col){
    //     if(i==triangle.size()){
    //        ans=min(ans,sum);
    //        return;
    //     }
        
    //     solve(triangle,ans,sum+triangle[i][col],i+1,col);
    //     solve(triangle,ans,sum+triangle[i][col],i+1,col+1);
    
    // }
    // int minimumTotal(vector<vector<int>>& triangle) {  
    //     int ans=INT_MAX;
    //     int sum=0;
    //     int col=0;
    //     solve(triangle,ans,sum,0,col);
    //     return ans;
    // }

    //method2
    // int solve(vector<vector<int>>&triangle,int row,int col,vector<vector<int>>&dp){
    //     // if(row==triangle.size()-1){
    //     //    return triangle[row][col];
    //     // }
    //     if(row==triangle.size()) return 0;
    //     if(dp[row][col]!=-1) return dp[row][col];
    //     int left=triangle[row][col]+solve(triangle,row+1,col,dp);
    //     int right=triangle[row][col]+solve(triangle,row+1,col+1,dp);
    //     return dp[row][col]=min(left,right);
         
    // }
    // int minimumTotal(vector<vector<int>>& triangle) {  
    //     vector<vector<int>>dp(triangle.size()+1,vector<int>(triangle.size()+1,-1));
    //     return solve(triangle,0,0,dp);
    // }


    int solve(vector<vector<int>>&triangle){
         vector<vector<int>>dp(triangle.size()+1,vector<int>(triangle.size()+1,0));
        for(int row=triangle.size()-1;row>=0;row--){
         for(int col=row;col>=0;col--){
        int left=triangle[row][col]+dp[row+1][col];
        int right=triangle[row][col]+dp[row+1][col+1];
        dp[row][col]=min(left,right);
         }
        }
        return dp[0][0];
    }
    int minimumTotal(vector<vector<int>>& triangle) {  
        return solve(triangle);
    }
};