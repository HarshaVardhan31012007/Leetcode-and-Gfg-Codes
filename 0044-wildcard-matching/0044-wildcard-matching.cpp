class Solution {
public:
    // bool solve(string &p,string &q,int i,int j,vector<vector<int>>&dp){
    //     if(i>=p.length()&&j>=q.length()) return 1;
    //     if(i>=p.length()) return 0;
    //     if(j>=q.length()){
    //         bool flag=1;
    //         for(int k=i;k<p.length();k++){
    //             if(p[k]!='*')
    //             flag=0;
    //         }
    //         if(flag) return 1;
    //         else return 0;
    //     }
    //     if(dp[i][j]!=-1)
    //     return dp[i][j];
    //     int ans=0;
    //     if(p[i]=='?'||p[i]==q[j])
    //     ans=ans||solve(p,q,i+1,j+1,dp);
    //     else if(p[i]=='*')
    //     ans=ans||solve(p,q,i,j+1,dp)||solve(p,q,i+1,j,dp);
    //     return dp[i][j]=ans;
    // }
    //  bool isMatch(string s, string p) {
    //     int m=p.size();
    //     int n=s.size();
    //     vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
    //     return solve(p,s,0,0,dp);
    // }

    bool solve(string &p,string &q,int i,int j,vector<vector<int>>&dp,vector<int>&star){
        if(i>=p.length()&&j>=q.length()) return 1;
        if(i>=p.length()) return 0;
        if(j>=q.length()){
           int len=p.length()-i;
           return len==star[i];
        }
        if(dp[i][j]!=-1)
        return dp[i][j];
        int ans=0;
        if(p[i]=='?'||p[i]==q[j])
        ans=ans||solve(p,q,i+1,j+1,dp,star);
        else if(p[i]=='*')
        ans=ans||solve(p,q,i,j+1,dp,star)||solve(p,q,i+1,j,dp,star);
        return dp[i][j]=ans;
    }
     bool isMatch(string s, string p) {
        int m=p.size();
        int n=s.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        vector<int>star(m+1,0);
        star[m]=0;
        for(int i=m-1;i>=0;i--){
            if(p[i]=='*')
            star[i]=1+star[i+1];
            else
            star[i]=star[i+1];
        }
        return solve(p,s,0,0,dp,star);
    }


    // bool solve(string &p,string &q,int i,int j){
    //   vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    //   dp[m][n]=1;
    //   for(int i=0;i<=m;j++){
        
    //   }
    // }
    // bool isMatch(string s, string p) {
    //     int m=p.size();
    //     int n=s.size();
    //     return solve(p,s,m,n);
    // }
};