class Solution {
public:
    // int solve(string &s1,string &s2,int i,int j,vector<vector<int>>&dp){
    //     if(i>=s1.length()&&j>=s2.length()) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(i<s1.length()&&j<s2.length()&&s1[i]==s2[j]) 
    //     return dp[i][j]=solve(s1,s2,i+1,j+1,dp);
    //     int l=INT_MAX;
    //     if(i<s1.length())
    //         l=s1[i]+solve(s1,s2,i+1,j,dp);
    //     int r=INT_MAX;
    //     if(j<s2.length())
    //        r=s2[j]+solve(s1,s2,i,j+1,dp);
    //     return dp[i][j]=min(l,r);
    // }
    // int minimumDeleteSum(string s1, string s2) {
    //     vector<vector<int>>dp(s1.length()+1,vector<int>(s2.length()+1,-1));
    //     return solve(s1,s2,0,0,dp);
    // }



     int solve(string &s1,string &s2,int i,int j,vector<vector<int>>&dp){
        if(i>=s1.length()&&j>=s2.length()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i<s1.length()&&j<s2.length()&&s1[i]==s2[j]) 
        return dp[i][j]=solve(s1,s2,i+1,j+1,dp);
        int l=INT_MAX;
        if(i<s1.length())
            l=s1[i]+solve(s1,s2,i+1,j,dp);
        int r=INT_MAX;
        if(j<s2.length())
           r=s2[j]+solve(s1,s2,i,j+1,dp);
        return dp[i][j]=min(l,r);
    }
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>>dp(s1.length()+1,vector<int>(s2.length()+1,INT_MAX));
        dp[s1.length()][s2.length()]=0;
        for(int i=s1.length();i>=0;i--){
            for(int j=s2.length();j>=0;j--){
                if(i==s1.length()&&j==s2.length()) continue;
                if(i<s1.length()&&j<s2.length()&&s1[i]==s2[j]){
                   dp[i][j]=dp[i+1][j+1];
                   continue;
                }
                int l=INT_MAX;
                if(i<s1.length())
                    l=s1[i]+dp[i+1][j];
                int r=INT_MAX;
                if(j<s2.length())
                r=s2[j]+dp[i][j+1];
                dp[i][j]=min(l,r);
            }
        }
        return dp[0][0];
    }
};