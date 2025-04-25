class Solution {
public:


// int find(int k,vector<int>&path){
//     for(int i=0;i<path.size();i++){
//         if(path[i]==k)
//         return i;
//     }
//     return -1;
// }
//     void dfs(unordered_map<int,list<int>>&adjList,unordered_map<int,bool>&visited,unordered_map<int,bool>&pvisited,vector<int>&path,int &maxi,int s,int n){
//           visited[s]=1;
//           pvisited[s]=1;
//           path.push_back(s);
//           for(auto &nbr:adjList[s]){
//              if(!visited[nbr]){
//                 dfs(adjList,visited,pvisited,path,maxi,nbr,n);
//              }
//              else if(visited[nbr]&&pvisited[nbr]){
//                 int b=path.size()-find(nbr,path);
//                 maxi=max(maxi,b);
//              }
//           }
//           path.pop_back();
//           pvisited[s]=0;
//     }
//     int longestCycle(vector<int>& edges) {
//         int n=edges.size();
//         unordered_map<int,list<int>>adjList;
//         for(int i=0;i<edges.size();i++){
//             adjList[i].push_back(edges[i]);
//         }
//         vector<int>path;
//         unordered_map<int,bool>visited;
//         unordered_map<int,bool>pvisited;
//         int maxi=INT_MIN;
//         for(int i=0;i<n;i++){
//         if(!visited[i]){
//         dfs(adjList,visited,pvisited,path,maxi,i,n);
//         }
//         }
//         return (maxi==INT_MIN)?-1:maxi;
//     }



    // void dfs(vector<int>&edges,unordered_map<int,bool>&visited,unordered_map<int,bool>&pvisited,vector<int>&dist,int &maxi,int s,int n,int length){
    //       visited[s]=1;
    //       pvisited[s]=1;
    //       dist[s]=length;
    //       int nbr=edges[s];
    //       if(nbr!=-1){
    //          if(!visited[nbr]){
    //             dfs(edges,visited,pvisited,dist,maxi,nbr,n,length+1);
    //          }
    //          else if(visited[nbr]&&pvisited[nbr]){
    //             int b=dist[s]-dist[nbr]+1;
    //             maxi=max(maxi,b);
    //          }
    //       }
    //       pvisited[s]=0;
    // }
    // int longestCycle(vector<int>& edges) {
    //     int n=edges.size();
    //     vector<int>dist(n,0);
    //     int length=0;
    //     unordered_map<int,bool>visited;
    //     unordered_map<int,bool>pvisited;
    //     int maxi=-1;
    //     for(int i=0;i<n;i++){
    //     if(!visited[i]){
    //     dfs(edges,visited,pvisited,dist,maxi,i,n,length);
    //     }
    //     }
    //     return maxi;
    // }






    void topoSort(vector<int>&edges,int n,unordered_map<int,bool>&visited){
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++){
        if(edges[i]!=-1)
        indegree[edges[i]]++;
        }
        queue<int>q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0)
            q.push(i);
        }
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            visited[front]=1;
            int node=edges[front];
            if(node!=-1){
                indegree[node]--;
                if(indegree[node]==0)
                q.push(node);
            }
        }
    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int>ans;
        int maxi=-1;
        unordered_map<int,bool>visited;
        topoSort(edges,n,visited);
        for(int i=0;i<n;i++){
        if(visited[i]==1) continue;
        int start=i;
        int curr=edges[i];
        visited[i]=1;
        int c=1;
        while(curr!=start){
          visited[curr]=1;
          curr=edges[curr];
          c++;  
        }
        maxi=max(maxi,c);
        }
        return maxi;
    }

};