class Solution {
public:
    int solve(string &s,int i,int n,vector<int>&dp){
        if(i>=n) return 1;
        if(dp[i]!=-1) return dp[i];
        int num1=stoi(s.substr(i,1));
        int num2=stoi(s.substr(i,2));
        int ans=0;
        if(num1>=1&&num1<=9){
            ans+=solve(s,i+1,n,dp);
        }
        if(num2<=26&&num2>=10){
            ans+=solve(s,i+2,n,dp);
        }
        return dp[i]=ans;
    }
    int numDecodings(string s) {
        int n=s.length();
        vector<int>dp(n,-1);
        return solve(s,0,n,dp);
    }
};