class Solution {
public:
    // void dfs(int s,int e,vector<vector<int>>&graph,vector<int>&temp,vector<vector<int>>&ans){
    //     temp.push_back(s);
    //     if(s==e){
    //         ans.push_back(temp);
    //         temp.pop_back();
    //         return;
    //     }
    //     for(auto &adjNode:graph[s]){
    //         dfs(adjNode,e,graph,temp,ans);
    //     }
    //     temp.pop_back();
    // }
    // vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    //     vector<vector<int>>ans;
    //     vector<int>temp;
    //     int n=graph.size();
    //     dfs(0,n-1,graph,temp,ans);
    //     return ans;
    // }



    // void dfs(int s,int e,vector<vector<int>>&graph,vector<int>&temp,vector<vector<int>>&ans){
    //     if(s==e){
    //         ans.push_back(temp);
    //         return;
    //     }
    //     for(auto &adjNode:graph[s]){
    //         temp.push_back(adjNode);
    //         dfs(adjNode,e,graph,temp,ans);
    //         temp.pop_back();
    //     }
    // }
    // vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    //     vector<vector<int>>ans;
    //     vector<int>temp;
    //     int n=graph.size();
    //     temp.push_back(0);
    //     dfs(0,n-1,graph,temp,ans);
    //     return ans;
    // }



    
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        int n=graph.size();
        queue<vector<int>>q;
        q.push({0});
        while(!q.empty()){
            vector<int>curr=q.front();
            q.pop();
            if(curr.back()==(n-1)){
                ans.push_back(curr);
            }
            for(auto &adjNode:graph[curr.back()]){
                vector<int>path=curr;
                path.push_back(adjNode);
                q.push(path);
            }
        }
        return ans;
    }
};