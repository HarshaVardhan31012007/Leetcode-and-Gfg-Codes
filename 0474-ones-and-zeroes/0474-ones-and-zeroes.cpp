class Solution {
public:
    // int solve(vector<pair<int,int>>&arr,int m,int n,int i,vector<vector<vector<int>>>&dp){
    //     if(i==arr.size()) return 0;
    //     if(dp[i][m][n]!=-1) return dp[i][m][n];
    //     int l=0;
    //     if(m-arr[i].first>=0&&n-arr[i].second>=0)
    //     l=1+solve(arr,m-arr[i].first,n-arr[i].second,i+1,dp);
    //     int r=solve(arr,m,n,i+1,dp);
    //     return dp[i][m][n]=max(l,r);
    // }
    // int findMaxForm(vector<string>& strs, int m, int n) {
    //     vector<pair<int,int>>arr;// 1st-no.of zeros and 2nd-no.of ones
    //     for(auto &str:strs){
    //         int one=0;
    //         int zero=0;
    //         for(auto &each:str){
    //             if(each=='0')
    //             zero++;
    //             if(each=='1')
    //             one++;
    //         }
    //         arr.push_back({zero,one});
    //     }
    //     vector<vector<vector<int>>>dp(strs.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
    //      return solve(arr,m,n,0,dp);
    // }


    // int solve(vector<pair<int,int>>&arr,int m,int n){
    //      vector<vector<vector<int>>>dp(arr.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,0)));
    //      for(int i=arr.size()-1;i>=0;i--){
    //         for(int j=0;j<=m;j++){
    //             for(int k=0;k<=n;k++){
    //             int l=0;
    //             if(j-arr[i].first>=0&&k-arr[i].second>=0)
    //             l=1+dp[i+1][j-arr[i].first][k-arr[i].second];
    //             int r=dp[i+1][j][k];
    //             dp[i][j][k]=max(l,r);
    //             }
    //         }
    //      }
    //      return dp[0][m][n];
    // }
    // int findMaxForm(vector<string>& strs, int m, int n) {
    //     vector<pair<int,int>>arr;// 1st-no.of zeros and 2nd-no.of ones
    //     for(auto &str:strs){
    //         int one=0;
    //         int zero=0;
    //         for(auto &each:str){
    //             if(each=='0')
    //             zero++;
    //             if(each=='1')
    //             one++;
    //         }
    //         arr.push_back({zero,one});
    //     }
    //      return solve(arr,m,n);
    // }


     int solve(vector<pair<int,int>>&arr,int m,int n){
         vector<vector<int>>curr(m+1,vector<int>(n+1,0));
         vector<vector<int>>next(m+1,vector<int>(n+1,0));
         for(int i=arr.size()-1;i>=0;i--){
            for(int j=0;j<=m;j++){
                for(int k=0;k<=n;k++){
                int l=0;
                if(j-arr[i].first>=0&&k-arr[i].second>=0)
                l=1+next[j-arr[i].first][k-arr[i].second];
                int r=next[j][k];
                curr[j][k]=max(l,r);
                }
            }
             next=curr;
         }
         return curr[m][n];
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>>arr;// 1st-no.of zeros and 2nd-no.of ones
        for(auto &str:strs){
            int one=0;
            int zero=0;
            for(auto &each:str){
                if(each=='0')
                zero++;
                if(each=='1')
                one++;
            }
            arr.push_back({zero,one});
        }
         return solve(arr,m,n);
    }
};