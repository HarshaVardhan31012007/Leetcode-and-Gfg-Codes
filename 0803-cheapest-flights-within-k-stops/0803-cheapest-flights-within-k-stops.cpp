class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {    
        unordered_map<int,list<pair<int,int>>>adjList;
        for(int i=0;i<flights.size();i++){
            adjList[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,src,0});
        vector<int>visited(n,INT_MAX);
        visited[src]=0;
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            if(curr[1]==dst) return curr[0];
            if(curr[2]>k) continue;
            if(visited[curr[1]]<curr[2]) continue;
            visited[curr[1]]=min(visited[curr[1]],curr[2]);
            for(auto &nbr:adjList[curr[1]]){
                pq.push({curr[0]+nbr.second,nbr.first,curr[2]+1});
            }
        }
        return -1;
    }
};