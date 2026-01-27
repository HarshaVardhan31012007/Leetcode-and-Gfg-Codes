class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int,list<pair<int,int>>>out;
        unordered_map<int,list<pair<int,int>>>in;
        for(auto &each:edges){
            out[each[0]].push_back({each[1],each[2]});
            in[each[1]].push_back({each[0],each[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        vector<int>cost(n,INT_MAX);
        vector<int>visited(n,0);
        cost[0]=0;
        pq.push({0,0});
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            if(top.second==(n-1)) return top.first;
            if(visited[top.second]) continue;
            visited[top.second]=1;
            for(auto &each:out[top.second]){
                if(1LL*cost[top.second]+1LL*each.second<1LL*cost[each.first]){
                    cost[each.first]=cost[top.second]+each.second;
                    pq.push({cost[each.first],each.first});
                }
            }
            for(auto &each:in[top.second]){
                if(1LL*cost[top.second]+2LL*each.second<1LL*cost[each.first]){
                    cost[each.first]=cost[top.second]+2*each.second;
                    pq.push({cost[each.first],each.first});
                }
            }
        }
        return -1;
    }
};