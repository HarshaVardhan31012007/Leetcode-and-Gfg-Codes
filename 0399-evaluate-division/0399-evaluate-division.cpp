class Solution {
public:
    void dfs(string src,string &dest,unordered_set<string>&visited,vector<double>&ans,double product,unordered_map<string,list<pair<string,double>>>&adjList){
        visited.insert(src);
        if(src==dest){
            ans.push_back(product);
            return;
        }
        for(auto &adj:adjList[src]){
            if(!visited.count(adj.first)){
                dfs(adj.first,dest,visited,ans,product*adj.second,adjList);
            }
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,list<pair<string,double>>>adjList;
        int n=equations.size();
        for(int i=0;i<n;i++){
            adjList[equations[i][0]].push_back({equations[i][1],values[i]});
            adjList[equations[i][1]].push_back({equations[i][0],1/values[i]});
        }
        int m=queries.size();
        vector<double>ans;
        for(int i=0;i<m;i++){
            string src=queries[i][0];
            string dest=queries[i][1];
            double cans=-1.0;
            if(!adjList.count(src)||!adjList.count(dest)){
                ans.push_back(cans);
                continue;
            }
            unordered_set<string>visited;
            double product=1.0;
            int size=ans.size();
            dfs(src,dest,visited,ans,product,adjList);
            if((int)ans.size()==size)
            ans.push_back(cans);
        }
        return ans;
    }
};