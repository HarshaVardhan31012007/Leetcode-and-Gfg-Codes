class Solution {
public:
    // class DSU{
    //    public:
    //    vector<int>parent;
    //    vector<int>rank;
    //    DSU(int n){
    //      rank.resize(n,0);
    //      parent.resize(n);
    //      for(int i=0;i<n;i++){
    //         parent[i]=i;
    //      }
    //    }  
    //    int find(int node){
    //      if(parent[node]==node) return node;
    //      return parent[node]=find(parent[node]);
    //    }
    //    void Union(int a,int b){
    //      a=find(a);
    //      b=find(b);
    //      if(a==b) return;
    //      if(rank[a]<rank[b]){
    //         parent[a]=b;
    //      }
    //      else if(rank[a]>rank[b]){
    //         parent[b]=a;
    //      }
    //      else{
    //         parent[b]=a;
    //         rank[a]++;
    //      }
    //    }
    // };
    int longestConsecutive(vector<int>& nums) {
        // unordered_map<int,int>mpp;
        // int ans=INT_MIN;
        // for(int i=0;i<nums.size();i++){
        //     int c=1;
        //     int k=nums[i];
        //     while(mpp.count(k-1)){
        //         c++;k--;
        //     }
        //     k=nums[i];
        //     while(mpp.count(k+1)){
        //         c++;k++;
        //     }
        //     ans=max(ans,c);
        //     mpp[nums[i]]=i;
        // }
        // return ans==INT_MIN?0:ans;


        // sort(nums.begin(),nums.end());
        // if(nums.size()==0) return 0;
        // int c=1;
        // int ans=0;
        // for(int i=1;i<nums.size();i++){
        //     if(nums[i]==nums[i-1]) continue;
        //     if(nums[i]==(nums[i-1]+1)){
        //         c++;
        //     }
        //     else{
        //         ans=max(ans,c);
        //         c=1;
        //     }
        // }
        // ans=max(ans,c);
        // return ans;


        // unordered_map<int,int>mpp;
        // int n=nums.size();
        // DSU dsu(n);
        // for(int i=0;i<n;i++){
        //     if(!mpp.count(nums[i]))
        //     mpp[nums[i]]=i;
        //     if(mpp.count(nums[i]-1)){
        //         dsu.Union(mpp[nums[i]-1],mpp[nums[i]]);
        //     }
        //     if(mpp.count(nums[i]+1)){
        //         dsu.Union(mpp[nums[i]+1],mpp[nums[i]]);
        //     }
        // }
        // unordered_map<int,int>mpp1;
        // int ans=0;
        // for(int i=0;i<n;i++){
        //     int p=dsu.find(i);
        //     mpp1[p]++;
        //     ans=max(ans,mpp1[p]);
        // }
        // return ans;



        unordered_set<int>st;
        for(auto &each:nums)
        st.insert(each);
        int ans=0;
        for(auto &each:st){
            if(st.find(each-1)==st.end()){
                int temp=0;
                int num=each;
                while(st.count(num)){
                    temp++;
                    num++;
                }
                ans=max(ans,temp);
            }
        }
        return ans;
    }
};