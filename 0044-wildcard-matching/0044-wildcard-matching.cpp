class Solution {
public:
    // bool solve(string &a,string &b,int i,int j,vector<vector<int>>&dp){
    //     if(i>=a.length()&&j>=b.length()) return true;
    //     if(i>=a.length()){
    //         for(int k=j;k<b.length();k++){
    //             if(b[k]!='*')
    //             return false;
    //         }
    //         return true;
    //     }
    //     if(j>=b.length()) return false;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     bool ans=false;
    //     if(b[j]=='?'||a[i]==b[j]){
    //         ans=solve(a,b,i+1,j+1,dp);
    //     }
    //     else if(b[j]=='*'){
    //         ans=solve(a,b,i+1,j,dp)||solve(a,b,i,j+1,dp);
    //     }
    //     return dp[i][j]=ans;
    // }
    // bool isMatch(string s, string p) {
    //     vector<vector<int>>dp(s.length()+1,vector<int>(p.length()+1,-1));
    //     return solve(s,p,0,0,dp);
    // }




    
    // bool isMatch(string s, string p) {
    //     vector<vector<bool>>dp(s.length()+1,vector<bool>(p.length()+1,0));
    //     dp[s.length()][p.length()]=1;
    //     for(int j=p.length()-1;j>=0;j--){
    //         if(p[j]!='*') break;
    //         dp[s.length()][j]=1;
    //     }
    //     for(int i=s.length()-1;i>=0;i--){
    //         for(int j=p.length()-1;j>=0;j--){
    //                 bool ans=false;
    //                 if(p[j]=='?'||s[i]==p[j]){
    //                     ans=dp[i+1][j+1];
    //                 }
    //                 else if(p[j]=='*'){
    //                     ans=dp[i+1][j]||dp[i][j+1];
    //                 }
    //                 dp[i][j]=ans;
    //         }
    //     }
    //     return dp[0][0];
    // }


     bool isMatch(string s, string p) {
        vector<bool>next(p.length()+1,0);
        next[p.length()]=1;
        for(int j=p.length()-1;j>=0;j--){
            if(p[j]!='*') break;
            next[j]=1;
        }
        vector<bool>curr(p.length()+1,0);
        for(int i=s.length()-1;i>=0;i--){
            for(int j=p.length()-1;j>=0;j--){
                    bool ans=false;
                    if(p[j]=='?'||s[i]==p[j]){
                        ans=next[j+1];
                    }
                    else if(p[j]=='*'){
                        ans=next[j]||curr[j+1];
                    }
                    curr[j]=ans;
            }
            next=curr;
        }
        return next[0];
    }
};