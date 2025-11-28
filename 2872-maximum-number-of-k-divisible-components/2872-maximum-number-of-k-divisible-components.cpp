class Solution {
public:
    // int dfs(int s,unordered_map<int,list<int>>&adjList,unordered_map<int,bool>&visited,vector<int>&values,int &count,int &k){
    //     visited[s]=1;
    //     int rem=values[s]%k;
    //     for(auto &adj:adjList[s]){
    //         if(!visited[adj])
    //         rem=(rem+dfs(adj,adjList,visited,values,count,k))%k;
    //     }
    //     if(rem==0) count++;
    //     return rem;   
    // }
    // int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
    //      int count=0;
    //      unordered_map<int,bool>visited;
    //      unordered_map<int,list<int>>adjList;
    //      for(auto &edge:edges){
    //         adjList[edge[0]].push_back(edge[1]);
    //         adjList[edge[1]].push_back(edge[0]);
    //      }
    //      //as min size is 1 ,so in any case we can start from 0 node
    //      dfs(0,adjList,visited,values,count,k);
    //      return count;
    // }



    
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        //important hai indegree is 0 for single nodes
        if(n==1) return 1;//n<2
         unordered_map<int,list<int>>adjList;
         vector<int>indegree(n,0);
         for(auto &edge:edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
            indegree[edge[1]]++;
         }
         queue<int>q;
         unordered_map<int,bool>visited;
         for(int i=0;i<n;i++){
            //indegree means neighbours as it is undirected if neighbours are 1 then it is leaf node
            if(indegree[i]==1){
               q.push(i);
               visited[i]=1;
            }
         }
         int count=0;
         while(!q.empty()){
            auto front=q.front();
            indegree[front]--;
            q.pop();
            int rem=values[front]%k;
            if(rem==0) count++;
            for(auto &adj:adjList[front]){
                 indegree[adj]--;
                if(indegree[adj]==1)
                q.push(adj);
                values[adj]=(values[adj]%k+rem)%k;
            }
         }
         return count;
    }
};