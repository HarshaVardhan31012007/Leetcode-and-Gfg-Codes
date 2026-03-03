class Solution {
public:
    // bool dfs(int src,int mark,vector<vector<int>>&graph,vector<int>&visited){
    //     visited[src]=mark;
    //     bool ans=true;
    //     for(auto &each:graph[src]){
    //         if(visited[each]==-1)
    //         ans=ans&&dfs(each,1-mark,graph,visited);
    //         else{
    //             if(visited[each]!=1-mark) return false;
    //         }
    //     }
    //     return ans;
    // }
    // bool isBipartite(vector<vector<int>>& graph) {
    //     int n=graph.size();
    //     int ans=true;
    //     vector<int>visited(n,-1);
    //     for(int i=0;i<n;i++){
    //         if(visited[i]==-1){
    //            ans=ans&&dfs(i,0,graph,visited);
    //         }
    //     }
    //     return ans;
    // }


    bool bfs(int src,vector<vector<int>>& graph,vector<int>&visited,int color){
        queue<int>q;
        q.push(src);
        visited[src]=color;
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            for(auto &each:graph[front]){
                if(visited[each]==-1){
                    visited[each]=!visited[front];
                    q.push(each);
                }
                else{
                    if(visited[each]==visited[front]) return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        int ans=true;
        vector<int>visited(n,-1);
        for(int i=0;i<n;i++){
            if(visited[i]==-1){
               ans=ans&&bfs(i,graph,visited,0);
            }
        }
        return ans;
    }
};