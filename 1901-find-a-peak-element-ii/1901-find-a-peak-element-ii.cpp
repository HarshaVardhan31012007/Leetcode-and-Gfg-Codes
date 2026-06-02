class Solution {
public:
    int find(vector<vector<int>>& mat,int mid){
        int n=mat[0].size();
        int maxi=INT_MIN;
        int maxIndex=-1;
        for(int j=0;j<n;j++){
           if(maxi<mat[mid][j]){
              maxi=mat[mid][j];
              maxIndex=j;
           }
        }
        return maxIndex;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int s=0;
        int e=m-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            int maxIndex=find(mat,mid);
            if((mid==0||mat[mid-1][maxIndex]<mat[mid][maxIndex])&&(mid==m-1||mat[mid+1][maxIndex]<mat[mid][maxIndex])) return {mid,maxIndex};
            else if(mid>0&&mat[mid-1][maxIndex]>mat[mid][maxIndex]){
                e=mid-1;
            }
            else if(mid+1<m&&mat[mid+1][maxIndex]>mat[mid][maxIndex]){
                s=mid+1;
            }
        }
        return {-1,-1};
    }
};