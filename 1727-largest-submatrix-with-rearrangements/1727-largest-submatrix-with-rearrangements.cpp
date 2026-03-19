class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>prevh(n,0);
        vector<int>currh(n,0);
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                currh[j]=(matrix[i][j]==1?1+prevh[j]:0);
            }
            prevh=currh;
            sort(currh.rbegin(),currh.rend());
            for(int j=0;j<n;j++){
                ans=max(ans,(j+1)*(currh[j]));
            }
        }   
        return ans;
    }
};