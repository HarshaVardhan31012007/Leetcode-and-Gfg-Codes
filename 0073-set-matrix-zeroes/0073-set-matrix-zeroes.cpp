class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();int n=matrix[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                 q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            fill(matrix[p.first].begin(),matrix[p.first].end(),0);
            for(int i=0;i<m;i++){
                matrix[i][p.second]=0;
            }
        }
    }
};