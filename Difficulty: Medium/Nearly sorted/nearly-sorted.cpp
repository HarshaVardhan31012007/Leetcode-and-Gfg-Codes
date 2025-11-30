class Solution {
  public:
    void nearlySorted(vector<int>& nums, int k) {
        if(k==0) return;
        priority_queue<int,vector<int>,greater<>>pq;
        int i=0;
        int j=0;
        while(j<nums.size()&&j<=i+k){
            pq.push(nums[j]);
            j++;
        }
        for(int i=0;i<nums.size();i++){
            nums[i]=pq.top();
            pq.pop();
            if(j<nums.size()){
                pq.push(nums[j]);
                j++;
            }
        }
    }
};