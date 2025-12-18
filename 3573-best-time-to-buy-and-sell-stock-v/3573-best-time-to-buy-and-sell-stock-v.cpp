class Solution {
public:
    // long long solve(vector<int>&prices,int k,int i,int prev,vector<vector<vector<long long>>>&dp){    
    //     if(k<0) return -1e12;
    //     if(i>=prices.size()){
    //        if(prev!=0){
    //           return -1e12;
    //        }
    //        return 0;
    //     }
    //     if(dp[i][prev][k]!=-1) return dp[i][prev][k];

    //     long long buy=-1e12;
    //     if(prev==0)
    //     buy=-prices[i]+solve(prices,k,i+1,1,dp);
    //     if(prev==2)
    //     buy=-prices[i]+solve(prices,k-1,i+1,0,dp);
    //     long long sell=-1e12;
    //     if(prev==0)
    //     sell=prices[i]+solve(prices,k,i+1,2,dp);
    //     if(prev==1)
    //     sell=prices[i]+solve(prices,k-1,i+1,0,dp);
    //     long long skip=solve(prices,k,i+1,prev,dp);
    //     return dp[i][prev][k]=max({buy,sell,skip});
    // }
    // long long maximumProfit(vector<int>& prices, int k) {
    //     vector<vector<vector<long long >>>dp(prices.size()+1,vector<vector<long long>>(3,vector<long long>(k+1,-1)));
    //     return solve(prices,k,0,0,dp);
    // }





    // long long solve(vector<int>&prices,int k,int i,int prev,vector<vector<vector<long long>>>&dp){    
    //     if(k<0) return -1e12;
    //     if(i>=prices.size()){
    //        if(prev!=0){
    //           return -1e12;
    //        }
    //        return 0;
    //     }
    //     if(dp[i][k][prev]!=-1) return dp[i][k][prev];
        
    //     if(prev==0){
    //        long long buy=-prices[i]+solve(prices,k,i+1,1,dp);
    //        long long sell=prices[i]+solve(prices,k,i+1,2,dp);
    //        long long skip=solve(prices,k,i+1,prev,dp);
    //        return dp[i][k][prev]=max(buy,max(sell,skip));
    //     }
        
    //     else if(prev==1){
    //        long long sell=prices[i]+solve(prices,k-1,i+1,0,dp);
    //        long long skip=solve(prices,k,i+1,prev,dp);
    //        return dp[i][k][prev]=max(sell,skip);
    //     }

    //     else { // else if(prev==2)
    //        long long buy=-prices[i]+solve(prices,k-1,i+1,0,dp);
    //        long long skip=solve(prices,k,i+1,prev,dp);
    //        return dp[i][k][prev]=max(buy,skip);
    //     }
    // }
    // long long maximumProfit(vector<int>& prices, int k) {
    //     vector<vector<vector<long long >>>dp(prices.size()+1,vector<vector<long long>>(k+1,vector<long long>(3,-1)));
    //     return solve(prices,k,0,0,dp);
    // }



    long long solve(vector<int>&prices,int k,int i,int prev,vector<vector<vector<long long>>>&dp){    
        if(k==0) return 0;
        if(i==prices.size()-1){
            return (prev==0?0:(prev==1?prices[i]:-prices[i]));
        }
        if(dp[i][k][prev]!=-1) return dp[i][k][prev];
        
        if(prev==0){
           long long buy=-prices[i]+solve(prices,k,i+1,1,dp);
           long long sell=prices[i]+solve(prices,k,i+1,2,dp);
           long long skip=solve(prices,k,i+1,prev,dp);
           return dp[i][k][prev]=max(buy,max(sell,skip));
        }
        
        else if(prev==1){
           long long sell=prices[i]+solve(prices,k-1,i+1,0,dp);
           long long skip=solve(prices,k,i+1,prev,dp);
           return dp[i][k][prev]=max(sell,skip);
        }

        else { // else if(prev==2)
           long long buy=-prices[i]+solve(prices,k-1,i+1,0,dp);
           long long skip=solve(prices,k,i+1,prev,dp);
           return dp[i][k][prev]=max(buy,skip);
        }
    }
    long long maximumProfit(vector<int>& prices, int k) {
        vector<vector<vector<long long >>>dp(prices.size()+1,vector<vector<long long>>(k+1,vector<long long>(3,-1)));
        return solve(prices,k,0,0,dp);
    }
};