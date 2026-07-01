class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({capital[i],profits[i]});
        }
        sort(v.begin(),v.end());
        priority_queue<pair<int,int>>pq;
        int i=0;
        int ans=w;
        while(i<n&&k>0){
            while(i<n&&v[i].first<=ans){
                pq.push({v[i].second,i});
                i++;
            }
            if(pq.empty()||pq.top().first<=0) return ans;
            ans+=pq.top().first;
            pq.pop();k--;
        }
        while(k>0&&!pq.empty()&&pq.top().first>0){
            ans+=pq.top().first;
            k--;
            pq.pop();
        }
        return ans;
    }
};