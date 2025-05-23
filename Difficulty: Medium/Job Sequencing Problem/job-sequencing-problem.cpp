class Solution {
  public:
//   static bool comp(pair<int,int>&a,pair<int,int>&b){
//       return a.first>b.first;
//   }
//     vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
//         int maxdeadline=*max_element(deadline.begin(),deadline.end());
//         vector<int>schedule(maxdeadline+1,-1);
//         vector<pair<int,int>>v;
//         for(int i=0;i<profit.size();i++){
//             v.push_back({profit[i],deadline[i]});
//         }
//         sort(v.begin(),v.end(),comp);
//         int profi=0;int count=0;
//         for(int i=0;i<v.size();i++){
//             int &curprofit=v[i].first;
//             int &dead=v[i].second;
//             for(int k=dead;k>0;k--){
//                 if(schedule[k]==-1){
//                     schedule[k]=dead;
//                     profi+=curprofit;
//                     count++;
//                     break;
//                 }
//             }
//         }
//         return {count,profi};
//     }


    int find(vector<int>&parent,int i){
        if(parent[i]==i) return i;
        return parent[i]=find(parent,parent[i]);
    }
    void unionSet(vector<int>&parent,int i,int j){
        i=find(parent,i);
        j=find(parent,j);
        parent[j]=i;
    }
static bool comp(pair<int,int>&a,pair<int,int>&b){
      return a.first>b.first;
  }
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int maxdeadline=*max_element(deadline.begin(),deadline.end());
        vector<int>schedule(maxdeadline+1,-1);
        vector<pair<int,int>>v;
        for(int i=0;i<profit.size();i++){
            v.push_back({profit[i],deadline[i]});
        }
        sort(v.begin(),v.end(),comp);
        int profi=0;int count=0;
        vector<int>parent(maxdeadline+1,0);
        for(int i=0;i<maxdeadline+1;i++){
            parent[i]=i;
        }
        for(int i=0;i<v.size();i++){
            int &curprofit=v[i].first;
            int &dead=v[i].second;
            int slots=find(parent,dead);
            if(slots>0){
                profi+=curprofit;
                unionSet(parent,slots-1,slots);
                count++;
            }
        }
        return {count,profi};
    }
};