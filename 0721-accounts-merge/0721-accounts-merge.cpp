class Solution {
public:
    int findParent(int u,vector<int>&parent){
       if(u==parent[u]) return u;
       return parent[u]=findParent(parent[u],parent);
    }
    void unionSet(int u,int v,vector<int>&parent,vector<int>&rank){
        u=findParent(u,parent);
        v=findParent(v,parent);
        if(rank[u]<rank[v]){
            parent[u]=v;
            rank[v]++;
        }
        else{
            parent[v]=u;
            rank[u]++;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        vector<int>parent(n);
        vector<int>rank(n,0);
        for(int i=0;i<n;i++)
        parent[i]=i;
        unordered_map<string,int>mpp;
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                auto it=mpp.find(mail);
                if(it==mpp.end()) mpp[mail]=i;
                else unionSet(i,it->second,parent,rank);
            }
        }
            // unordered_map<int,set<string>>preAns;
            // for(auto it:mpp){
            //     int accountNo=it.second;
            //     string mail=it.first;
            //     accountNo=findParent(accountNo,parent);
            //     preAns[accountNo].insert(mail);
            // }
            // vector<vector<string>>ans;
            // for(auto it:preAns){
            //    vector<string>v;
            //    v.push_back(accounts[it.first][0]);
            //    for(auto each:it.second) v.push_back(each);
            //    ans.push_back(v);
            // }
            //  return ans;


            unordered_map<int,vector<string>>preAns;
            for(auto it:mpp){
                int accountNo=it.second;
                string mail=it.first;
                accountNo=findParent(accountNo,parent);
                preAns[accountNo].push_back(mail);
            }
            vector<vector<string>>ans;
            for(auto it:preAns){
               vector<string>v;
               v.push_back(accounts[it.first][0]);
               for(auto each:it.second) v.push_back(each);
               sort(v.begin()+1,v.end());
               ans.push_back(v);
            }
             return ans;
    }
};