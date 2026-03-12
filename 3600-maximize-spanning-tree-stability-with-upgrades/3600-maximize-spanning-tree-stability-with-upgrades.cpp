// class Solution {
// public:
//     int findParent(int u,vector<int>&parent){
//         if(parent[u]==u) return u;
//         return parent[u]=findParent(parent[u],parent);
//     }
//     void unionHelp(int u,int v,vector<int>&parent,vector<int>&rank){
//         if(rank[u]<rank[v]){
//             parent[u]=v;
//             rank[v]++;
//         }
//         else{
//             parent[v]=u;
//             rank[u]++;
//         }
//     }
//     int maxStability(int n, vector<vector<int>>& edges, int k) {
//         int minEdges=n-1;
//         int nedges=edges.size();
//         if(minEdges>nedges) return -1;
//         vector<int>parent(n,-1);
//         for(int i=0;i<n;i++)
//         parent[i]=i;
//         vector<int>rank(n,0);
//         priority_queue<pair<int,pair<int,int>>>pq;
//         int c=0;
//         int mini=INT_MAX;
//         for(auto &edge:edges){
//             int u=edge[0];int v=edge[1];int s=edge[2];
//             int must=edge[3];
//             if(must){
//                int node1=findParent(u,parent);int node2=findParent(v,parent);
//                if(node1==node2) return -1;
//                else unionHelp(node1,node2,parent,rank);
//                if(s<mini){
//                     mini=s;
//                 }
//                 c++;
//             }
//             else{
//                pq.push({s,{u,v}});
//             }
//         }
//         vector<int>v;
//         while(!pq.empty()){
//             auto front=pq.top();
//             int u=front.second.first;int v1=front.second.second;
//             int s1=front.first;
//             pq.pop();
//             int node1=findParent(u,parent);int node2=findParent(v1,parent);
//             if(node1==node2) continue;
//             unionHelp(node1,node2,parent,rank);
//             v.push_back(s1);
//             c++;
//         }
//         if(c!=n-1) return -1;
//         sort(v.begin(),v.end());
//         if(v.empty()) return mini;
//         for(int i=0;i<k&&i<v.size();i++)
//         v[i]=(v[i]*2);
//         int mini1=*min_element(v.begin(),v.end());
//         return min(mini,mini1);
//     }
// };



// class Solution {
// public:
//     int findParent(int u,vector<int>&parent){
//         if(parent[u]==u) return u;
//         return parent[u]=findParent(parent[u],parent);
//     }
//     void unionHelp(int u,int v,vector<int>&parent,vector<int>&rank){
//         if(rank[u]<rank[v]){
//             parent[u]=v;
//             rank[v]++;
//         }
//         else{
//             parent[v]=u;
//             rank[u]++;
//         }
//     }
//     int maxStability(int n, vector<vector<int>>& edges, int k) {
//         int minEdges=n-1;
//         int nedges=edges.size();
//         if(minEdges>nedges) return -1;
//         vector<int>parent(n,-1);
//         for(int i=0;i<n;i++)
//         parent[i]=i;
//         vector<int>rank(n,0);
//         priority_queue<pair<int,pair<int,int>>>pq;
//         int c=0;
//         int mini=INT_MAX;
//         for(auto &edge:edges){
//             int u=edge[0];int v=edge[1];int s=edge[2];
//             int must=edge[3];
//             if(must){
//                int node1=findParent(u,parent);int node2=findParent(v,parent);
//                if(node1==node2) return -1;//cycle
//                else unionHelp(node1,node2,parent,rank);
//                if(s<mini){
//                     mini=s;
//                 }
//                 c++;
//             }
//             else{
//                pq.push({s,{u,v}});
//             }
//         }
//         int mini1=INT_MAX;
//         priority_queue<int,vector<int>,greater<>>pq1;
//         while(!pq.empty()){
//             auto front=pq.top();
//             int u=front.second.first;int v1=front.second.second;
//             int s1=front.first;
//             pq.pop();
//             int node1=findParent(u,parent);int node2=findParent(v1,parent);
//             if(node1==node2) continue;
//             unionHelp(node1,node2,parent,rank);
//             pq1.push(s1);
//             c++;
//         }
//         while(!pq1.empty()&&k--){
//             auto top=pq1.top();
//             pq1.pop();
//             mini1=min(mini1,2*top);
//         }
//         while(!pq1.empty()){
//             mini1=min(mini1,pq1.top());
//             pq1.pop();
//         }
//         if(c!=n-1) return -1;//disconnected graph
//         return min(mini,mini1);
//     }



class Solution {
public:
    class DSU{
        public:
        vector<int>parent,rank;
        DSU(int n){
            parent.resize(n);
            rank.resize(n,0);
            for(int i=0;i<n;i++)
            parent[i]=i;
        }

        int find(int node){
            if(parent[node]==node) return node;
            return parent[node]=find(parent[node]);
        }

        bool Union(int node1,int node2){
            node1=find(node1);
            node2=find(node2);
            if(node1==node2) return false;
            if(rank[node1]<rank[node2]){
                parent[node1]=node2;
            }
            else if(rank[node1]>rank[node2]){
                parent[node2]=node1;
            }
            else{
                parent[node2]=node1;
                rank[node1]++;
            }
            return true;
        }
    };
    bool possible(int n,vector<vector<int>>&edges,int k,int mid){

        DSU dsu(n);

        vector<vector<int>>upgradeEdges;
        for(auto &edge:edges){

            int u=edge[0];
            int v=edge[1];
            int s=edge[2];
            int must=edge[3];
  
            if(must==1){
                if(s<mid) return false;
                dsu.Union(u,v);
            }
            else{
                if(s>=mid){
                    dsu.Union(u,v);
                }
                else if(2*s>=mid){
                    upgradeEdges.push_back({u,v});
                }
            }
        }
        for(auto &edge:upgradeEdges){

            int u=edge[0];
            int v=edge[1];
            if(dsu.find(u)!=dsu.find(v)){
                if(k<=0) return false;
                k--;
                dsu.Union(u,v);
            }
        }
        int root=dsu.find(0);
        for(int i=0;i<n;i++){
            if(dsu.find(i)!=root) return false; 
        }
        return true;
    }
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        DSU dsu(n);
        for(auto &edge:edges){

            int u=edge[0];
            int v=edge[1];
            int s=edge[2];
            int must=edge[3];
  
            if(must==1){
                if(dsu.find(u)==dsu.find(v)) return -1;
                dsu.Union(u,v);
            }
        }
        int s=1;
        int e=2*1e5;
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(possible(n,edges,k,mid)){
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return ans;
    }
};