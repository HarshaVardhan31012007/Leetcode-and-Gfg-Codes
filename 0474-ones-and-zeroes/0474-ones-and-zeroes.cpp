class Solution {
public:
    int solve(vector<pair<int,int>>&arr,int m,int n,int i,vector<vector<vector<int>>>&dp){
        if(i==arr.size()) return 0;
        if(dp[i][m][n]!=-1) return dp[i][m][n];
        int l=0;
        if(m-arr[i].first>=0&&n-arr[i].second>=0)
        l=1+solve(arr,m-arr[i].first,n-arr[i].second,i+1,dp);
        int r=solve(arr,m,n,i+1,dp);
        return dp[i][m][n]=max(l,r);
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
        vector<vector<vector<int>>>dp(strs.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
         return solve(arr,m,n,0,dp);
    }
};