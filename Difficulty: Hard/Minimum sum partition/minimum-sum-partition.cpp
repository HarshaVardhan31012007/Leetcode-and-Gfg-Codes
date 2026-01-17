class Solution {
  public:
    // int minDifference(vector<int>& arr) {
    //     int t=accumulate(arr.begin(),arr.end(),0);
    //     vector<vector<bool>>dp(arr.size()+1,vector<bool>(t+1,0));
    //     dp[arr.size()][0]=true;
    //     for(int i=(int)arr.size()-1;i>=0;i--){
    //         for(int j=t;j>=0;j--){
    //             bool inc=false;
    //             if(j>=arr[i])
    //             inc=dp[i+1][j-arr[i]];
    //             bool exc=dp[i+1][j];
    //             dp[i][j]=inc||exc;
    //         }
    //     }
    //     int ans=INT_MAX;
    //     for(int j=1;j<=t;j++){
    //         if(dp[0][j]){
    //             ans=min(ans,abs(j-t+j));
    //         }
    //     }
    //     return ans;
    // }
    
    
    // int minDifference(vector<int>& arr) {
    //     int t=accumulate(arr.begin(),arr.end(),0);
    //     vector<bool>curr(t+1,0);
    //     curr[0]=true;
    //     for(int i=arr.size()-1;i>=0;i--){
    //         for(int j=t;j>=0;j--){
    //             bool inc=false;
    //             if(j>=arr[i])
    //             inc=curr[j-arr[i]];
    //             bool exc=curr[j];
    //             curr[j]=inc||exc;
    //         }
    //     }
    //     int ans=INT_MAX;
    //     for(int j=1;j<=t;j++){
    //         if(curr[j]){
    //             ans=min(ans,abs(j-t+j));
    //         }
    //     }
    //     return ans;
    
    
    
    // int minDifference(vector<int>& arr) {
    //     int t=accumulate(arr.begin(),arr.end(),0);
    //     vector<bool>curr(t+1,0);
    //     curr[0]=true;
    //     int ans=INT_MAX;
    //     for(int i=arr.size()-1;i>=0;i--){
    //         for(int j=t;j>=0;j--){
    //             bool inc=false;
    //             if(j>=arr[i])
    //             inc=curr[j-arr[i]];
    //             bool exc=curr[j];
    //             curr[j]=inc||exc;
    //             if(i==0&&curr[j]&&j<=t/2)
    //             ans=min(ans,abs(j-t+j));
    //         }
    //     }
    //     return ans;
    // }
    
    
    
    int minDifference(vector<int>& arr) {
    int t = accumulate(arr.begin(), arr.end(), 0);
    bitset<200001> dp;   // size >= max total sum
    dp[0] = 1;

    for (int x : arr) {
        dp |= (dp << x);
    }

    int ans = INT_MAX;
    for (int j = 0; j <= t/2; j++) {
        if (dp[j]) {
            ans = min(ans, t - 2*j);
        }
    }
    return ans;
}

};
