class Solution {
public:
    // const int mod=1e9+7;
    // int numOfWays(int n) {
        
    //     long long int s=6;
    //     long long int d=6;
    //     for(int i=2;i<=n;i++){
    //        long long int d1=((s+d)%mod*2)%mod;
    //        long long int s1=((d%mod*2)%mod+(s%mod*3)%mod)%mod;
    //        s=s1%mod;
    //        d=d1%mod;
    //     }
    //     return (s+d)%mod;
    // }




    const int mod=1e9+7;
    vector<string>str={ "RBG","RGB","RBR","RGR",
                        "GRB","GBR","GBG","GRG",
                        "BRG","BGR","BGB","BRB" };
    vector<vector<int>>dp;
    int solve(int n,int prev){
        if(n==0) return 1;
        if(dp[n][prev]!=-1) return dp[n][prev];
        string last=str[prev];
        int ans=0;
        for(int i=0;i<12;i++){
          if(i==prev) continue;
          string curr=str[i];
          bool flag=true;
          for(int j=0;j<3;j++){
            if(curr[j]==last[j]){
                flag=false;
                break;
            }
          }
          if(flag){
            ans=(ans%mod+solve(n-1,i)%mod)%mod;
          }
        }
        return dp[n][prev]=ans%mod;
    }
    int numOfWays(int n) {
        dp.resize(n+1,vector<int>(12,-1));
        int ans=0;
        for(int i=0;i<12;i++){
            ans=(ans+solve(n-1,i))%mod;
        }
        return ans%mod;
    }
};