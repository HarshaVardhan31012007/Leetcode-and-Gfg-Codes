class Solution {
public:
    bool findtopo(vector<vector<int>>&v,int k,vector<int>&temp,int &idx){
        vector<int>inorder(k);
        vector<vector<int>>adj(k);
        for(auto &each:v){
            inorder[each[1]-1]++;
            adj[each[0]-1].push_back(each[1]-1);
        }
        queue<int>q;
        for(int i=0;i<k;i++){
            if(inorder[i]==0)
            q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            temp[node]=idx++;
            k--;
            for(auto &adjNode:adj[node]){
                inorder[adjNode]--;
                if(inorder[adjNode]==0){
                    q.push(adjNode);
                }
            }
        }
        return k==0;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int>row(k,-1),col(k,-1);
        vector<vector<int>>ans(k,vector<int>(k,0));
        int idx1=0,idx2=0;
        if(!findtopo(rowConditions,k,row,idx1)) return {};
        if(!findtopo(colConditions,k,col,idx2)) return {};
        for(int i=0;i<k;i++){
            int r=(row[i]==-1?idx1:row[i]);
            int c=(col[i]==-1?idx2:col[i]);
            ans[r][c]=(i+1);
        }
        return ans;
    }
};