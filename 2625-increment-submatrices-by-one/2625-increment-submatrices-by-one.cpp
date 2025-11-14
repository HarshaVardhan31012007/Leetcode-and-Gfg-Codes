class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        // vector<vector<int>>matrix(n,vector<int>(n,0));
        // for(auto &query:queries){
        //     int row1=query[0];int row2=query[2];
        //     int col1=query[1];int col2=query[3];
        //     for(int i=row1;i<=row2;i++){
        //         for(int j=col1;j<=col2;j++){
        //             matrix[i][j]++;
        //         }
        //     }
        // }
        // return matrix;



        vector<vector<int>>matrix(n,vector<int>(n,0));
        for(auto &query:queries){
            int row1=query[0];int row2=query[2];
            int col1=query[1];int col2=query[3];
            for(int j=col1;j<=col2;j++){
                matrix[row1][j]++;
            }
            if(row2+1<n){
                for(int j=col1;j<=col2;j++){
                    matrix[row2+1][j]--;
                }
            }
        }
        for(int j=0;j<n;j++){
            for(int i=1;i<n;i++){
                matrix[i][j]+=matrix[i-1][j];
            }
        }
        return matrix;
    }
};