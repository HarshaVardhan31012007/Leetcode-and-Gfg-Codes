class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // priority_queue<int,vector<int>,greater<>>pq;
        // for(auto &num:nums){
        //     pq.push(num);
        //     if(pq.size()>k) pq.pop();
        // }
        // return pq.top();



        priority_queue<int,vector<int>,greater<>>pq;
        for(int i=0;i<nums.size();i++){
            if(i<k){
                pq.push(nums[i]);
            }
            else if(nums[i]>pq.top()){
                pq.push(nums[i]);
                pq.pop();
            }
        }
        return pq.top();
    }
};