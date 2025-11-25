class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {

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
    //     // while(!dq.empty()&&i-dq.front()>=k){
    //     //     dq.pop_front();
    //     // }
    //     // while(!dq.empty()&&nums[dq.back()]<nums[i])
    //     // dq.pop_back();
    //     // dq.push_back(i);


    //     // if(!dq.empty()&&i-dq.front()>=k){
    //     //     dq.pop_front();
    //     // }
    //     // while(!dq.empty()&&nums[dq.back()]<nums[i])
    //     // dq.pop_back();
    //     // dq.push_back(i);


    
    //     while(!dq.empty()&&nums[dq.back()]<nums[i])
    //     dq.pop_back();
    //     dq.push_back(i);
    //     if(!dq.empty()&&i-dq.front()>=k){
    //         dq.pop_front();
    //     }

    //     ans.push_back(nums[dq.front()]);
    //  }
    //  return ans;





        priority_queue<pair<int,int>>pq;
        vector<int>ans;
        for(int i=0;i<k;i++){
            while(!pq.empty()&&pq.top().first<=arr[i]){//this means whole heap is less than current //here this loop empties the heap
               pq.pop();
            }
            pq.push({arr[i],i});
        }
        ans.push_back(pq.top().first);
        for(int i=k;i<arr.size();i++){
            while(!pq.empty()&&i-pq.top().second>=k) pq.pop();
            while(!pq.empty()&&pq.top().first<=arr[i]){
                pq.pop();
            }
            pq.push({arr[i],i});
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};