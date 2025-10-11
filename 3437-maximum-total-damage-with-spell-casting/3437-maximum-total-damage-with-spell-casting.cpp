class Solution {
public:
    long long int solve(vector<int>&power,int i,vector<long long int>&dp,unordered_map<int,int>&freq){
        if(i>=power.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int idx=lower_bound(power.begin()+i+1,power.end(),power[i]+3)-power.begin();
        long long int l=1LL*freq[power[i]]*power[i]+solve(power,idx,dp,freq);
        long long int r=solve(power,i+freq[power[i]],dp,freq);
        return dp[i]=max(l,r);
    }
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int,int>freq;
        for(auto &num:power){
            freq[num]++;
        }
        sort(power.begin(),power.end());
        vector<long long int>dp(power.size()+1,-1);
        return solve(power,0,dp,freq);
    }



    // long long maximumTotalDamage(vector<int>& power) {
    //     sort(power.begin(),power.end());
    //     vector<int>next(power.size()+1,0);
    //         for(int prev=power.size()-2;prev>=-1;prev--){
    //             for(int i=power.size()-1;i>prev;i--){
    //                 int d=0;
    //                 if(prev!=-1)
    //                 d=power[i]-power[prev];
    //                 int l=0; int r=0;
    //                 if(prev==-1||d==0||d>2)
    //                 l=power[i]+next[i+1];
    //                 if(prev==-1||d!=0)
    //                 r=next[prev+1];
    //                 next[prev+1]=max(l,r);
    //         }
    //     }
    //     return next[0];
    // }



    // long long maximumTotalDamage(vector<int>& power) {
    //     sort(power.begin(),power.end());
    //     vector<pair<int,int>>v;
    //     for(int i=0;i<power.size();i++){
    //         if(i>0&&power[i]==power[i-1])
    //         v.back().second++;
    //         else
    //         v.push_back({power[i],1});
    //     }
    //     vector<int>next(v.size()+1,0);
    //         for(int prev=v.size()-2;prev>=-1;prev--){
    //             for(int i=v.size()-1;i>prev;i--){
    //                 int d=0;
    //                 if(prev!=-1)
    //                 d=v[i].first-v[prev].first;
    //                 int l=0;
    //                 if(prev==-1||d>2)
    //                 l=v[i].first*v[i].second+next[i+1];
    //                 int r=next[prev+1];
    //                 next[prev+1]=max(l,r);
    //         }
    //     }
    //     return next[0];
    // }
};