class Solution {
public:
    // void dfs(vector<vector<int>>& isConnected,unordered_map<int,bool>&visited,int n,int s){
    //     visited[s]=1;
    //     for(int i=0;i<n;i++){
    //         if(isConnected[s][i]&&!visited[i]){
    //             dfs(isConnected,visited,n,i);
    //         }
    //     }
    // }
    void bfs(vector<vector<int>>& isConnected,unordered_map<int,bool>&visited,int n,int s){
       queue<int>q;
       visited[s]=1;
       q.push(s);
       while(!q.empty()){
        auto front=q.front();
        q.pop();
        for(int i=0;i<n;i++){
            if(isConnected[front][i]&&!visited[i]){
                visited[i]=1;
                q.push(i);
            }
        }
       }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count=0;
        int n=isConnected.size();
        unordered_map<int,bool>visited;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                // dfs(isConnected,visited,n,i);
                bfs(isConnected,visited,n,i);
                count++;
            }
        }
        return count;
    }
};