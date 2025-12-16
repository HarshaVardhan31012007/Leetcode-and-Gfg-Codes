class Solution {
public:
    void dfs(int s,int p,unordered_map<int,list<int>>&adjList,vector<int>&good,vector<int>&down){
        down[s]=good[s];
        for(auto &c:adjList[s]){
            if(c==p) continue;
            dfs(c,s,adjList,good,down);
            down[s]+=(down[c]>0?down[c]:0);
        }
    }
    void dfs1(int s,int p,unordered_map<int,list<int>>&adjList,vector<int>&up,vector<int>&down){
        if(p==-1){
            up[s]=0;
        }
        else{
            int val=up[p]+down[p]-(down[s]>0?down[s]:0);
            up[s]=max(0,val);
        }
        for(auto &c:adjList[s]){
            if(c==p) continue;
            dfs1(c,s,adjList,up,down);
        }
    }
    vector<int> maxSubgraphScore(int n, vector<vector<int>>& edges, vector<int>& good) {
        unordered_map<int,list<int>>adjList;
        for(auto &edge:edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        vector<int>up(n,0);
        vector<int>down(n,0);
        for(auto &each:good)
        each=(each==0?-1:each);//score of node
        dfs(0,-1,adjList,good,down);
        dfs1(0,-1,adjList,up,down);
        vector<int>ans;
        for(int i=0;i<n;i++)
        ans.push_back(up[i]+down[i]);
        return ans;
    }
};