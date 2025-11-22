class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // unordered_map<int,int>freq;
        // for(auto &num:nums){
        //     freq[num]++;
        // }
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        // int count=0;
        // for(auto it=freq.begin();it!=freq.end();it++){
        //     if(count<k){
        //         pq.push({it->second,it->first});
        //         count++;
        //     }
        //     else if(it->second>=pq.top().first){
        //         pq.pop();
        //         pq.push({it->second,it->first});
        //     }
        // }
        // vector<int>ans;
        // while(!pq.empty()){
        //      ans.push_back(pq.top().second);
        //      pq.pop();
        // }
        // return ans;



         unordered_map<int,int>freq;
        for(auto &num:nums){
            freq[num]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        // for(auto it=freq.begin();it!=freq.end();it++){
        //     pq.push({it->second,it->first});
        //     if(pq.size()>k){
        //         pq.pop();
        //     }
        // }

         for(auto &each:freq){
            pq.push({each.second,each.first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int>ans;
        while(!pq.empty()){
            //  ans.push_back(pq.top().second);
             auto &[freq,num]=pq.top();
             ans.push_back(num);
             pq.pop();
        }
        return ans;
    }
};