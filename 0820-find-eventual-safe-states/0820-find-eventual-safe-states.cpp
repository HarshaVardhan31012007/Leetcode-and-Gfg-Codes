class Solution {
public:
    bool checkCycle(int s,vector<vector<int>>& graph,unordered_map<int,bool>&visited,
    unordered_map<int,bool>&pvisited,int safenodes[],int n){
        visited[s]=1;
        pvisited[s]=1;
        safenodes[s]=0;
        for(auto &nbr:graph[s]){
            if(!visited[nbr]){
              bool ans=checkCycle(nbr,graph,visited,pvisited,safenodes,n);
              if(ans==true)
              return true;
            }
            else if(visited[nbr]==true&&pvisited[nbr]==true){
                return true;
            }
        }
        pvisited[s]=false;
        safenodes[s]=1;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        unordered_map<int,bool>visited;
        unordered_map<int,bool>pvisited;
        vector<int>ans;
        int *safenodes=new int[n];
        for(int i=0;i<n;i++){
            if(!visited[i])
            checkCycle(i,graph,visited,pvisited,safenodes,n);
        }
        for(int i=0;i<n;i++){
            if(safenodes[i]==1)
            ans.push_back(i);
        }
        return ans;
    }
};