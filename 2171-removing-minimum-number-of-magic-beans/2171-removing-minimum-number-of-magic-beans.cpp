class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(),beans.end());
        int n=beans.size();
        vector<long long>suffix(n,0);
        long long sum=0;
        for(int i=n-1;i>=0;i--){
            suffix[i]=sum;
            sum+=beans[i];
        }
        long long prefix=0;
        long long ans=LLONG_MAX;
        for(int i=0;i<n;i++){
            long long before=prefix;
            long long after=(suffix[i]-(1LL*(n-i-1)*beans[i]));
            ans=min(ans,after+before);
            prefix+=beans[i];
        }
        return ans;
    }
};