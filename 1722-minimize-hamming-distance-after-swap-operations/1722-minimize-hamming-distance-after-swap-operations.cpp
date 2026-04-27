class Solution {
public:
    // int find(vector<int>&a,vector<int>&b){
    //     int c=0;
    //     for(int i=0;i<a.size();i++){
    //         if(a[i]!=b[i]) c++;
    //     }
    //     return c;
    // }
    // int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
    //    queue<vector<int>>q;
    //    q.push(source);
    //    map<vector<int>,int>visited;
    //    visited[source]=1;
    //    int ans=INT_MAX;
    //    while(!q.empty()){
    //       vector<int>v=q.front();
    //       q.pop();
    //       ans=min(ans,find(v,target));
    //       for(auto &each:allowedSwaps){
    //         int x=each[0];
    //         int y=each[1];
    //         swap(v[x],v[y]);
    //         if(!visited[v]){
    //             q.push(v);
    //             visited[v]=1;
    //         }
    //       }
    //    }
    //    return ans;
    // }




    class DSU{
        public:
        vector<int>rank;
        vector<int>parent;
        int size;
        DSU(int n){
            size=n;
            parent.resize(n);
            rank.resize(n,0);
            for(int i=0;i<n;i++){
                parent[i]=i;
            }
        }
        int find(int p){
            if(parent[p]==p) return p;
            return parent[p]=find(parent[p]);
        }
        void Union(int a,int b){
             a=find(a);
             b=find(b);
             if(a==b) return;
             if(rank[a]<rank[b]){
                parent[a]=b;
             }
             else if(rank[b]>rank[a]){
                parent[a]=b;
             }
             else{
                parent[b]=a;
                rank[a]++;
             }
        }
    };
    // int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
    //    int n=source.size();
    //    DSU dsu(n);
    //    for(auto &each:allowedSwaps){
    //        dsu.Union(each[0],each[1]);
    //    }
    //    unordered_map<int,multiset<int>>mpp;
    //    for(int i=0;i<n;i++){
    //       int p=dsu.find(i);
    //       mpp[p].insert(source[i]);
    //    }
    //    int ans=0;
    //    for(int i=0;i<n;i++){
    //       int p=dsu.find(i);
    //       if(mpp[p].count(target[i])){
    //          auto it=mpp[p].find(target[i]);
    //          mpp[p].erase(it);
    //       }
    //       else
    //       ans++;
    //    }
    //    return ans;
    // }



    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
       int n=source.size();
       DSU dsu(n);
       for(auto &each:allowedSwaps){
           dsu.Union(each[0],each[1]);
       }
       unordered_map<int,unordered_map<int,int>>mpp;
       for(int i=0;i<n;i++){
          int p=dsu.find(i);
          mpp[p][source[i]]++;
       }
       int ans=0;
       for(int i=0;i<n;i++){
          int p=dsu.find(i);
          if(mpp[p][target[i]]>0){
             mpp[p][target[i]]--;
          }
          else
          ans++;
       }
       return ans;
    }
};