//method 1 --DSU
//class Solution {
// public:
//     class DSU{
//        public:
//        vector<int>parent;
//        vector<int>rank;
//        DSU(int n){
//          rank.resize(n,0);
//          parent.resize(n);
//          for(int i=0;i<n;i++){
//             parent[i]=i;
//          }
//        }  
//        int find(int node){
//          if(parent[node]==node) return node;
//          return parent[node]=find(parent[node]);
//        }
//        void Union(int a,int b){
//          a=find(a);
//          b=find(b);
//          if(a==b) return;
//          if(rank[a]<rank[b]){
//             parent[a]=b;
//          }
//          else if(rank[a]>rank[b]){
//             parent[b]=a;
//          }
//          else{
//             parent[b]=a;
//             rank[a]++;
//          }
//        }
//     };
//     vector<int> maxValue(vector<int>& nums) {
//         int n=nums.size();
//         DSU dsu(n);
//         vector<int>ans(n);
//         set<pair<int,int>>st;
//         for(int i=0;i<n;i++){
//             int num=nums[i];
//             auto it=st.upper_bound({nums[i],i});
//             int maxi=nums[i];
//             while(it!=st.end()){
//                 dsu.Union(i,it->second);
//                 maxi=max(maxi,it->first);
//                 it=st.erase(it);// it necomes invalid after erase so erase function return ierator pointing to next element
//             }
//             st.insert({maxi,i});// to make sure that we can connect any other i suc that nums[i]<element erased
//         }
//         // for(int i=0;i<n;i++){
//         //     for(int j=0;j<i;j++){
//         //         if(nums[j]>nums[i]){
//         //             dsu.Union(i,j);
//         //         }
//         //     }
//         // }
//         unordered_map<int,int>mpp1;
//         for(int i=0;i<n;i++){
//             int p=dsu.find(i);
//             mpp1[p]=max(mpp1[p],nums[i]);
//         }
//         for(int i=0;i<n;i++){
//             int p=dsu.find(i);
//             ans[i]=mpp1[p];
//         }
//         return ans;
//     }
// };


//method 2--prefix and suffix

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n=nums.size();
        vector<int>PrefixMax(n);
        PrefixMax[0]=nums[0];
        for(int i=1;i<n;i++){
            PrefixMax[i]=max(nums[i],PrefixMax[i-1]);
        }
        vector<int>SuffixMin(n);
        vector<int>ans(n);
        SuffixMin[n-1]=nums[n-1];
        ans[n-1]=PrefixMax[n-1];
        for(int i=n-2;i>=0;i--){
            if(PrefixMax[i]>SuffixMin[i+1]){
                ans[i]=max(PrefixMax[i],ans[i+1]);
            }
            else
            ans[i]=PrefixMax[i];
            SuffixMin[i]=min(nums[i],SuffixMin[i+1]);
        }
        return ans;
    }
};