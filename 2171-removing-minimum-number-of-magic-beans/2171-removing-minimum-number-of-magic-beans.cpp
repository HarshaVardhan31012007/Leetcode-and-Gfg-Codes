class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n=beans.size();
        sort(beans.begin(),beans.end());
        long long prefix=0;
        long long ans=LLONG_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,-1LL*(n-i)*beans[i]);
            prefix+=beans[i];
        }
        ans+=prefix;
        return ans;
    }
};