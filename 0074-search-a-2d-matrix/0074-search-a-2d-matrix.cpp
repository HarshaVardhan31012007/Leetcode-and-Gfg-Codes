class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int s=0;
        int e=m*n-1;
        int mid=s+(e-s)/2;
        while(s<=e){
            int r=mid/n;
            int c=mid%n;
            if(matrix[r][c]==target)
            return true;
            if(matrix[r][c]>target)
            e=mid-1;
            if(matrix[r][c]<target)
            s=mid+1;
            mid=s+(e-s)/2;
        }
        return false;
    }
};