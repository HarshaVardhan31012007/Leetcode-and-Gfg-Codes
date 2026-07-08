class Solution {
public:
    // int solve(string &s,int i,int n,vector<int>&dp){
    //     if(i>=n) return 1;
    //     if(dp[i]!=-1) return dp[i];
    //     int num1=stoi(s.substr(i,1));
    //     int num2=stoi(s.substr(i,2));
    //     int ans=0;
    //     if(num1>=1&&num1<=9){
    //         ans+=solve(s,i+1,n,dp);
    //     }
    //     if(num2<=26&&num2>=10){
    //         ans+=solve(s,i+2,n,dp);
    //     }
    //     return dp[i]=ans;
    // }
    // int numDecodings(string s) {
    //     int n=s.length();
    //     vector<int>dp(n,-1);
    //     return solve(s,0,n,dp);
    // }


    // int solve(string &s,int i,int n,vector<int>&dp){
    //     if(i>=n) return 1;
    //     if(dp[i]!=-1) return dp[i];
    //     int ans=0;
    //     int num1=(s[i]-'0');
    //     if(num1>=1&&num1<=9){
    //         ans+=solve(s,i+1,n,dp);
    //     }

    //     if(i+1<n){
    //         int num2=10*(s[i]-'0')+(s[i+1]-'0');
    //         if(num2>=10&&num2<=26)
    //         ans+=solve(s,i+2,n,dp);
    //     }
    //     return dp[i]=ans;
    // }
    // int numDecodings(string s) {
    //     int n=s.length();
    //     vector<int>dp(n,-1);
    //     return solve(s,0,n,dp);
    // }


    
    // int numDecodings(string s) {
    //     int n=s.length();
    //     vector<int>dp(n+1,0);
    //     dp[n]=1;
    //     for(int i=n-1;i>=0;i--){
    //         int ans=0;
    //         int num1=(s[i]-'0');
    //         if(num1>=1&&num1<=9){
    //             ans+=dp[i+1];
    //         }

    //         if(i+1<n){
    //             int num2=10*(s[i]-'0')+(s[i+1]-'0');
    //             if(num2>=10&&num2<=26)
    //             ans+=dp[i+2];
    //         }
    //         dp[i]=ans;
    //     }
    //     return dp[0];
    // }


    int numDecodings(string s) {
        int n=s.length();
        int next1=1;int next2=0;
        for(int i=n-1;i>=0;i--){
            int ans=0;
            int num1=(s[i]-'0');
            if(num1>=1&&num1<=9){
                ans+=next1;
            }

            if(i+1<n){
                int num2=10*(s[i]-'0')+(s[i+1]-'0');
                if(num2>=10&&num2<=26)
                ans+=next2;
            }
            next2=next1;
            next1=ans;
        }
        return next1;
    }
};