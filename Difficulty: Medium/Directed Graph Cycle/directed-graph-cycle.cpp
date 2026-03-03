class Solution {
  public:
     bool detectCycle(vector<vector<int>>& edges,vector<int>&visited,int s){
        visited[s]=2;
        for(auto &c:edges){
            int k;
            if(s==c[0]) k=c[1];
            else continue;
            if(!visited[k]){
                int ans=detectCycle(edges,visited,k);
                if(ans==true)
                return true;
            }
            else if(visited[k]==2){
                return true;
            }
        }
        visited[s]=1;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        bool ans=false;
        vector<int>visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                ans=detectCycle(edges,visited,i);
                if(ans==true)
                return true;
            }
        }
        return false;
    }
};