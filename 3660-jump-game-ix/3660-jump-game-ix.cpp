class Solution {
public:
    class DSU{
       public:
       vector<int>parent;
       vector<int>rank;
       DSU(int n){
         rank.resize(n,0);
         parent.resize(n);
         for(int i=0;i<n;i++){
            parent[i]=i;
         }
       }  
       int find(int node){
         if(parent[node]==node) return node;
         return parent[node]=find(parent[node]);
       }
       void Union(int a,int b){
         a=find(a);
         b=find(b);
         if(a==b) return;
         if(rank[a]<rank[b]){
            parent[a]=b;
         }
         else if(rank[a]>rank[b]){
            parent[b]=a;
         }
         else{
            parent[b]=a;
            rank[a]++;
         }
       }
    };
    vector<int> maxValue(vector<int>& nums) {
        int n=nums.size();
        DSU dsu(n);
        vector<int>ans(n);
        set<pair<int,int>>st;
        for(int i=0;i<n;i++){
            int num=nums[i];
            auto it=st.upper_bound({nums[i],i});
            int maxi=nums[i];
            while(it!=st.end()){
                dsu.Union(i,it->second);
                maxi=max(maxi,it->first);
                it=st.erase(it);
            }
            st.insert({maxi,i});
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<i;j++){
        //         if(nums[j]>nums[i]){
        //             dsu.Union(i,j);
        //         }
        //     }
        // }
        unordered_map<int,int>mpp1;
        for(int i=0;i<n;i++){
            int p=dsu.find(i);
            mpp1[p]=max(mpp1[p],nums[i]);
        }
        for(int i=0;i<n;i++){
            int p=dsu.find(i);
            ans[i]=mpp1[p];
        }
        return ans;
    }
};