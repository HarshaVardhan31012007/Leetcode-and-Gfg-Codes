class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // priority_queue<int,vector<int>,greater<int>>pq;
        // for(int i=0;i<nums.size();i++){
        //     pq.push(nums[i]);
        // }
        // int freq=0;int prev=-1;
        // while(!pq.empty()){
        //    if(freq==0||pq.top()==prev){
        //    freq++;
        //    }
        //    else{
        //    if(k--){
        //     ans.push_back(prev);
        //    }
        //    freq=1;
        //    }
        //    prev=pq.top();
        //    pq.pop();
        // }
        // return ans;
        
        vector<int>ans;
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
          mpp[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto it=mpp.begin();it!=mpp.end();it++){
             if(pq.size()<k){
                pq.push({it->second,it->first});
             }
             else{
                if(it->second>pq.top().first){
                    pq.pop();
                    pq.push({it->second,it->first});
                }
             }
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};