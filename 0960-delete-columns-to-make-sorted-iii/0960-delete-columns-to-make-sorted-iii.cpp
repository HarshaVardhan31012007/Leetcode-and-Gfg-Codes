class Solution {
public: 
    bool check(vector<string>& strs,int c,int p,int m){
        for(int i=0;i<m;i++){
            if(strs[i][p]>strs[i][c])
            return false;
        }
        return true;
    }
    int solve(int i,int prev,vector<string>& strs,int m,int n,vector<vector<int>>&dp){
         if(i>=n) return 0;
         if(dp[i][prev+1]!=-1) return dp[i][prev+1];
         int inc=0;
         if(prev==-1||check(strs,i,prev,m)){
             inc=1+solve(i+1,i,strs,m,n,dp);
         } 
         int exc=solve(i+1,prev,strs,m,n,dp);
         return dp[i][prev+1]=max(inc,exc);
    }
    int minDeletionSize(vector<string>& strs) {
        int m=strs.size();
        int n=strs[0].size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return n-solve(0,-1,strs,m,n,dp);
    }
};