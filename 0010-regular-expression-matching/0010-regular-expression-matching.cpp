class Solution {
public:
    //  bool solve(string &a,string &b,int i,int j,vector<vector<int>>&dp){
    //     if(i>=a.length()&&j>=b.length()) return true;
    //     if(i>=a.length()){
    //         for(int k=j;k<b.length();k++){
    //             if(b[k+1]!='*')
    //             return false;
    //             else
    //             k++;
    //         }
    //         return true;
    //     }
    //     if(j>=b.length()) return false;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     bool ans=false;
    //     if(j+1<b.length()&&b[j+1]=='*'){
    //         if(b[j]=='.'||a[i]==b[j])
    //         ans=solve(a,b,i+1,j,dp);
    //         ans=ans||solve(a,b,i,j+2,dp);
    //     }
    //     else if(b[j]=='.'||a[i]==b[j]){
    //         ans=solve(a,b,i+1,j+1,dp);
    //     }
    //     return dp[i][j]=ans;
    // }
    // bool isMatch(string s, string p) {
    //     vector<vector<int>>dp(s.length()+1,vector<int>(p.length()+1,-1));
    //     return solve(s,p,0,0,dp);
    // }



    // bool solve(string &a,string &b,int i,int j,vector<vector<int>>&dp){
    //     if(i>=a.length()&&j>=b.length()) return true;
    //     if(j==b.length()) return false;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     bool ans=false;
    //     bool curr=i<a.length()&&(b[j]=='.'||a[i]==b[j]);
    //     if(j+1<b.length()&&b[j+1]=='*'){
    //        if(curr)
    //        ans=solve(a,b,i+1,j,dp);
    //        ans=ans||solve(a,b,i,j+2,dp);
    //     }
    //     else if(curr){
    //         ans=solve(a,b,i+1,j+1,dp);
    //     }
    //     return dp[i][j]=ans;
    // }
    // bool isMatch(string s, string p) {
    //     vector<vector<int>>dp(s.length()+1,vector<int>(p.length()+1,-1));
    //     return solve(s,p,0,0,dp);
    // }




    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.length()+1,vector<int>(p.length()+1,0));
        dp[s.length()][p.length()]=1;
        for(int i=s.length();i>=0;i--){
            for(int j=p.length()-1;j>=0;j--){
                    bool ans=false;
                    bool curr=i<s.length()&&(p[j]=='.'||s[i]==p[j]);
                    if(j+1<p.length()&&p[j+1]=='*'){
                    if(curr)
                    ans=dp[i+1][j];
                    ans=ans||dp[i][j+2];
                    }
                    else if(curr){
                        ans=dp[i+1][j+1];
                    }
                    dp[i][j]=ans;
            }
        }
        return dp[0][0];
    }
};