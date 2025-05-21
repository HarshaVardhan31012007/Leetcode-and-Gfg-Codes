class Solution {
public:
    // int solve(vector<int>&obstacles,int i,int lane,vector<vector<int>>&dp){
    //     if(i==obstacles.size()-1) return 0;
    //     if(dp[i][lane]!=-1) return dp[i][lane];
    //     if(i+1<obstacles.size()&&obstacles[i+1]!=lane){
    //         return dp[i][lane]=solve(obstacles,i+1,lane,dp);
    //     }
    //     else{
    //         if(obstacles[i]!=0){
    //         int a=6-obstacles[i]-obstacles[i+1];
    //         return dp[i][lane]=1+solve(obstacles,i+1,a,dp);
    //         }
    //         else{
    //             int a=1e9;
    //             int b=1e9;
    //             int c=1e9;
    //             if(1!=obstacles[i+1])
    //             a=1+solve(obstacles,i+1,1,dp);
    //             if(2!=obstacles[i+1])
    //             b=1+solve(obstacles,i+1,2,dp);
    //             if(3!=obstacles[i+1])
    //             c=1+solve(obstacles,i+1,3,dp);
    //             return dp[i][lane]=min({a,b,c});
    //         }
    //     }
    // }
    // int minSideJumps(vector<int>& obstacles) {
    //    vector<vector<int>>dp(obstacles.size()+1,vector<int>(4,-1));
    //    return solve(obstacles,0,2,dp); 
    // }



     int solve(vector<int>&obstacles,int i,int lane,vector<vector<int>>&dp){
        if(i==obstacles.size()-1) return 0;
        if(dp[i][lane]!=-1) return dp[i][lane];
        if(obstacles[i+1]!=lane){
            return dp[i][lane]=solve(obstacles,i+1,lane,dp);
        }
        else{
              int ans=INT_MAX;
              for(int j=1;j<=3;j++){
                 if(lane!=j&&obstacles[i]!=j)
                 ans=min(ans,1+solve(obstacles,i+1,j,dp));
              }
              return dp[i][lane]=ans;
        }
    }
    int minSideJumps(vector<int>& obstacles) {
       vector<vector<int>>dp(obstacles.size()+1,vector<int>(4,-1));
       return solve(obstacles,0,2,dp); 
    }
};