class Solution {
public:
    void dfs(int s,int e,vector<vector<int>>&graph,vector<int>&temp,vector<vector<int>>&ans){
        temp.push_back(s);
        if(s==e){
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        for(auto &adjNode:graph[s]){
            dfs(adjNode,e,graph,temp,ans);
        }
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int>temp;
        int n=graph.size();
        dfs(0,n-1,graph,temp,ans);
        return ans;
    }
};