// class Solution {
// public:
//     int dfs(int node,vector<vector<int>>&adjList,vector<int>&visited,int &numberOfAdj){
//         visited[node]=1;
//         if(numberOfAdj==-1){
//             numberOfAdj=adjList[node].size();
//         } 
//         else if(numberOfAdj!=adjList[node].size()){
//             numberOfAdj=-2;
//         }
//         int curr=1;
//         for(auto &adj:adjList[node]){
//             if(!visited[adj])
//             curr+=dfs(adj,adjList,visited,numberOfAdj);
//         }
//         return curr;
//     }
//     int countCompleteComponents(int n, vector<vector<int>>& edges) {
//         vector<vector<int>>adjList(n);
//         for(auto &each:edges){
//             adjList[each[0]].push_back(each[1]);
//             adjList[each[1]].push_back(each[0]);
//         }
//         int ans=0;
//         vector<int>visited(n,0);
//         for(int i=0;i<n;i++){
//             if(!visited[i]){
//                 int numberOfAdj=-1;
//                 int currsize=dfs(i,adjList,visited,numberOfAdj);
//                 if(numberOfAdj==currsize-1)
//                 ans++;
//             }
//         }
//         return ans;
//     }
// };



class Solution {
public:
    void dfs(int node,vector<vector<int>>&adjList,vector<int>&visited,int &v,int &e){
        visited[node]=1;
        v++;
        e+=adjList[node].size();
        for(auto &adj:adjList[node]){
            if(!visited[adj])
            dfs(adj,adjList,visited,v,e);
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adjList(n);
        for(auto &each:edges){
            adjList[each[0]].push_back(each[1]);
            adjList[each[1]].push_back(each[0]);
        }
        int ans=0;
        vector<int>visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                int v=0;
                int e=0;
                dfs(i,adjList,visited,v,e);
                if((v*(v-1))==e)
                ans++;
            }
        }
        return ans;
    }
};