class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        priority_queue<int>pq;
        long long ans=0;
        for(int j=0;j<nums.size();j++){
            pq.push(nums[j]);
            if(s[j]=='1'){
                ans+=pq.top();
                pq.pop();
            }
        }
        return ans;
    }
};