class Solution {
public:
    // int solve(vector<int>&power,int i,int prev,vector<vector<int>>&dp){
    //     if(i>=power.size()) return 0;
    //     if(dp[i][prev+1]!=-1) return dp[i][prev+1];
    //     int d=-1;
    //     if(prev!=-1)
    //     d=power[i]-power[prev];
    //     int l=0;int r=0;
    //     if(prev==-1||d==0||d>2)
    //     l=power[i]+solve(power,i+1,i,dp);
    //     if(d!=0)
    //     r=solve(power,i+1,prev,dp);
    //     return dp[i][prev+1]=max(l,r);
    // }
    // long long maximumTotalDamage(vector<int>& power) {
    //     sort(power.begin(),power.end());
    //     vector<vector<int>>dp(power.size()+1,vector<int>(power.size()+1,-1));
    //     return solve(power,0,-1,dp);
    // }



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




     // long long int solve(vector<int>&power,int i,vector<long long int>&dp,unordered_map<int,int>&freq){
    //     if(i>=power.size()) return 0;
    //     if(dp[i]!=-1) return dp[i];
    //     int idx=lower_bound(power.begin()+i+1,power.end(),power[i]+3)-power.begin();
    //     long long int l=1LL*freq[power[i]]*power[i]+solve(power,idx,dp,freq);
    //     long long int r=solve(power,i+freq[power[i]],dp,freq);
    //     return dp[i]=max(l,r);
    // }
    // long long maximumTotalDamage(vector<int>& power) {
    //     unordered_map<int,int>freq;
    //     for(auto &num:power){
    //         freq[num]++;
    //     }
    //     sort(power.begin(),power.end());
    //     vector<long long int>dp(power.size()+1,-1);
    //     return solve(power,0,dp,freq);
    // }



    
      
       
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int,int>freq;
        for(auto &num:power){
            freq[num]++;
        }
        vector<int>nums;
        for(auto &i:freq){
            nums.push_back(i.first);
        }
        sort(nums.begin(),nums.end());
        vector<long long int>dp(nums.size()+1,0);
        for(int i=nums.size()-1;i>=0;i--){
             int idx=lower_bound(nums.begin()+i+1,nums.end(),nums[i]+3)-nums.begin();
            long long int l=1LL*freq[nums[i]]*nums[i]+dp[idx];
            long long int r=dp[i+1];
            dp[i]=max(l,r);
        }
        return dp[0];
    }
};