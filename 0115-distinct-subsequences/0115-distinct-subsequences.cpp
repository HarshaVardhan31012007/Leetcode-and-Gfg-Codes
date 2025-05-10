class Solution {
public:
    int solve(string &s,string &t,int i,int j,vector<vector<int>>&dp){
       if(j>=t.size())
         return 1;
       if(i>=s.size()) 
       return 0;
       if(dp[i][j]!=-1)
       return dp[i][j];
       int l=0;
       if(s[i]==t[j])
       l=solve(s,t,i+1,j+1,dp);
       int r=solve(s,t,i+1,j,dp);
       return dp[i][j]=l+r;
    }
    int numDistinct(string s, string t) {
        int m=s.size();int n=t.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(s,t,0,0,dp);
    }
};