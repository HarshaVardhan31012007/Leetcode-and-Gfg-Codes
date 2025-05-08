class Solution {
public:
    // int solve(vector<int>&cuts,int s,int e,vector<vector<int>>&dp){
    //     if(dp[s][e]!=-1)
    //     return dp[s][e];
    //     int ans=INT_MAX;
    //     for(auto &cut:cuts){
    //       if(cut>s&&cut<e)
    //       ans=min(ans,e-s+solve(cuts,s,cut,dp)+solve(cuts,cut,e,dp));
    //     }
    //     return dp[s][e]=(ans==INT_MAX)?0:ans;
    // }
    // int minCost(int n, vector<int>& cuts) {
    //     vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    //     return solve(cuts,0,n,dp);
    // }


    // int solve(vector<int>&cuts,int n){
    //   vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    //   for(int i=n-1;i>=0;i--){
    //     for(int j=i;j<=n-1;j++){
    //     int ans=INT_MAX;
    //     for(auto &cut:cuts){
    //       if(cut>i&&cut<j)
    //       ans=min(ans,j-i+dp[i][cut]+dp[cut][j]);
    //     }
    //     dp[i][j]=(ans==INT_MAX)?0:ans;
    //     }
    //   }
    //   return dp[0][n];
    // }
    // int minCost(int n, vector<int>& cuts) {
    //     return solve(cuts,n);
    // }

    int minCost(int n, vector<int>& cuts) {
		cuts.insert(cuts.begin(),0);
		cuts.insert(cuts.end(),n);
		sort(cuts.begin(),cuts.end());
		int m=cuts.size();
		vector<vector<int>> dp(m,vector<int>(m,0));
		for(int i=m-1;i>=1;i--){
			for(int j=i;j<=m-2;j++){
				int mini=1e9;
				for(int ind=i;ind<=j;ind++){
					int cost= cuts[j+1]-cuts[i-1]+dp[i][ind-1]+dp[ind+1][j];
					mini=min(mini,cost);
				}
				dp[i][j]=mini;
			}
		}
		return dp[1][cuts.size()-2];
	}
};