class Solution {
public:
    class comp{
        public:
        bool operator()(pair<int,string>&a,pair<int,string>&b){
            if(a.first!=b.first)
            return a.first>b.first;
            return a.second<b.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>freq;
        for(auto &each:words){
            freq[each]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,comp>pq;
        for(auto &each:freq){
            pq.push({each.second,each.first});
            if(pq.size()>k)
            pq.pop();
        }
        // vector<string>ans;
        // while(!pq.empty()){
        //     ans.push_back(pq.top().second);
        //     pq.pop();
        // }
        // sort(ans.begin(),ans.end(),[&](string &a,string &b){
        //     if(freq[a]!=freq[b])
        //     return freq[a]>freq[b];
        //     return a<b;
        // });


        vector<string>ans(pq.size());
        int i=pq.size()-1;
        while(!pq.empty()){
            ans[i--]=pq.top().second;
            pq.pop();
        }
        return ans;
    }
};