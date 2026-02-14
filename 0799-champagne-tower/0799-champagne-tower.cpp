class Solution {
public:
    // double champagneTower(int poured, int query_row, int query_glass) {
    //     int row=query_row;
    //     vector<double>v(1);
    //     v[0]=poured;
    //     double ans=v[0];
    //     for(int i=1;i<=row;i++){
    //         v.push_back(0.0);
    //         for(int j=i;j>=0;j--){
    //             v[j]=(j!=0&&v[j-1]>=1?((v[j-1]-1)/2.0):0)+(j!=i&&v[j]>=1?((v[j]-1)/2.0):0);
    //             if(j==query_glass&&i==row){
    //                 ans=v[j];
    //                 break;
    //             }
    //         }
    //     }
    //     return (ans>=1)?1.0:ans;
    // }


    void solve(int i,int row,vector<double>&dp){
        if(i>=row) return;
        for(int j=i;j>=0;j--){
            dp[j]=max((dp[j]-1)/2.0,0.0);
            dp[j+1]+=dp[j];
        }
        solve(i+1,row,dp);
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double>dp(query_row+1,0);
        dp[0]=poured;
        solve(0,query_row,dp);
        return min(dp[query_glass],1.0);
    }
};