class Solution {
public:
    bool possible(int node,int currColor,vector<vector<int>>&graph,vector<int>&color){
        color[node]=currColor;
        for(auto &adjNode:graph[node]){
            if(color[adjNode]==color[node]) return false;
            if(color[adjNode]==-1){
                if(!possible(adjNode,!currColor,graph,color)) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!possible(i,0,graph,color)) return false;
            }
        }
        return true;
    }
};