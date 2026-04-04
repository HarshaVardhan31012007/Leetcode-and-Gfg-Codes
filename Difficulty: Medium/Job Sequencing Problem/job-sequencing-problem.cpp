class Solution {
  public:
    class DSU{
       public:
       vector<int>parent;
       DSU(int n){
           parent.resize(n);
           for(int i=0;i<n;i++)
           parent[i]=i;
       }
       int find(int a){
           if(parent[a]==a) return a;
           return parent[a]=find(parent[a]);
       }
       void Union(int a,int b){
           int c=find(a);
           int d=find(b);
           parent[c]=d;
       }
    };
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        
        // vector<pair<int,int>>v;
        // int n=deadline.size();
        // for(int i=0;i<n;i++){
        //     v.push_back({deadline[i],profit[i]});
        // }
        
        // sort(v.begin(),v.end(),[&](pair<int,int>&a,pair<int,int>&b){
        //     if(a.second!=b.second) return a.second>b.second;
        //     return a.first>b.first;
        // });
        // unordered_set<int>st;
        // int ans1=0;int ans2=0;
        // for(int i=0;i<n;i++){
        //     int d=v[i].first-1;
        //     while(d>=0){
        //         if(!st.count(d)){
        //             st.insert(d);
        //             ans1++;
        //             ans2+=v[i].second;
        //             break;
        //         }
        //         d--;
        //     }
        // }
        // return {ans1,ans2};
        
        
        
        
        // vector<pair<int,int>>v;
        // int maxDeadline=INT_MIN;
        // int n=deadline.size();
        // for(int i=0;i<n;i++){
        //     v.push_back({deadline[i],profit[i]});
        //     maxDeadline=max(maxDeadline,deadline[i]);
        // }
        // sort(v.begin(),v.end(),[&](pair<int,int>&a,pair<int,int>&b){
        //     if(a.second!=b.second) return a.second>b.second;
        //     return a.first>b.first;
        // });
        // vector<int>schedule(maxDeadline,-1);
        // int ans1=0;int ans2=0;
        // for(int i=0;i<n;i++){
        //     int d=v[i].first-1;
        //     while(d>=0){
        //         if(schedule[d]==-1){
        //             schedule[d]=d;
        //             ans1++;
        //             ans2+=v[i].second;
        //             break;
        //         }
        //         d--;
        //     }
        // }
        // return {ans1,ans2};
        
        
        
        
        vector<pair<int,int>>v;
        int maxDeadline=INT_MIN;
        int n=deadline.size();
        for(int i=0;i<n;i++){
            v.push_back({deadline[i],profit[i]});
            maxDeadline=max(maxDeadline,deadline[i]);
        }
        sort(v.begin(),v.end(),[&](pair<int,int>&a,pair<int,int>&b){
            if(a.second!=b.second) return a.second>b.second;
            return a.first>b.first;
        });
        DSU dsu(maxDeadline+1);
        int ans1=0;int ans2=0;
        for(int i=0;i<n;i++){
            int p=dsu.find(v[i].first);
            if(p!=0){
                ans1++;
                ans2+=v[i].second;
                dsu.Union(p,p-1);
            }
        }
        return {ans1,ans2};
        
    }
};