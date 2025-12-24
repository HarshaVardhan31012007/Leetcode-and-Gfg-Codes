class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        priority_queue<pair<int,int>>pq;
        int i=0;
        long long ans=0;
        for(int j=0;j<nums.size();j++){
            pq.push({nums[j],j});
            if(s[j]=='1'){
                ans+=pq.top().first;
                i=pq.top().second+1;
                pq.pop();
            }
        }
        return ans;
    }
};