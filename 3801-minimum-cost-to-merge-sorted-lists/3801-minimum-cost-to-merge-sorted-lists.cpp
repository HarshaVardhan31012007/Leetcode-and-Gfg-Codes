class Solution {
public:
    long long minMergeCost(vector<vector<int>>& lists) {
        int n=lists.size();
        long long N=1LL<<n;
        vector<long long>dp(N,LLONG_MAX);
        vector<vector<int>>mergeList(N);
        for(int i=0;i<n;i++){
            dp[1<<i]=0;
            mergeList[1<<i]=lists[i];
        }
        for(long long mask=3;mask<N;mask++){
            if((mask&(mask-1))==0) continue;
            for(long long sub=mask;sub>0;sub=(sub-1)&mask){
                long long diff=mask-sub;
                if(diff==0||sub==mask) continue;
                auto &v1=mergeList[sub];
                auto &v2=mergeList[diff];
                long long median1=v1[(v1.size()-1)/2];
                long long median2=v2[(v2.size()-1)/2];
                long long cost=dp[sub]+dp[diff]+v1.size()+v2.size()+llabs(median1-median2);
                if(cost<dp[mask]){
                    dp[mask]=cost;
                    if(mergeList[mask].empty()){
                        mergeList[mask].resize(v1.size()+v2.size());
                        merge(v1.begin(),v1.end(),v2.begin(),v2.end(),mergeList[mask].begin());
                    }
                }
            }
        }
        return dp[N-1];
    }
};