class Solution {
public:
    // int solve(vector<int>&satisfaction,int i,int time,vector<vector<int>>&dp){
    //     if(i==satisfaction.size()) return 0;
    //     if(dp[i][time]!=-1) return dp[i][time];
    //      int l=satisfaction[i]*time+solve(satisfaction,i+1,time+1,dp);
    //      int r=0;
    //     if(satisfaction[i]<0)//optimization
    //     r=solve(satisfaction,i+1,time,dp);
    //     return dp[i][time]=max(l,r);
    // }
    // int maxSatisfaction(vector<int>& satisfaction) {
    //     sort(satisfaction.begin(),satisfaction.end());
    //     vector<vector<int>>dp(satisfaction.size()+1,vector<int>(satisfaction.size()+1,-1));
    //     return solve(satisfaction,0,1,dp);
    // }


    //  int solve(vector<int>&satisfaction){
    //      vector<vector<int>>dp(satisfaction.size()+1,vector<int>(satisfaction.size()+2,0));
    //     for(int i=satisfaction.size()-1;i>=0;i--){
    //       for(int time=satisfaction.size();time>=1;time--){
    //      int l=satisfaction[i]*time+dp[i+1][time+1];
    //      int r=dp[i+1][time];
    //     dp[i][time]=max(l,r);
    //       }
    //     }
    //     return dp[0][1];
    // }
    // int maxSatisfaction(vector<int>& satisfaction) {
    //     sort(satisfaction.begin(),satisfaction.end());
    //     return solve(satisfaction);
    // }


    int solve(vector<int>&satisfaction){
        vector<int>curr(satisfaction.size()+2,0);
        vector<int>next(satisfaction.size()+2,0);
        for(int i=satisfaction.size()-1;i>=0;i--){
          for(int time=satisfaction.size();time>=1;time--){
         int l=satisfaction[i]*time+next[time+1];
         int r=next[time];
        curr[time]=max(l,r);
          }
          next=curr;
        }
        return curr[1];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        return solve(satisfaction);
    }
};