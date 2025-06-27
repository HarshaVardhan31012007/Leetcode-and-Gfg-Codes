class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();int n=matrix[0].size();
        // queue<pair<int,int>>q;
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(matrix[i][j]==0){
        //          q.push({i,j});
        //         }
        //     }
        // }
        // while(!q.empty()){
        //     auto p=q.front();
        //     q.pop();
        //     fill(matrix[p.first].begin(),matrix[p.first].end(),0);
        //     for(int i=0;i<m;i++){
        //         matrix[i][p.second]=0;
        //     }
        // }

       int col0=1;
       for(int i=0;i<m;i++){
        if(matrix[i][0]==0) col0=0;
        for(int j=1;j<n;j++){
            if(matrix[i][j]==0){
                matrix[i][0]=0;
                matrix[0][j]=0;
            }
        }
       }
       for(int i=m-1;i>=0;i--){
        for(int j=1;j<n;j++){
           if(matrix[i][0]==0||matrix[0][j]==0)
           matrix[i][j]=0;
        }
        if(col0==0) matrix[i][0]=0;
       }

    }
};