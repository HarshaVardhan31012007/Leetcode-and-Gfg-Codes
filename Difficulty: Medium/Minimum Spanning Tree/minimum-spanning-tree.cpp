class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<int>MST(V,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        vector<vector<pair<int,int>>>adjList(V);
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            adjList[u].push_back({v,w});
            adjList[v].push_back({u,w});
        }
        pq.push({0,0});
        int sum=0;
        while(!pq.empty()){
            auto top=pq.top();
            int w=top.first;
            int node=top.second;
            pq.pop();
            if(MST[node]) continue;
            sum+=w;
            MST[node]=1;
            for(auto &adj:adjList[node]){
                if(!MST[adj.first]){
                    pq.push({adj.second,adj.first});
                }
            }
        }
        return sum;
    }
};