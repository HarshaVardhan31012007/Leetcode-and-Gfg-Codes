class Solution {
public:
    bool findtopo(vector<vector<int>>&v,int k,vector<int>&temp){
        vector<int>inorder(k,-1);
        vector<vector<int>>adj(k);
        int nodes=0;
        for(auto &each:v){
            if(inorder[each[0]-1]==-1){
                inorder[each[0]-1]=0;
                nodes++;
            }
            if(inorder[each[1]-1]==-1){
                inorder[each[1]-1]=0;
                nodes++;
            }
            inorder[each[1]-1]++;
            adj[each[0]-1].push_back(each[1]-1);
        }
        queue<int>q;
        for(int i=0;i<k;i++){
            if(inorder[i]==0)
            q.push(i);
        }
        int idx=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            temp[node]=idx++;
            nodes--;
            for(auto &adjNode:adj[node]){
                inorder[adjNode]--;
                if(inorder[adjNode]==0){
                    q.push(adjNode);
                }
            }
        }
        for(auto &each:temp){
            if(each==-1)
            each=idx++;
        }
        return nodes==0;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int>row(k,-1),col(k,-1);
        vector<vector<int>>ans(k,vector<int>(k,0));
        if(!findtopo(rowConditions,k,row)) return {};
        if(!findtopo(colConditions,k,col)) return {};
        for(int i=0;i<k;i++){
            int r=row[i];
            int c=col[i];
            ans[r][c]=(i+1);
        }
        return ans;
    }
};