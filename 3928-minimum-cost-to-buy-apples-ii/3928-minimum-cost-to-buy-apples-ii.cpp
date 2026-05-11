class Solution {
public:
    vector<int> minCost(long n, vector<int>& prices, vector<vector<int>>& roads) {
        vector<vector<long>>empty;
        vector<vector<long>>full;
        unordered_map<long,list<vector<long>>>adjList;
        for(auto &each:roads){
            adjList[each[0]].push_back({each[1],each[2],each[3]});
            adjList[each[1]].push_back({each[0],each[2],each[3]});
        }
        for(long src=0;src<n;src++){
            priority_queue<pair<long,long>,vector<pair<long,long>>,greater<>>pq;
            vector<long>cost(n,LONG_MAX);
            cost[src]=0;
            pq.push({0,src});
            while(!pq.empty()){
                auto top=pq.top();
                long shop=top.second;
                pq.pop();
                for(auto &adj:adjList[shop]){
                    long c=adj[1];long v=adj[0];
                    if(cost[shop]+c<cost[v]){
                        cost[v]=cost[shop]+c;
                        pq.push({cost[v],v});
                    }
                }
            }
            empty.push_back(cost);
        }

        for(long src=0;src<n;src++){
            priority_queue<pair<long,long>,vector<pair<long,long>>,greater<>>pq;
            vector<long>cost(n,LONG_MAX);
            cost[src]=prices[src];
            pq.push({cost[src],src});
            while(!pq.empty()){
                auto top=pq.top();
                long shop=top.second;
                pq.pop();
                for(auto &adj:adjList[shop]){
                    long c=adj[1];long v=adj[0];long tax=adj[2];
                    if(cost[shop]+c*tax<cost[v]){
                        cost[v]=cost[shop]+c*tax;
                        pq.push({cost[v],v});
                    }
                }
            }
            full.push_back(cost);
        }

        vector<int>ans;
        for(long shop=0;shop<n;shop++){
            long mini=LONG_MAX;
            for(long dst=0;dst<n;dst++){
               if(empty[shop][dst]!=LONG_MAX&&full[dst][shop]!=LONG_MAX)
               mini=min(mini,empty[shop][dst]+full[dst][shop]);
            }
            ans.push_back((int)mini);
        }
        return ans;
    }
};