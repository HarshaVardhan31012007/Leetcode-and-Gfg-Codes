// User function Template for C++
class Solution {
  public:
    pair<int,int>solve(string &s,int i,int j,vector<vector<pair<int,int>>>&dp){
        if(i==j) return {s[i]=='T',s[i]=='F'};
        if(dp[i][j].first!=-1&&dp[i][j].second!=-1) return dp[i][j];
        int t=0;int f=0;
        for(int k=i;k<j;k++){
            if(s[k]=='&'){
                auto l=solve(s,i,k-1,dp);
                auto r=solve(s,k+1,j,dp);
                int lT=l.first;int lF=l.second;
                int rT=r.first;int rF=r.second;
                t+=lT*rT;
                f+=lT*rF+lF*rT+lF*rF;
            }
            else if(s[k]=='|'){
                auto l=solve(s,i,k-1,dp);
                auto r=solve(s,k+1,j,dp);
                int lT=l.first;int lF=l.second;
                int rT=r.first;int rF=r.second;
                t+=lT*rT+lT*rF+lF*rT;
                f+=lF*rF;
            }
            else if(s[k]=='^'){
                auto l=solve(s,i,k-1,dp);
                auto r=solve(s,k+1,j,dp);
                int lT=l.first;int lF=l.second;
                int rT=r.first;int rF=r.second;
                t+=lT*rF+lF*rT;
                f+=lF*rF+lT*rT;
            }
        }
        return dp[i][j]={t,f};
    }
    int countWays(string &s) {
        int n=s.length();
        vector<vector<pair<int,int>>>dp(n+1,vector<pair<int,int>>(n+1,make_pair(-1,-1)));
        auto ans=solve(s,0,n-1,dp);
        return ans.first;
    }
};