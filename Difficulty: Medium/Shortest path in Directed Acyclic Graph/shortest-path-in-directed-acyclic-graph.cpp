//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    void dfs(int s,unordered_map<int,list<pair<int,int>>>&adjList,unordered_map<int,bool>&visited,vector<int>&distance){
        visited[s]=1;
        for(auto &nbr:adjList[s]){
            if(!visited[nbr.first]&&distance[s]+nbr.second<distance[nbr.first]){
                distance[nbr.first]=distance[s]+nbr.second;
                dfs(nbr.first,adjList,visited,distance);
            }
        }
        visited[s]=0;
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        unordered_map<int,bool>visited;
        unordered_map<int,list<pair<int,int>>>adjList;
        for(int i=0;i<E;i++){
            adjList[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        vector<int>distance(V,INT_MAX);
        distance[0]=0;
        dfs(0,adjList,visited,distance);
        for(auto &each:distance){
            if(each==INT_MAX)
            each=-1;
        }
        return distance;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends