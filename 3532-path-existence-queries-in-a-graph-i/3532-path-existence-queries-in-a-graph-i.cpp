// class Solution {
// public:
//     int find(int node,vector<int>&parent){
//         if(node==parent[node]) return node;
//         return parent[node]=find(parent[node],parent);
//     }
//     void Union(int node1,int node2,vector<int>&rank,vector<int>&parent){
//         if(rank[node1]<rank[node2]){
//             parent[node1]=node2;
//         }
//         else if(rank[node1]>rank[node2]){
//             parent[node2]=node1;
//         }
//         else{
//             parent[node2]=node1;
//             rank[node1]++;
//         }
//     }
//     vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
//         vector<int>rank(n,0);
//         vector<int>parent;
//         for(int i=0;i<n;i++) parent.push_back(i);
//         for(int i=1;i<n;i++){
//             int curr=nums[i];
//             int prev=nums[i-1];
//             if((curr-prev)<=maxDiff){
//                 int node1=find(i,parent);
//                 int node2=find(i-1,parent);
//                 if(node1!=node2){
//                     Union(node1,node2,rank,parent);
//                 }
//             }
//         }

//         vector<bool>ans;
//         for(auto &each:queries){
//             ans.push_back(find(each[0],parent)==find(each[1],parent));
//         }
//         return ans;
//     }
// };



class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>component;
        for(int i=0;i<n;i++) component.push_back(i);
        for(int i=1;i<n;i++){
            int curr=nums[i];
            int prev=nums[i-1];
            if((curr-prev)<=maxDiff){
                component[i]=component[i-1];
            }
        }

        vector<bool>ans;
        for(auto &each:queries){
            ans.push_back(component[each[0]]==component[each[1]]);
        }
        return ans;
    }
};