class Solution {
public:
    // int solve(vector<int>&slices,int i,int n,int endIndex,vector<vector<int>>&dp){
    //     if(n==0||i>endIndex) return 0; 
    //     if(dp[i][n]!=-1) return dp[i][n];
    //     int l=slices[i]+solve(slices,i+2,n-1,endIndex,dp);
    //     int r=solve(slices,i+1,n,endIndex,dp);
    //     return dp[i][n]=max(l,r);
    // }
    // int maxSizeSlices(vector<int>& slices) {
    //     vector<vector<int>>dp(slices.size()+1,vector<int>(slices.size()/3+1,-1));
    //     vector<vector<int>>dp1(slices.size()+1,vector<int>(slices.size()/3+1,-1));
    //     return max(solve(slices,0,slices.size()/3,slices.size()-2,dp),solve(slices,1,slices.size()/3,slices.size()-1,dp1));
    // }


    int solve(vector<int>&slices,int s,int e){
         vector<vector<int>>dp(slices.size()+2,vector<int>((slices.size()/3)+1,0));
         for(int i=e;i>=s;i--){
            for(int n=1;n<=(slices.size()/3);n++){
                    int l=slices[i]+dp[i+2][n-1];
                    int r=dp[i+1][n];
                    dp[i][n]=max(l,r);
            }
         }
         return dp[s][slices.size()/3];
    }
    int maxSizeSlices(vector<int>& slices) {
        return max(solve(slices,0,slices.size()-2),solve(slices,1,slices.size()-1));
    }
};