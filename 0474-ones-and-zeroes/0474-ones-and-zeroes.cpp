class Solution {
public:
    int calculate(string &str){
        int count=0;
        for(auto &ch:str){
            if(ch=='0')
            count++;
        }
        return count;
    }
    int solve(vector<pair<int,int>>&v,int i,int m,int n,vector<vector<vector<int>>>&dp){
        if(i>=v.size()) return 0;
        if(dp[i][m][n]!=-1) return dp[i][m][n];
        int inc=0;
        if(v[i].first<=m&&v[i].second<=n)
        inc=1+solve(v,i+1,m-v[i].first,n-v[i].second,dp);
        int exc=solve(v,i+1,m,n,dp);
        return dp[i][m][n]=max(inc,exc);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>>v;
        for(auto &str:strs){
            int zeroc=calculate(str);
            int onec=str.length()-zeroc;
            v.push_back({zeroc,onec});
        }
        vector<vector<vector<int>>>dp(strs.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return solve(v,0,m,n,dp);
    }
};