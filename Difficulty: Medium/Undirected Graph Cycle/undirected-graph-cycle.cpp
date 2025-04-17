//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    bool detectCycle(vector<vector<int>>& edges,int n,unordered_map<int,bool>&visited,int src){
        queue<int>q;
        unordered_map<int,int>parent;
        q.push(src);
        visited[src]=true;
        parent[src]=-1;
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            for(auto &c:edges){
                int a=c[0];int b=c[1];
                int k;
                if(a==front) k=b;
                else if(b==front) k=a;
                else continue;
                    if(!visited[k]){
                        visited[k]=true;
                        parent[k]=front;
                        q.push(k);
                    }
                    else if(visited[k]==true&&parent[front]!=k){
                        return true;
                    }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        bool ans=false;
        unordered_map<int,bool>visited;
        int n=V;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans=detectCycle(edges,n,visited,i);
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
        bool ans = obj.isCycle(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends