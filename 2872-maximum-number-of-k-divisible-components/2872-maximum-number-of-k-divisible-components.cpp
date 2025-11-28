class Solution {
public:
    int dfs(int s,unordered_map<int,list<int>>&adjList,unordered_map<int,bool>&visited,vector<int>&values,int &count,int &k){
        visited[s]=1;
        int rem=values[s]%k;
        for(auto &adj:adjList[s]){
            if(!visited[adj])
            rem=(rem+dfs(adj,adjList,visited,values,count,k))%k;
        }
        if(rem==0) count++;
        return rem;   
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
         int count=0;
         unordered_map<int,bool>visited;
         unordered_map<int,list<int>>adjList;
         for(auto &edge:edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
         }
         //as min size is 1 ,so in any case we can start from 0 node
         dfs(0,adjList,visited,values,count,k);
         return count;
    }
};