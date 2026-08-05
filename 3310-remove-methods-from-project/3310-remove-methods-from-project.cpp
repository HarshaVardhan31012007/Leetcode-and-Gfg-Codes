// class Solution {
// public:
//     void dfs(int node,vector<vector<int>>&adj,vector<int>&suspicious,bool &flag,int &color){
//         suspicious[node]=color;
//         for(auto &adjNode:adj[node]){
//             if(!suspicious[adjNode])
//             dfs(adjNode,adj,suspicious,flag,color);
//             else if(flag&&suspicious[adjNode]==1)
//             flag=false;
//         }
//     }
//     vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
//         vector<vector<int>>adj(n);
//         for(auto &each:invocations){
//             adj[each[0]].push_back(each[1]);
//         }
//         vector<int>suspicious(n,0);
//         bool flag=false;
//         int color=1;
//         dfs(k,adj,suspicious,flag,color);
//         flag=true;
//         color=2;
//         for(int i=0;i<n;i++){
//             if(!suspicious[i])
//             dfs(i,adj,suspicious,flag,color);
//         }
//         vector<int>ans;
//         for(int i=0;i<n;i++){
//             if(suspicious[i]==1&&flag)
//             continue;
//             ans.push_back(i);
//         }
//         return ans;
//     }
// };




class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        for(auto &each:invocations){
            adj[each[0]].push_back(each[1]);
            indegree[each[1]]++;
        }
        queue<int>q;
        q.push(k);
        vector<int>visited(n,0);
        visited[k]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto &adjNode:adj[node]){
                indegree[adjNode]--;
                if(!visited[adjNode]){
                    visited[adjNode]=1;
                    q.push(adjNode);
                }
            }
        }
        bool flag=true;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(visited[i]&&indegree[i]>0){
                flag=false;
                break;
            }
            if(!visited[i])
            ans.push_back(i);
        }
        if(!flag){
            vector<int>v;
            for(int i=0;i<n;i++) v.push_back(i);
            return v;
        }
        return ans;
    }
};