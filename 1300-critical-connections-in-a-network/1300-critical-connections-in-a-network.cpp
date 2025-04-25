class Solution {
public:
    void bridge(int s,unordered_map<int,bool>&visited,unordered_map<int,list<int>>&adjList,vector<int>&low,vector<int>&num,vector<vector<int>>&ans,int parent,int &timer){
      visited[s]=1;
      num[s]=low[s]=++timer;
      for(auto &nbr:adjList[s]){
        if(!visited[nbr]){
            bridge(nbr,visited,adjList,low,num,ans,s,timer);
            low[s]=min(low[s],low[nbr]);
            if(low[nbr]>num[s]){
                ans.push_back({s,nbr});
            }
        }
        else if(visited[nbr]&&nbr!=parent){
            low[s]=min(low[s],num[nbr]);
        }
      }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
       unordered_map<int,list<int>>adjList;
       for(int i=0;i<connections.size();i++){
        adjList[connections[i][0]].push_back(connections[i][1]);
        adjList[connections[i][1]].push_back(connections[i][0]);
       }
       vector<vector<int>>ans;
       vector<int>low(n,-1);
       vector<int>num(n,-1);
       unordered_map<int,bool>visited;
       int timer=0;
       for(int i=0;i<n;i++){
       if(!visited[i])
       bridge(i,visited,adjList,low,num,ans,-1,timer);
       }
       return ans;
    }
};