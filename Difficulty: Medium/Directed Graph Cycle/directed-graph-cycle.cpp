//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
     bool detectCycle(vector<vector<int>>& edges,unordered_map<int,bool>&path,unordered_map<int,bool>&visited,int s){
        visited[s]=true;
        path[s]=true;
        for(auto &c:edges){
            int k;
            if(s==c[0]) k=c[1];
            else continue;
            if(!visited[k]){
                int ans=detectCycle(edges,path,visited,k);
                if(ans==true)
                return true;
            }
            else if(visited[k]==true && path[k]==true){
                return true;
            }
        }
        path[s]=false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        bool ans=false;
        unordered_map<int,bool>visited;
        unordered_map<int,bool>path;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                ans=detectCycle(edges,path,visited,i);
                if(ans==true)
                return true;
            }
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends