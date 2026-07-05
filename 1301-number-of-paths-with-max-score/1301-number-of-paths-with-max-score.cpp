class Solution {
public:
    vector<int>temp={-1,-1};
    const int mod=1e9+7;
    vector<int>solve(vector<string>&board,int m,int n,int i,int j,vector<vector<vector<int>>>&dp){
        if(i<0||j<0||i>=m||j>=n||board[i][j]=='X') return {INT_MIN,0};
        if(dp[i][j]!=temp) return dp[i][j];
        if(board[i][j]=='S'){
            return {0,1};
        }
        auto right=solve(board,m,n,i,j+1,dp);
        auto down=solve(board,m,n,i+1,j,dp);
        auto diag=solve(board,m,n,i+1,j+1,dp);
        int curr=(board[i][j]=='E' ?0:board[i][j]-'0');
        int maxi=max({right[0],down[0],diag[0]});
        int count=0;
        if(maxi==right[0]) count=(count+right[1])%mod;
        if(maxi==down[0]) count=(count+down[1])%mod;
        if(maxi==diag[0]) count=(count+diag[1])%mod;
        if(maxi==INT_MIN){
            return dp[i][j]={INT_MIN,0};
        }
        return dp[i][j]={(curr+maxi)%mod,count};
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,{-1,-1}));
        auto ans=solve(board,m,n,0,0,dp);
        if(ans[0]==INT_MIN) return {0,0};
        return ans;
    }
};