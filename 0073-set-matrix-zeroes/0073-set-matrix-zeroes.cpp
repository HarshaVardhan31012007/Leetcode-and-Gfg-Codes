class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        bool r=false;
        bool c=false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&matrix[i][j]==0) r=true;
                if(j==0&&matrix[i][j]==0) c=true;
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][0]==0||matrix[0][j]==0)
                matrix[i][j]=0;
            }
        }
        for(int j=1;j<n;j++){
            if(r){
                matrix[0][j]=0;
            }
        }
        for(int i=1;i<m;i++){
            if(c){
                matrix[i][0]=0;
            }
        }
    }
};