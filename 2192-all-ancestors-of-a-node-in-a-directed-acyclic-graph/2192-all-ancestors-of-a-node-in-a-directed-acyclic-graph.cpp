class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<set<int>>ans(n);
        vector<int>inorder(n,0);
        vector<vector<int>>adj(n);
        for(auto &each:edges){
            adj[each[0]].push_back(each[1]);
            inorder[each[1]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(inorder[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto &adjNode:adj[node]){
                ans[adjNode].insert(ans[node].begin(),ans[node].end());
                ans[adjNode].insert(node);
                inorder[adjNode]--;
                if(inorder[adjNode]==0)
                q.push(adjNode);
            }
        }
        vector<vector<int>>temp;
        for(auto &each:ans){
            vector<int>temp1;
            temp1.insert(temp1.end(),each.begin(),each.end());
            temp.push_back(temp1);
        }
        return temp;
    }
};