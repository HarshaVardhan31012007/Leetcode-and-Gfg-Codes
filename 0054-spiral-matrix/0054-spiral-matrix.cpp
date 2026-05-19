class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int m=matrix.size();
        int n=matrix[0].size();
        int dx=0;int dy=0;
        while(m>=1&&n>=1){
            int i=0;
            int j=0;
            while(j<n){
                ans.push_back(matrix[i+dx][j+dy]);
                j++;
            }
            j=n-1;
            i=1;
            while(i<m){
                ans.push_back(matrix[i+dx][j+dy]);
                i++;
            }
            if(m==1) break;
            i=m-1;
            j=n-2;
            while(j>=0){
                ans.push_back(matrix[i+dx][j+dy]);
                j--;
            }
            if(n==1) break;
            i=m-2;
            j=0;
            while(i>=1){
                ans.push_back(matrix[i+dx][j+dy]);
                i--;
            }
            m-=2;
            n-=2;
            dx++;dy++;
        }
        return ans;
    }
};