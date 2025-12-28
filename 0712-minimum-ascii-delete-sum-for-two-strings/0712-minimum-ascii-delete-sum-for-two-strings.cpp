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



    // int minimumDeleteSum(string s1, string s2) {
    //     vector<vector<int>>dp(s1.length()+1,vector<int>(s2.length()+1,INT_MAX));
    //     dp[s1.length()][s2.length()]=0;
    //     for(int i=s1.length();i>=0;i--){
    //         for(int j=s2.length();j>=0;j--){
    //             if(i==s1.length()&&j==s2.length()) continue;
    //             if(i<s1.length()&&j<s2.length()&&s1[i]==s2[j]){
    //                dp[i][j]=dp[i+1][j+1];
    //                continue;
    //             }
    //             int l=INT_MAX;
    //             if(i<s1.length())
    //                 l=s1[i]+dp[i+1][j];
    //             int r=INT_MAX;
    //             if(j<s2.length())
    //             r=s2[j]+dp[i][j+1];
    //             dp[i][j]=min(l,r);
    //         }
    //     }
    //     return dp[0][0];
    // }



    // int minimumDeleteSum(string s1, string s2) {
    //     vector<vector<int>>dp(s1.length()+1,vector<int>(s2.length()+1,INT_MAX));
    //     dp[s1.length()][s2.length()]=0;
    //     for(int i=s1.length()-1;i>=0;i--){
    //        dp[i][s2.length()]=dp[i+1][s2.length()]+s1[i];
    //     }
    //     for(int i=s2.length()-1;i>=0;i--){
    //        dp[s1.length()][i]=dp[s1.length()][i+1]+s2[i];
    //     }
    //     for(int i=s1.length()-1;i>=0;i--){
    //         for(int j=s2.length()-1;j>=0;j--){
    //             if(s1[i]==s2[j]){
    //                dp[i][j]=dp[i+1][j+1];
    //                continue;
    //             }
    //             dp[i][j]=min(s1[i]+dp[i+1][j],s2[j]+dp[i][j+1]);
    //         }
    //     }
    //     return dp[0][0];
    // }


    
    // int minimumDeleteSum(string s1, string s2) {
    //     vector<int>next(s2.length()+1,INT_MAX);
    //     vector<int>curr(s2.length()+1,INT_MAX);
    //     next[s2.length()]=0;
    //     for(int i=s2.length()-1;i>=0;i--){
    //        next[i]=next[i+1]+s2[i];
    //     }
    //     for(int i=s1.length()-1;i>=0;i--){
    //         for(int j=s2.length();j>=0;j--){
    //             if(j==s2.length()){
    //                 curr[j]=next[j]+s1[i];
    //                 continue;
    //             }
    //             if(s1[i]==s2[j]){
    //                curr[j]=next[j+1];
    //                continue;
    //             }
    //             curr[j]=min(s1[i]+next[j],s2[j]+curr[j+1]);
    //         }
    //         next=curr;
    //     }
    //     return next[0];
    // }





    int longestCommonSubsequence(string a, string b) {
        vector<vector<int>>dp(a.size()+1,vector<int>(b.size()+1,0));
        for(int i=a.size()-1;i>=0;i--){
            for(int j=b.size()-1;j>=0;j--){
                    if(a[i]==b[j]){
                        dp[i][j]=a[i]+dp[i+1][j+1];
                    }
                    else{
                        dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                    }
            }
        }
        return dp[0][0];
    }
    int minimumDeleteSum(string s1, string s2) {
        int t=accumulate(s1.begin(),s1.end(),0);
        t+=accumulate(s2.begin(),s2.end(),0);
        return t-2*(longestCommonSubsequence(s1,s2));
    }
};