//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        unordered_map<int,list<pair<int,int>>>adjList;
        for(int i=0;i<m;i++){
            adjList[edges[i][0]-1].push_back({edges[i][1]-1,edges[i][2]});
            adjList[edges[i][1]-1].push_back({edges[i][0]-1,edges[i][2]});
        }
        vector<int>distance(n,INT_MAX);
        vector<int>parent(n,-1);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,0});
        distance[0]=0;
        parent[0]=-1;
        while(!q.empty()){
            auto front=q.top();
            q.pop();
            for(auto &nbr:adjList[front.second]){
                if(distance[front.second]+nbr.second<distance[nbr.first]){
                    parent[nbr.first]=front.second;
                    distance[nbr.first]=distance[front.second]+nbr.second;
                    q.push({distance[nbr.first],nbr.first});
                }
            }
        }
        vector<int>ans;
        int node=n-1;
        while(node!=-1){
            ans.push_back(node+1);
            node=parent[node];
        }
        ans.push_back(distance[n-1]);
        reverse(ans.begin(),ans.end());
        if(ans[0]==INT_MAX) return {-1};
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends