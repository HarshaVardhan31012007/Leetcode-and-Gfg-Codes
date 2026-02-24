class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        int V=adj.size();
        vector<int>visited(V,0);
        queue<int>q;
        q.push(0);
        visited[0]=1;
        vector<int>ans;
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            ans.push_back(front);
            for(auto &adj:adj[front]){
                if(!visited[adj]){
                    visited[adj]=1;
                    q.push(adj);
                }
            }
        }
        return ans;
    }
};