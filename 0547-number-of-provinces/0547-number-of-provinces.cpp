class Solution {
public:
    void dfs(int src,int V,vector<vector<int>>&isConnected,vector<int>&visited){
          visited[src]=1;
          for(int i=0;i<V;i++){
             if(!visited[i]&&isConnected[src][i]){
                dfs(i,V,isConnected,visited);
             }
          }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int noOfProvinces=0;
        int V=isConnected.size();
        vector<int>visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,V,isConnected,visited);
                noOfProvinces++;
            }
        }
        return noOfProvinces;
    }
};