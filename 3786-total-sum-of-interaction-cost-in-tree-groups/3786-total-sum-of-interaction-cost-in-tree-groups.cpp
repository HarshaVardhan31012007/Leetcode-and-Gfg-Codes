class Solution {
public:
    long long interactionCosts(int n, vector<vector<int>>& edges, vector<int>& group) {
        unordered_map<int,list<int>>adjList;
        for(auto &edge:edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        long long ans=0;
        vector<int>tcount(21,0);
        for(int i=0;i<group.size();i++)
        tcount[group[i]]++;//useful to calculate out count if we know incount at a edge
        function<vector<int>(int,int)>dfs=[&](int s,int p){
             vector<int>res(21,0);
             res[group[s]]++;
             for(auto &adj:adjList[s]){
                if(adj==p) continue;
                vector<int>down=dfs(adj,s);
                for(int i=1;i<21;i++){
                    if(down[i]<=0) continue;
                    int below=down[i];
                    int above=tcount[i]-down[i];
                    ans+=1LL*below*above;
                    res[i]+=below;
                }
             }
             return res;
        };
        dfs(0,-1);
        return ans;
    }
};