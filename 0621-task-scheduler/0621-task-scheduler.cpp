class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int,int>>pq;
        int freq[26]={0};
        for(auto &task:tasks){
            freq[task-'A']++;
        }
        for(int i=0;i<26;i++){
            if(freq[i])
            pq.push({freq[i],i});
        }
        int ans=0;
        while(!pq.empty()){
            int cycle=n+1;
            vector<pair<int,int>>v;
            while(cycle>0&&!pq.empty()){
                 auto top=pq.top();
                 pq.pop();
                 top.first--;
                 cycle--;
                 ans++;
                 v.push_back(top);
            }
            for(auto &each:v){
                if(each.first>0)
                pq.push(each);
            }
            if(!pq.empty())
            ans+=cycle;
        }
        return ans;
    }
};