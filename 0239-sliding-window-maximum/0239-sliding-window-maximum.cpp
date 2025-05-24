class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //   deque<int>dq;
    //   vector<int>ans;
    //   for(int i=0;i<k;i++){
    //      while(!dq.empty()&&nums[dq.back()]<nums[i])
    //      dq.pop_back();
    //      dq.push_back(i);
    //   }  
    //    ans.push_back(nums[dq.front()]);
    //  for(int i=k;i<nums.size();i++){
    //     //addition and removal
    //     // while(!dq.empty()&&nums[dq.back()]<nums[i])
    //     // dq.pop_back();
    //     // dq.push_back(i);
    //     // while(!dq.empty()&&i-dq.front()>=k){
    //     //     dq.pop_front();
    //     // }
    //     // removal and then addition
    //     while(!dq.empty()&&i-dq.front()>=k){
    //         dq.pop_front();
    //     }
    //     while(!dq.empty()&&nums[dq.back()]<nums[i])
    //     dq.pop_back();
    //     dq.push_back(i);
    //     ans.push_back(nums[dq.front()]);
    //  }
    //  return ans;

    vector<int>ans;
    priority_queue<pair<int,int>>pq;
    for(int i=0;i<k;i++){
        pq.push({nums[i],i});
    }
    ans.push_back(pq.top().first);
    for(int i=k;i<nums.size();i++){
        while(!pq.empty()&&i-pq.top().second>=k)
        pq.pop();
        pq.push({nums[i],i});
        ans.push_back(pq.top().first);
    }
      return ans;
    }
};