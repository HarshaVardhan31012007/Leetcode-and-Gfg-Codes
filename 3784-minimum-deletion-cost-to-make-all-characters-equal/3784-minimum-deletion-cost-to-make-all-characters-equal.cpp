class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        unordered_map<char,long long>freq;
        for(int i=0;i<s.length();i++)
            freq[s[i]]+=1LL*cost[i];
        long long sum=accumulate(cost.begin(),cost.end(),0LL);
        long long mini=LLONG_MAX;
        for(auto &each:freq){
             mini=min(mini,sum-each.second);
        }
        return mini;
    }
};