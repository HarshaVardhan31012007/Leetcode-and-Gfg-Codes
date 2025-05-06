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


    //  bool solve(string &s,string &p,int i,int j,vector<vector<int>>&dp){
    //   if(i==s.length()&&j==p.length()) return 1;
    //   if(j==p.length()) return 0;
    //   if(dp[i][j]!=-1)
    //   return dp[i][j];
    //   bool curr=i<s.length()&&(p[j]=='.'||s[i]==p[j]);
    //   if(j+1<p.length()&&p[j+1]=='*'){
    //     int emptycase=solve(s,p,i,j+2,dp);
    //     int precase=curr&&solve(s,p,i+1,j,dp);
    //     return dp[i][j]=emptycase||precase;
    //   }
    //   else if(curr)
    //   return dp[i][j]=solve(s,p,i+1,j+1,dp);
    //   else
    //   return dp[i][j]=false;
    // }
    // bool isMatch(string s, string p) {
    //     int m=s.size();
    //     int n=p.size();
    //     vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
    //     return solve(s,p,0,0,dp);
    // }


    // bool solve(string &s,string &p,int m,int n){
    // vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    // dp[m][n]=1;
    // for(int i=m;i>=0;i--){
    //     for(int j=n-1;j>=0;j--){
    //   bool curr=i<s.length()&&(p[j]=='.'||s[i]==p[j]);
    //   if(j+1<p.length()&&p[j+1]=='*'){
    //     int emptycase=dp[i][j+2];
    //     int precase=curr&&dp[i+1][j];
    //     dp[i][j]=emptycase||precase;
    //   }
    //   else if(curr)
    //   dp[i][j]=dp[i+1][j+1];
    //   else
    //   dp[i][j]=false;
    //     }
    // }
    // return dp[0][0];
    // }
    // bool isMatch(string s, string p) {
    //     int m=s.size();
    //     int n=p.size();
    //     return solve(s,p,m,n);
    // }



      bool solve(string &s,string &p,int m,int n){
    vector<int>curr(n+1,0);
    vector<int>next(n+1,0);
    curr[n]=1;
    for(int i=m;i>=0;i--){
        for(int j=n-1;j>=0;j--){
      bool cur=i<s.length()&&(p[j]=='.'||s[i]==p[j]);
      if(j+1<p.length()&&p[j+1]=='*'){
        int emptycase=curr[j+2];
        int precase=cur&&next[j];
        curr[j]=emptycase||precase;
      }
      else if(cur)
      curr[j]=next[j+1];
      else
      curr[j]=false;
        }
        next=curr;
        //for rem i<m and j==n
        curr[n]=0;
    }
    return curr[0];
    }
    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        return solve(s,p,m,n);
    }
};