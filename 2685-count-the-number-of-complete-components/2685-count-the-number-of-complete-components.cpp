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



// class Solution {
// public:
//     void dfs(int node,vector<vector<int>>&adjList,vector<int>&visited,int &v,int &e){
//         visited[node]=1;
//         v++;
//         e+=adjList[node].size();
//         for(auto &adj:adjList[node]){
//             if(!visited[adj])
//             dfs(adj,adjList,visited,v,e);
//         }
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
//                 int v=0;
//                 int e=0;
//                 dfs(i,adjList,visited,v,e);
//                 if((v*(v-1))==e)
//                 ans++;
//             }
//         }
//         return ans;
//     }
// };



// class Solution {
// public:
//     void dfs(int node,vector<vector<int>>&adjList,vector<int>&visited,int &v,int &e){
//         visited[node]=1;
//         v++;
//         e+=adjList[node].size();
//         for(auto &adj:adjList[node]){
//             if(!visited[adj])
//             dfs(adj,adjList,visited,v,e);
//         }
//     }
//     int countCompleteComponents(int n, vector<vector<int>>& edges) {
//         vector<set<int>>vertex(n);
//         for(auto &each:edges){
//             vertex[each[0]].insert(each[1]);
//             vertex[each[1]].insert(each[0]);
//         }
//         int ans=0;
//         unordered_map<string,int>mpp;
//         for(int i=0;i<n;i++){
//            vertex[i].insert(i);
//            string temp="";
//            for(auto &each:vertex[i]){
//               temp+=to_string(each)+",";
//            }
//            mpp[temp]++;
//         }
//         for(auto &each:mpp){
//             int size=count(each.first.begin(),each.first.end(),',');
//             if(size==each.second)
//             ans++;
//         }
//         return ans;
//     }



class Solution {
public:
    int find(int node,vector<int>&parent){
        if(parent[node]==node) return node;
        return parent[node]=find(parent[node],parent);
    }
    void Union(int x,int y,vector<int>&parent,vector<int>&size){
        int node1=find(x,parent);
        int node2=find(y,parent);
        if(node1==node2) return;
        if(size[node1]<size[node2]){
            parent[node1]=node2;
            size[node2]+=size[node1];
        }
        else if(size[node1]>=size[node2]){
            parent[node2]=node1;
            size[node1]+=size[node2];
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int>size(n,1);
        vector<int>parent;
        for(int i=0;i<n;i++) 
        parent.push_back(i);
        int ans=0;
        for(auto &each:edges){
            Union(each[0],each[1],parent,size);
        }
        unordered_map<int,int>mpp;
        for(auto &each:edges){
            mpp[find(each[0],parent)]++;
        }
        for(int i=0;i<n;i++){
            if(find(i,parent)==i){
                int v=size[i];
                int e=mpp[i];
                if(v*(v-1)/2==e) ans++;
            }
        }
        return ans;
    }
};