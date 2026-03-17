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
        
        void Union(int node1,int node2){
            int u=find(node1);
            int v=find(node2);
            if(u==v) return;
            if(rank[u]<rank[v]){
                parent[u]=v;
            }
            else if(rank[u]>rank[v]){
                parent[v]=u;
            }
            else{
                parent[v]=u;
                rank[u]++;
            }
        }
    };
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int numberOfAccounts=accounts.size();
        DSU dsu(numberOfAccounts);
        for(int i=0;i<numberOfAccounts;i++){
            for(int j=i+1;j<numberOfAccounts;j++){
                if(dsu.find(i)==dsu.find(j)) continue;
                vector<string>a=accounts[i];
                vector<string>b=accounts[j];
                if(a[0]==b[0]){
                    bool issame=false;
                    for(int p=1;p<a.size();p++){
                        for(int q=1;q<b.size();q++){
                            if(a[p]==b[q]){
                                issame=true;
                                break;
                            }
                        }
                    }
                    if(issame){
                        dsu.Union(i,j);
                    }
                }
            }
        }
            unordered_map<int,set<string>>mpp;
            for(int i=0;i<numberOfAccounts;i++){
                int par=dsu.find(i);
                vector<string>a=accounts[i];
                for(int j=1;j<a.size();j++){
                    mpp[par].insert(accounts[i][j]);
                }
            }
            vector<vector<string>>ans;
            for(auto &each:mpp){
                vector<string>temp;
                temp.push_back(accounts[each.first][0]);
                for(auto &each1:each.second)
                temp.push_back(each1);
                ans.push_back(temp);
            }
        return ans;
    }
};