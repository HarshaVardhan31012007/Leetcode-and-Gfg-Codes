class Solution {
  public:
    int find(vector<vector<int>> &mat,int mid){
        int count=0;
        for(int i=0;i<mat.size();i++){
            count+=upper_bound(mat[i].begin(),mat[i].end(),mid)-mat[i].begin();
        }
        return count;
    }
    int median(vector<vector<int>> &mat) {
       int n=mat.size();int m=mat[0].size();
       int l=mat[0][0];int h=mat[0][m-1];
       for(int i=1;i<n;i++){
           l=min(l,mat[i][0]);
           h=max(h,mat[i][m-1]);
       }
       int ans=-1;
       int left=(n*m+1)/2;
       while(l<=h){
           int mid=(l+h)/2;
          // if(find(mat,mid)>left){
          if(find(mat,mid)>=left){
               ans=mid;
               h=mid-1;
           }
           else{
               l=mid+1;
           }
       }
       return ans;
    }
};
