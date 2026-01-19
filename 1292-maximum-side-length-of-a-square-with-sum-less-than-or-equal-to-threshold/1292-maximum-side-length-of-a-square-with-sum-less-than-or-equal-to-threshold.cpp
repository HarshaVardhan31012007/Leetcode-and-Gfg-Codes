class Solution {
public:
    // int maxSideLength(vector<vector<int>>& mat, int threshold) {
    //       int m=mat.size();
    //       int n=mat[0].size();
    //       vector<vector<int>>prefixr(m,vector<int>(n,0));
    //       for(int i=0;i<m;i++){
    //         int sum=0;
    //         for(int j=0;j<n;j++){
    //             sum+=mat[i][j];
    //             prefixr[i][j]=sum;
    //         }
    //       }
    //       int ans=0;
    //       for(int i=0;i<m;i++){
    //         for(int j=0;j<n;j++){
    //             for(int k=min(m-i,n-j);k>=1;k--){
    //                 int sum=0;
    //                 for(int r=0;r<k;r++){
    //                   sum+=prefixr[i+r][j+k-1]-(j>0?prefixr[i+r][j-1]:0);
    //                 }
    //                 if(sum<=threshold){
    //                     ans=max(ans,k);
    //                     break;
    //                 }
    //             }
    //         }
    //       }
    //       return ans;
    // }


    //  int maxSideLength(vector<vector<int>>& mat, int threshold) {
    //       int m=mat.size();
    //       int n=mat[0].size();
    //       vector<vector<int>>prefixr(m,vector<int>(n,0));
    //       for(int i=0;i<m;i++){
    //         int sum=0;
    //         for(int j=0;j<n;j++){
    //             sum+=mat[i][j];
    //             prefixr[i][j]=sum;
    //         }
    //       }
    //       int ans=0;
    //       for(int i=0;i<m;i++){
    //         for(int j=0;j<n;j++){
    //                 int s=1;int e=min(m-i,n-j);
    //                 while(s<=e){
    //                     int mid=s+(e-s)/2;
    //                     int sum=0;
    //                     for(int r=0;r<mid;r++){
    //                     sum+=prefixr[i+r][j+mid-1]-(j>0?prefixr[i+r][j-1]:0);
    //                     }
    //                     if(sum<=threshold){
    //                         ans=max(ans,mid);
    //                         s=mid+1;
    //                     }
    //                     else{
    //                         e=mid-1;
    //                     }
    //                 }
    //         }
    //       }
    //       return ans;
    // }



     int maxSideLength(vector<vector<int>>& mat, int threshold) {
          int m=mat.size();
          int n=mat[0].size();
          vector<vector<int>>prefixr(m,vector<int>(n,0));
          for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                prefixr[i][j]=mat[i][j]+(i>0?prefixr[i-1][j]:0)+(j>0?prefixr[i][j-1]:0)-(i>0&&j>0?prefixr[i-1][j-1]:0);
            }
          }
          int ans=0;
          for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                    int s=1;int e=min(m-i,n-j);
                    while(s<=e){
                        int mid=s+(e-s)/2;
                        int sum=prefixr[i+mid-1][j+mid-1]-(j>0?prefixr[i+mid-1][j-1]:0)-(i>0?prefixr[i-1][j+mid-1]:0)+(i>0&&j>0?prefixr[i-1][j-1]:0);
                        if(sum<=threshold){
                            ans=max(ans,mid);
                            s=mid+1;
                        }
                        else{
                            e=mid-1;
                        }
                    }
            }
          }
          return ans;
    }
};