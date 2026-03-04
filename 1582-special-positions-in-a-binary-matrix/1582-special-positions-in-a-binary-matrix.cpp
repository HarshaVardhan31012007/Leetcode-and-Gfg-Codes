class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<int>row(m);
        vector<int>column(n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                row[i]+=mat[i][j];
                column[j]+=mat[i][j];
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1&&row[i]==1&&column[j]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};