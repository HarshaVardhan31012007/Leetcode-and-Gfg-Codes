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
    //             int a=INT_MAX;
    //             if(1!=obstacles[i+1])
    //             a=min(a,1+solve(obstacles,i+1,1,dp));
    //             if(2!=obstacles[i+1])
    //             a=min(a,1+solve(obstacles,i+1,2,dp));
    //             if(3!=obstacles[i+1])
    //             a=min(a,1+solve(obstacles,i+1,3,dp));
    //             return dp[i][lane]=a;
    //         }
    //     }
    // }
    // int minSideJumps(vector<int>& obstacles) {
    //    vector<vector<int>>dp(obstacles.size()+1,vector<int>(4,-1));
    //    return solve(obstacles,0,2,dp); 
    // }


    // int solve(vector<int>&obstacles,int i,int lane,vector<vector<int>>&dp){
    //     if(i==obstacles.size()-1) return 0;
    //     if(dp[i][lane]!=-1) return dp[i][lane];
    //     if(i+1<obstacles.size()&&obstacles[i+1]!=lane){
    //         return dp[i][lane]=solve(obstacles,i+1,lane,dp);
    //     }
    //     else{
    //             int a=INT_MAX;
    //             if(1!=lane&&1!=obstacles[i])
    //             a=min(a,1+solve(obstacles,i+1,1,dp));
    //             if(2!=lane&&2!=obstacles[i])
    //             a=min(a,1+solve(obstacles,i+1,2,dp));
    //             if(3!=lane&&3!=obstacles[i])
    //             a=min(a,1+solve(obstacles,i+1,3,dp));
    //             return dp[i][lane]=a;
    //     }
    // }
    // int minSideJumps(vector<int>& obstacles) {
    //    vector<vector<int>>dp(obstacles.size()+1,vector<int>(4,-1));
    //    return solve(obstacles,0,2,dp); 
    // }


    //  int solve(vector<int>&obstacles,int i,int lane,vector<vector<int>>&dp){
    //     if(i==obstacles.size()-1) return 0;
    //     if(dp[i][lane]!=-1) return dp[i][lane];
    //     if(obstacles[i+1]!=lane){
    //         return dp[i][lane]=solve(obstacles,i+1,lane,dp);
    //     }
    //     else{
    //           int ans=INT_MAX;
    //           for(int j=1;j<=3;j++){
    //              if(lane!=j&&obstacles[i]!=j)
    //              ans=min(ans,1+solve(obstacles,i+1,j,dp));
    //           }
    //           return dp[i][lane]=ans;
    //     }
    // }
    // int minSideJumps(vector<int>& obstacles) {
    //    vector<vector<int>>dp(obstacles.size(),vector<int>(4,-1));
    //    return solve(obstacles,0,2,dp); 
    // }


    // int solve(vector<int>&obstacles){
    //    vector<vector<int>>dp(obstacles.size(),vector<int>(4,0));
    // //no need initilize all with zeros
    // //    for(int i=0;i<4;i++){
    // //     dp[obstacles.size()-1][i]=0;
    // //    }
    //    for(int i=obstacles.size()-2;i>=0;i--){
    //     for(int lane=1;lane<=3;lane++){
    //         if(obstacles[i+1]!=lane){
    //         dp[i][lane]=dp[i+1][lane];
    //     }
    //     else{
    //           int ans=INT_MAX;
    //           for(int j=1;j<=3;j++){
    //              if(lane!=j&&obstacles[i]!=j)
    //              ans=min(ans,1+dp[i+1][j]);
    //           }
    //           dp[i][lane]=ans;
    //     }
    //     }
    //    }
    //    return dp[0][2];
    // }
    // int minSideJumps(vector<int>& obstacles) {
    //    return solve(obstacles); 
    // }


    int solve(vector<int>&obstacles){
        vector<int>curr(4,0);
        vector<int>next(4,0);
       for(int i=obstacles.size()-2;i>=0;i--){
        for(int lane=1;lane<=3;lane++){
            if(obstacles[i+1]!=lane){
            curr[lane]=next[lane];
        }
        else{
              int ans=INT_MAX;
              for(int j=1;j<=3;j++){
                 if(lane!=j&&obstacles[i]!=j)
                 ans=min(ans,1+next[j]);
              }
              curr[lane]=ans;
        }
        }
        next=curr;
       }
       return curr[2];
    }
    int minSideJumps(vector<int>& obstacles) {
       return solve(obstacles); 
    }
};