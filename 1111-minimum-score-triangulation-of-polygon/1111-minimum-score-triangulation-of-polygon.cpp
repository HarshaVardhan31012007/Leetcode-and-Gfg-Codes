class Solution {
public:
    int solve(vector<int>&values,int s,int e,vector<vector<int>>&dp){
       if(e-s+1<=2) return 0;
       if(dp[s][e]!=-1) return dp[s][e];
        int maxi=INT_MAX;;
        for(int i=s+1;i<e;i++){
             maxi=min(maxi,values[s]*values[i]*values[e]+solve(values,s,i,dp)+solve(values,i,e,dp));
        }
        return dp[s][e]=maxi;
    }
    int minScoreTriangulation(vector<int>& values) {
        vector<vector<int>>dp(values.size()+1,vector<int>(values.size()+1,-1));
        return solve(values,0,values.size()-1,dp);
    }
};