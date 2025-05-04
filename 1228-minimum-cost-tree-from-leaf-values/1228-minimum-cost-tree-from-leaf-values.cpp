class Solution {
public:
    // int solve(map<pair<int,int>,int>&maxi,int s,int e,vector<vector<int>>&dp){
    //     if(s>=e) return 0;
    //     if(dp[s][e]!=-1)
    //     return dp[s][e];
    //     int ans=INT_MAX;
    //     for(int i=s;i<e;i++){
    //        ans=min(ans,maxi[{s,i}]*maxi[{i+1,e}]+solve(maxi,s,i,dp)+solve(maxi,i+1,e,dp));
    //     }
    //     return dp[s][e]=ans;
    // }
    //  int mctFromLeafValues(vector<int>& arr) {
    //     int n=arr.size();
    //     map<pair<int,int>,int> maxi;
    //     for(int i=0;i<n;i++){
    //         for(int j=i;j<n;j++){
    //             if(i==j)
    //             maxi[{i,j}]=arr[j];
    //             else{
    //                 maxi[{i,j}]=max(maxi[{i,j-1}],arr[j]);
    //             }
    //         }
    //     }
    //     vector<vector<int>>dp(n,vector<int>(n,-1));
    //     return solve(maxi,0,n-1,dp);
    // }

    int solve(map<pair<int,int>,int>&maxi,int n){
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int s=n-1;s>=0;s--){
            for(int e=0;e<=n-1;e++){
                if(s>=e)
                continue;
                else{
         int ans=INT_MAX;
        for(int i=s;i<e;i++){
           ans=min(ans,maxi[{s,i}]*maxi[{i+1,e}]+dp[s][i]+dp[i+1][e]);
        }
        dp[s][e]=ans;
                }
            }
        }
        return dp[0][n-1];
    }
    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();
        map<pair<int,int>,int> maxi;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(i==j)
                maxi[{i,j}]=arr[j];
                else{
                    maxi[{i,j}]=max(maxi[{i,j-1}],arr[j]);
                }
            }
        }
        return solve(maxi,n);
    }
};