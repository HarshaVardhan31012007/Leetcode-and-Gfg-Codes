class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // vector<int>ans;
        // unordered_map<int,int>mpp;
        // for(int i=0;i<nums.size();i++){
        //   mpp[nums[i]]++;
        // }
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        // for(auto it=mpp.begin();it!=mpp.end();it++){
        //      if(pq.size()<k){
        //         pq.push({it->second,it->first});
        //      }
        //      else{
        //         if(it->second>pq.top().first){
        //             pq.pop();
        //             pq.push({it->second,it->first});
        //         }
        //      }
        // }
        // while(!pq.empty()){
        //     ans.push_back(pq.top().second);
        //     pq.pop();
        // }
        // return ans;


        vector<int>ans;
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++)
          mpp[nums[i]]++;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto it=mpp.begin();it!=mpp.end();it++){
            pq.push({it->second,it->first});
             if(pq.size()>k){
                pq.pop();
             }
        }
        while(!pq.empty()){
            // ans.push_back(pq.top().second);
            auto [frq,num]=pq.top();
            ans.push_back(num);
            pq.pop();
        }
        return ans;
    }
};