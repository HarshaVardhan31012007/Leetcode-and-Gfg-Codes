class Solution {
public:
    int solve(vector<int>&prefix,int i,int j,int k,vector<vector<int>>&dp){
        if(i>=j) return  0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=INT_MAX;
        for(int idx=i;idx<j;idx+=k-1){
           int left=solve(prefix,i,idx,k,dp);
           int right=solve(prefix,idx+1,j,k,dp);
           mini=min(mini,left+right);
        }
        if(((j-i)%(k-1))==0)
        mini+=prefix[j]-prefix[i-1];
        return dp[i][j]=mini;
    }
    int mergeStones(vector<int>& stones, int k) {
        int n=stones.size();
        if((n-1)%(k-1)) return -1;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        vector<int>prefix(n+1,0);
        prefix[0]=0;
        for(int i=1;i<=n;i++){
            prefix[i]=prefix[i-1]+stones[i-1];
        }
        return solve(prefix,1,n,k,dp);
    }
};