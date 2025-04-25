class Solution {
public:
int find(int k,vector<int>&path){
    for(int i=0;i<path.size();i++){
        if(path[i]==k)
        return i;
    }
    return -1;
}
    void dfs(unordered_map<int,list<int>>&adjList,unordered_map<int,bool>&visited,unordered_map<int,bool>&pvisited,vector<int>&path,int &maxi,int s,int n){
          visited[s]=1;
          pvisited[s]=1;
          path.push_back(s);
          for(auto &nbr:adjList[s]){
             if(!visited[nbr]){
                dfs(adjList,visited,pvisited,path,maxi,nbr,n);
             }
             else if(visited[nbr]&&pvisited[nbr]){
                int b=path.size()-find(nbr,path);
                maxi=max(maxi,b);
             }
          }
          path.pop_back();
          pvisited[s]=0;
    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        unordered_map<int,list<int>>adjList;
        for(int i=0;i<edges.size();i++){
            adjList[i].push_back(edges[i]);
        }
        vector<int>path;
        unordered_map<int,bool>visited;
        unordered_map<int,bool>pvisited;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
        if(!visited[i]){
        dfs(adjList,visited,pvisited,path,maxi,i,n);
        pvisited.clear();
        }
        }
        return (maxi==INT_MIN)?-1:maxi;
    }
};