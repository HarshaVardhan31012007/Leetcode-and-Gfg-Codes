class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        // int n=s1.size();
        // int m=s2.size();
        // int ans=0;
        // for(int diff=-(n-1);diff<m;diff++){
        //     int i,j;
        //     if(diff>=0){
        //         i=0;j=i+diff;
        //     }
        //     else{
        //         j=0;i=j+abs(diff);
        //     }
        //     int curr=0;
        //     for(;i<n&&j<m;i++,j++){
        //         if(s1[i]==s2[j]){
        //             curr++;
        //         }
        //         else{
        //             ans=max(ans,curr);
        //         }
        //     }
        //     ans=max(ans,curr);
        // }
        // return ans;
        
        
        int m=s1.size();
        int n=s2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(s1[i]==s2[j]){
                    dp[i][j]=1+(i>0&&j>0?dp[i-1][j-1]:0);
                }
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};