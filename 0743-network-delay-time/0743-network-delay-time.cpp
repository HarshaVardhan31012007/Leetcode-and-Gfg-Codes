class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adjList(n);
        for(auto &time:times){
            int node1=time[0];int node2=time[1];
            int t=time[2];
            adjList[node1-1].push_back({node2-1,t});
        }
        vector<int>time(n,INT_MAX);
        priority_queue<pair<int,int>>pq;
        pq.push({0,k-1});
        time[k-1]=0;
        while(!pq.empty()){
            pair<int,int>curr=pq.top();
            int currTime=curr.first;
            int currNode=curr.second;
            pq.pop();
            if(currTime>time[currNode]) continue;
            for(auto &adj:adjList[currNode]){
                int adjNode=adj.first;
                int signalTravelTime=adj.second;
                if(currTime+signalTravelTime<time[adjNode]){
                    time[adjNode]=currTime+signalTravelTime;
                    pq.push({time[adjNode],adjNode});
                }
            }
        }
        int minTime=*max_element(time.begin(),time.end());
        if(minTime==INT_MAX) return -1;
        return minTime;
    }
};