//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

//Back-end complete function Template for C++


// } Driver Code Ends

class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int v=adj.size();
        vector<int>distance(v,-1);
        unordered_map<int,bool>visited;
        unordered_map<int,int>parent;
        queue<int>q;
        q.push(src);
        visited[src]=true;
        parent[src]=-1;
        distance[src]=0;
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            for(auto nbr:adj[front]){
                if(!visited[nbr]){
                    visited[nbr]=true;
                    parent[nbr]=front;
                    distance[nbr]=distance[front]+1;
                    q.push(nbr);
                }
            }
        }
        return distance;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int src;
        cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(adj, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
        cout << "~\n";
    }
}

// } Driver Code Ends