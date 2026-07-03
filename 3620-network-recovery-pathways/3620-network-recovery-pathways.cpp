class Solution {
public:
    vector<int>getToposort(unordered_map<int,list<pair<int,int>>>&adjList,vector<int>&indegree,int n){
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>toposort;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            toposort.push_back(node);
            for(auto &adjp:adjList[node]){
                int adj=adjp.first;
                indegree[adj]--;
                if(indegree[adj]==0){
                    q.push(adj);
                }
            }
        }
        return toposort;
    }
    bool possible(vector<int>&toposort,int n,long long mid,unordered_map<int,list<pair<int,int>>>&adjList,long long k){
        vector<long long>dist(n,LLONG_MAX);
        dist[0]=0;
        for(auto &node:toposort){
            if(dist[node]==LLONG_MAX) continue;
            for(auto &adj:adjList[node]){
                int adjNode=adj.first;
                int w=adj.second;
                if(w<mid) continue;
                dist[adjNode]=min(dist[adjNode],dist[node]+w);
            }
        }
        return dist[n-1]<=k;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n=online.size();
        unordered_map<int,list<pair<int,int>>>adjList;
        vector<int>indegree(n,0);
        int mn=1e9;int mx=-1;
        for(auto &edge:edges){
            if(online[edge[0]]&&online[edge[1]]){
               adjList[edge[0]].push_back({edge[1],edge[2]});
               mn=min(mn,edge[2]);
               mx=max(mx,edge[2]);
               indegree[edge[1]]++;
            }
        }
        if(mx==-1) return -1;
        vector<int>toposort=getToposort(adjList,indegree,n);
        int ans=-1;
        while(mn<=mx){
            long long mid=mn+(mx-mn)/2;
            if(possible(toposort,n,mid,adjList,k)){
                ans=mid;
                mn=mid+1;
            }
            else{
                mx=mid-1;
            }
        }
        return ans;
    }
};