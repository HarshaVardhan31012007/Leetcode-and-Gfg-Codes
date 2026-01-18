class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>>prefixr(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            int sum=0;
            for(int j=0;j<n;j++){
                sum+=grid[i][j];
                prefixr[i][j]=sum;
            }
        }

        vector<vector<int>>prefixc(m,vector<int>(n,0));
        for(int j=0;j<n;j++){
            int sum=0;
            for(int i=0;i<m;i++){
                sum+=grid[i][j];
                prefixc[i][j]=sum;
            }
        }

        for(int side=min(m,n);side>=2;side--){
            for(int i=0;i+side<=m;i++){
                for(int j=0;j+side<=n;j++){
                      int diag=0;int antidiag=0;
                      for(int k=0;k<side;k++){
                          diag+=grid[i+k][j+k];
                          antidiag+=grid[i+k][j+side-1-k];
                      }
                      if(diag!=antidiag) continue;
                      int k;
                      for(k=0;k<side;k++){
                        int sum=prefixr[i+k][j+side-1]-(j>0?prefixr[i+k][j-1]:0);
                        if(sum!=diag) break;
                      }
                      if(k<side) continue;
                      for(k=0;k<side;k++){
                        int sum=prefixc[i+side-1][j+k]-(i>0?prefixc[i-1][j+k]:0);
                        if(sum!=diag) break;
                      }
                      if(k<side) continue;
                      return side;
                }
            }
        }
        return 1;
    }
};