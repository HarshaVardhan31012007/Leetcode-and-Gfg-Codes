class Solution {
public:
    const int mod=1e9+7;
    int solve(string &corridor,int i,vector<int>&dp,vector<int>&prefix){
        if(i>=corridor.length()) return 1;
        if(dp[i]!=-1) return dp[i];
        int idx=lower_bound(prefix.begin()+i,prefix.end(),(i==0?0:prefix[i-1])+2)-prefix.begin();
        if(idx==corridor.length()) return 0;
        if(idx==corridor.length()-1) return 1;
        int ans=0;
        for(int k=idx+1;k<corridor.length();k++){
              if(corridor[k]=='S'){
                 ans=(ans+solve(corridor,k,dp,prefix))%mod;
                 break;
              }
              ans=(ans+solve(corridor,k+1,dp,prefix))%mod;
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
};