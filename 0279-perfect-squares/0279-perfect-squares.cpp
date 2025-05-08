class Solution {
public:
    int solve(int n,vector<int>&num,vector<int>&dp){
        if(dp[n]!=-1)
        return dp[n];
        int ans=INT_MAX;
        for(auto &each:num){
            if(each<=n)
            ans=min(ans,1+solve(n-each,num,dp));
        }
        return dp[n]=(ans==INT_MAX)?0:ans;
    }
    int numSquares(int n) {
        double a=sqrt(n);
        if(a==(int)a) return 1;
        vector<int>num;
        for(int i=1;i<n;i++){
            if(sqrt(i)==(int)sqrt(i))
            num.push_back(i);
        }
        vector<int>dp(n+1,-1);
       return solve(n,num,dp);
    }
};