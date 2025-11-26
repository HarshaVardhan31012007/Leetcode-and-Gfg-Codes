class Solution {
public:
    // const int mod=1e9+7;
    // int solve(vector<vector<int>>&grid,int i,int j,int rem,int k,vector<vector<vector<int>>>&dp){
    //     if(i<0||j<0||i>=grid.size()||j>=grid[0].size()) return 0;
    //     if(i==grid.size()-1&&j==grid[0].size()-1){
    //         rem=(rem+((grid[i][j])%k))%k;
    //         if(rem==0) return 1;
    //         return 0;
    //     }
    //     if(dp[i][j][rem]!=-1) return dp[i][j][rem];
    //     int right=solve(grid,i,j+1,(rem+((grid[i][j])%k))%k,k,dp);
    //     int down=solve(grid,i+1,j,(rem+((grid[i][j])%k))%k,k,dp);
    //     return dp[i][j][rem]=(right+down)%mod;
    // }
    // int numberOfPaths(vector<vector<int>>& grid, int k) {
    //     vector<vector<vector<int>>>dp(grid.size()+1,vector<vector<int>>(grid[0].size()+1,vector<int>(k+1,-1)));
    //     return solve(grid,0,0,0,k,dp);
    // }


    // const int mod=1e9+7;
    // int solve(vector<vector<int>>&grid,int k){
    //     vector<vector<vector<int>>>dp(grid.size()+1,vector<vector<int>>(grid[0].size()+1,vector<int>(k+1,0)));
    //     for(int i=grid.size()-1;i>=0;i--){
    //         for(int j=grid[0].size()-1;j>=0;j--){
    //             for(int r=0;r<k;r++){
    //                 int rem=(r+grid[i][j]%k)%k;
    //                 if(i==grid.size()-1&&j==grid[0].size()-1){
    //                     if(rem==0) dp[i][j][r]=1;
    //                     else dp[i][j][r]=0;
    //                     continue;
    //                 }
    //                 int right=dp[i][j+1][rem];
    //                 int down=dp[i+1][j][rem];
    //                 dp[i][j][r]=(right+down)%mod;
    //             }
    //         }
    //     }
    //     return dp[0][0][0];
    // }
    // int numberOfPaths(vector<vector<int>>& grid, int k) {
    //     return solve(grid,k);
    // }




    const int mod=1e9+7;
    int solve(vector<vector<int>>&grid,int k){
        vector<vector<int>>curr(grid[0].size()+1,vector<int>(k+1,0));
        vector<vector<int>>next(grid[0].size()+1,vector<int>(k+1,0));
        for(int i=grid.size()-1;i>=0;i--){
            for(int j=grid[0].size()-1;j>=0;j--){
                for(int r=0;r<k;r++){
                    int rem=(r+grid[i][j]%k)%k;
                    if(i==grid.size()-1&&j==grid[0].size()-1){
                        if(rem==0) curr[j][r]=1;
                        else curr[j][r]=0;
                        continue;
                    }
                    int right=curr[j+1][rem];
                    int down=next[j][rem];
                    curr[j][r]=(right+down)%mod;
                }
            }
            next=curr;
        }
        return curr[0][0];
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        return solve(grid,k);
    }
};