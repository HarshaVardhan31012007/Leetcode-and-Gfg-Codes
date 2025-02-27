class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>frq;

        for(auto each:tasks)
        frq[each]++;

        priority_queue<pair<int,char>>pq;

        for(auto e:frq)
        pq.push({e.second,e.first});

        int time=0;
        while(!pq.empty()){
            int cycle=n+1;
            vector<pair<int,char>>temp;
            while(cycle>0&&!pq.empty()){
                auto [freq,task]=pq.top();
                pq.pop();
                cycle--;
                time++;
                freq--;
                temp.push_back({freq,task});
            }

            for(auto each:temp){
                if(each.first>0)
                pq.push(each);
            }
            if(!pq.empty())
            time+=cycle;
        }
        return time;
    }
};