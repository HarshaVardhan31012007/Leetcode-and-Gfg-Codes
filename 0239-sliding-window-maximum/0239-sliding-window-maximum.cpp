class Solution {
public:
    // class compare{
    //    public:
    //    bool operator()(pair<int,int> a,pair<int,int> b){
    //       if(a.first!=b.first)
    //       return a.first<b.first;
    //       else
    //       return a.second<b.second;
    //    }
    // };


    //  class compare{
    //    public:
    //    bool operator()(pair<int,int> a,pair<int,int> b){
    //       return a.first<b.first;
    //    }
    // };
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        //priority_queue<pair<int,int>,vector<pair<int,int>>,compare>pq;
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<k;i++){
            pq.push({nums[i],i});
        }
        ans.push_back(pq.top().first);
        for(int i=k;i<nums.size();i++){
            pq.push({nums[i],i});
            while(i-pq.top().second>=k)
            pq.pop();
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};