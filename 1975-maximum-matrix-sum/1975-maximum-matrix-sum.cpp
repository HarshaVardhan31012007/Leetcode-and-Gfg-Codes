class Solution {
public:
    // long long maxMatrixSum(vector<vector<int>>& matrix) {
    //     long long sum=0;int m=matrix.size();int n=matrix[0].size();
    //     long long mini=LLONG_MAX;long long c=0;
    //     bool iszero=false;
    //     for(int i=0;i<m;i++){
    //        for(int j=0;j<n;j++){
    //           sum+=abs(matrix[i][j]);
    //           mini=min(mini,1LL*abs(matrix[i][j]));
    //           if(i+1<m&&matrix[i+1][j]==0)
    //           iszero=true;
    //           else if(j+1<n&&matrix[i][j+1]==0)
    //           iszero=true;
    //           else if(i>0&&matrix[i-1][j]==0)
    //           iszero=true;
    //           else if(j>0&&matrix[i][j-1]==0)
    //           iszero=true;
    //           if(matrix[i][j]<0){
    //             c++;
    //           }
    //        }
    //     }
    //     if(!iszero&&(c&1))
    //     sum-=2*mini;
    //     return sum;
    // }




    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0;int m=matrix.size();int n=matrix[0].size();
        long long mini=LLONG_MAX;long long c=0;
        for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
              sum+=abs(matrix[i][j]);
              mini=min(mini,1LL*abs(matrix[i][j]));
              if(matrix[i][j]<0){
                c++;
              }
           }
        }
        if(c&1)
        sum-=2*mini;
        return sum;
    }
};