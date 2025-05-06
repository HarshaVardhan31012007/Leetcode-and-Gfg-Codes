class Solution {
public:
    // bool solve(string &s,string &p,int i,int j){
    //   if(i==s.length()&&j==p.length()) return 1;
    //   if(j==p.length()) return 0;
    //   bool curr=i<s.length()&&(p[j]=='.'||s[i]==p[j]);
    //   if(j+1<p.length()&&p[j+1]=='*'){
    //     int emptycase=solve(s,p,i,j+2);
    //     int precase=curr&&solve(s,p,i+1,j);
    //     return emptycase||precase;
    //   }
    //   else if(curr)
    //   return solve(s,p,i+1,j+1);
    //   else
    //   return false;
    // }
    // bool isMatch(string s, string p) {
    //     return solve(s,p,0,0);
    // }


     bool solve(string &s,string &p,int i,int j,vector<vector<int>>&dp){
      if(i==s.length()&&j==p.length()) return 1;
      if(j==p.length()) return 0;
      if(dp[i][j]!=-1)
      return dp[i][j];
      bool curr=i<s.length()&&(p[j]=='.'||s[i]==p[j]);
      if(j+1<p.length()&&p[j+1]=='*'){
        int emptycase=solve(s,p,i,j+2,dp);
        int precase=curr&&solve(s,p,i+1,j,dp);
        return dp[i][j]=emptycase||precase;
      }
      else if(curr)
      return dp[i][j]=solve(s,p,i+1,j+1,dp);
      else
      return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(s,p,0,0,dp);
    }
};