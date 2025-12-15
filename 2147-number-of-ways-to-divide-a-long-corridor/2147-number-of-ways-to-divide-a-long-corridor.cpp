class Solution {
public:
    const int mod=1e9+7;
    int solve(string &corridor,int i,vector<int>&dp,vector<int>&prefix){
        if(i>=corridor.length()) return 1;
        if(dp[i]!=-1) return dp[i];
        int idx=lower_bound(prefix.begin(),prefix.end(),(i==0?0:prefix[i-1])+2)-prefix.begin();
        if(idx==corridor.length()) return 0;
        if(idx==corridor.length()-1) return 1;
        int ans=0;
        for(int k=idx+1;k<=corridor.length();k++){
            //   if(corridor[k]=='S'){
            //      ans=(ans+solve(corridor,k,dp,prefix))%mod;
            //      break;
            //   }
            //   ans=(ans+solve(corridor,k,dp,prefix))%mod;
            
              ans=(ans+solve(corridor,k,dp,prefix))%mod;
              if(corridor[k]=='S'){
                 break;
              }
        }
        return dp[i]=ans;
    }
    int numberOfWays(string corridor) {
        vector<int>prefix(corridor.length(),0);
        prefix[0]=(corridor[0]=='S'?1:0);
        for(int i=1;i<corridor.length();i++){
            prefix[i]=prefix[i-1]+(corridor[i]=='S'?1:0);
        }
        vector<int>dp(corridor.length()+1,-1);
        return solve(corridor,0,dp,prefix);
    }



    // const int mod=1e9+7;
    // int solve(string &corridor,int i,int c,vector<vector<int>>&dp){
    //     if(i>=corridor.length()){
    //         if(c==2) return 1;
    //         return 0;
    //     }
    //     if(c>2) return 0;
    //     if(dp[i][c]!=-1) return dp[i][c];
    //     int ans=0;
    //     if(corridor[i]=='S'){
    //         if(c+1==2){
    //             ans=(ans+solve(corridor,i+1,0,dp))%mod;//partition
    //         }
    //         ans=(ans+solve(corridor,i+1,c+1,dp))%mod;//skip
    //     }
    //     else{
    //        if(c==2){
    //           ans=(ans+solve(corridor,i+1,0,dp))%mod;//partiton
    //        }
    //        ans=(ans+solve(corridor,i+1,c,dp))%mod;//skip
    //     }
    //     return dp[i][c]=ans%mod;
    // }
    // int numberOfWays(string corridor) {
    //     vector<vector<int>>dp(corridor.length()+1,vector<int>(3,-1));
    //     return solve(corridor,0,0,dp);
    // }




    // const int mod=1e9+7;
    // int numberOfWays(string corridor) {
    //    long long count=0;
    //    long long ans=1;
    //    long long prefix=0;
    //    for(auto &each:corridor){
    //         if(each=='S'){
    //             prefix++;
    //         }
    //         if(prefix==2){
    //             count++;
    //         }
    //         if(prefix==3){
    //             ans=(1LL*ans*count)%mod;
    //             prefix=1;
    //             count=0;
    //         }
    //    }
    //    if(prefix!=2)
    //    return 0;
    //    return ans;
    // }
};