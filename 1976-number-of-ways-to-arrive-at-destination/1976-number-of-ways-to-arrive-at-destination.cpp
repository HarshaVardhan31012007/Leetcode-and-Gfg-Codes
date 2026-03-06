class Solution {
public:
    const int mod=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adjList(n);
        for(auto &each:roads){
            int u=each[0];
            int v=each[1];
            int w=each[2];
            adjList[u].push_back({v,w});
            adjList[v].push_back({u,w});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>>pq;
        pq.push({0,0});
        vector<long long>distance(n,LLONG_MAX);
        distance[0]=0;
        vector<long long>ways(n,0);
        ways[0]=1;
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            if(distance[top.second]<top.first) continue;
            for(auto &each:adjList[top.second]){
                int each0=each.first;int each1=each.second;
                if(top.first+each1<distance[each0]){
                    distance[each0]=top.first+each1;
                    ways[each0]=ways[top.second];
                    pq.push({distance[each0],each0});
                }
                else if(top.first+each1==distance[each0]){
                    ways[each0]=(ways[each0]+ways[top.second])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};