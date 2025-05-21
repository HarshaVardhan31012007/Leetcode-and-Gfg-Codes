class Solution {
public:
    // int solve(vector<int>& values,int s,int e,vector<vector<int>>&dp){
    //     if(s+1==e) return 0;
    //     if(dp[s][e]!=-1) return dp[s][e];
    //     int ans=INT_MAX;
    //     for(int j=s+1;j<e;j++){
    //         ans=min(ans,values[s]*values[e]*values[j]+solve(values,s,j,dp)+solve(values,j,e,dp));
    //     }
    //     return dp[s][e]=ans;
    // }
    // int minScoreTriangulation(vector<int>& values) {
    //    vector<vector<int>>dp(values.size()+1,vector<int>(values.size()+1,-1));
    //    return solve(values,0,values.size()-1,dp);
    // }

     int solve(vector<int>& values,vector<vector<int>>&dp){
        for(int s=values.size()-1;s>=0;s--){
            for(int e=s+2;e<values.size();e++){
                int ans=INT_MAX;
                for(int j=s+1;j<e;j++){
                    ans=min(ans,values[s]*values[e]*values[j]+dp[s][j]+dp[j][e]);
                }
                dp[s][e]=ans;
            }
        }
        return dp[0][values.size()-1];
    }
    int minScoreTriangulation(vector<int>& values) {
       vector<vector<int>>dp(values.size()+1,vector<int>(values.size()+1,0));
       return solve(values,dp);
    }
};