class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
    //  vector<vector<int>>ans(matrix[0].size(),vector<int>(matrix.size(),-1));
    //   for(int i=0;i<matrix[0].size();i++){
    //     for(int j=0;j<matrix.size();j++){
    //         ans[i][j]=matrix[j][i];
    //     }
    //   }
    //   return ans;  

     int m=matrix.size();
     int n=matrix[0].size();
     vector<vector<int>>ans(n,vector<int>(m,0));
     for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            ans[j][i]=matrix[i][j];
        }
      }
      return ans;  
    }
};