class Solution {
public:
    // int solve(vector<vector<int>>&grid,int col,int m,int n,int prev,vector<vector<int>>&dp){
    //     if(col>=n) return 0;
    //     if(dp[col][prev]!=-1) return dp[col][prev];
    //     int minAns=INT_MAX;
    //     for(int digit=0;digit<=9;digit++){
    //         if(digit==prev) continue;
    //         int cost=0;
    //         for(int i=0;i<m;i++){
    //             if(grid[i][col]!=digit) cost++;
    //         }
    //         minAns=min(minAns,cost+solve(grid,col+1,m,n,digit,dp));
    //     }
    //     return minAns;
    // }
    // int minimumOperations(vector<vector<int>>& grid) {
    //     int m=grid.size();
    //     int n=grid[0].size();
    //     vector<vector<int>>dp(n,vector<int>(11,-1));
    //     return solve(grid,0,m,n,10,dp);
    // }


    vector<vector<int>>freq;
    int solve(vector<vector<int>>&grid,int col,int m,int n,int prev,vector<vector<int>>&dp){
        if(col>=n) return 0;
        if(dp[col][prev]!=-1) return dp[col][prev];
        int minAns=INT_MAX;
        for(int digit=0;digit<=9;digit++){
            if(digit==prev) continue;
            minAns=min(minAns,(m-freq[col][digit])+solve(grid,col+1,m,n,digit,dp));
        }
        return dp[col][prev]=minAns;
    }
    int minimumOperations(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(10,-1));
        freq.assign(n,vector<int>(10,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                freq[j][grid[i][j]]++;
            }
        }
        int mini=INT_MAX;
        for(int i=0;i<10;i++)
        mini=min(mini,(m-freq[0][i])+solve(grid,1,m,n,i,dp));
        return mini;
    }
};