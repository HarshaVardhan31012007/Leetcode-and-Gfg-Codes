class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        priority_queue<pair<int,int>>pq;
        vector<int>ans;
        for(int i=0;i<k;i++){
            while(!pq.empty()&&pq.top().first<=arr[i]){
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