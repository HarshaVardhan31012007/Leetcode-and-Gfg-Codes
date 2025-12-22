class Solution {
public: 
    // bool check(vector<string>& strs,int c,int p,int m){
    //     for(int i=0;i<m;i++){
    //         if(strs[i][p]>strs[i][c])
    //         return false;
    //     }
    //     return true;
    // }
    // int solve(int i,int prev,vector<string>& strs,int m,int n,vector<vector<int>>&dp){
    //      if(i>=n) return 0;
    //      if(dp[i][prev+1]!=-1) return dp[i][prev+1];
    //      int inc=0;
    //      if(prev==-1||check(strs,i,prev,m)){
    //          inc=1+solve(i+1,i,strs,m,n,dp);
    //      } 
    //      int exc=solve(i+1,prev,strs,m,n,dp);
    //      return dp[i][prev+1]=max(inc,exc);
    // }
    // int minDeletionSize(vector<string>& strs) {
    //     int m=strs.size();
    //     int n=strs[0].size();
    //     vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    //     return n-solve(0,-1,strs,m,n,dp);
    // }



    bool check(vector<string>& strs,int c,int p,int m){
        for(int i=0;i<m;i++){
            if(strs[i][p]>strs[i][c])
            return false;
        }
        return true;
    }
    int minDeletionSize(vector<string>& strs) {
        int m=strs.size();
        int n=strs[0].size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){//j is prev
                int inc=0;
                if(j==-1||check(strs,i,j,m)){
                    inc=1+dp[i+1][i+1];//as prev is starts from -1 so shifted it
                } 
                int exc=dp[i+1][j+1];//as prev is starts from -1 so shifted it
                dp[i][j+1]=max(inc,exc);//as prev is starts from -1 so shifted it
            }
        }
        return n-dp[0][0];
    }
};