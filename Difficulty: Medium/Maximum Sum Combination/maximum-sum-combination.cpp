class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int idx=a.size()-1;
        priority_queue<pair<int,int>>pq;
        vector<int>ans;
        for(int i=0;i<b.size();i++){
            pq.push({a[a.size()-1]+b[i],idx});
        }
        int count=k;
        while(count--){
            auto top=pq.top();
            pq.pop();
            ans.push_back(top.first);
            if(top.second>0){
                pq.push({top.first+a[top.second-1]-a[top.second],top.second-1});
            }
        }
        return ans;
    }
};