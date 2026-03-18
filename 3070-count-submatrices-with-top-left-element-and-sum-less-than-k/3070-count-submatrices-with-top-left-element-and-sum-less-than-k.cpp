class Solution {
public:
    int countSubmatrices(vector<vector<int>>& prefix, int k) {
        int m=prefix.size();int n=prefix[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            bool flag=false;
            for(int j=0;j<n;j++){
                 prefix[i][j]=prefix[i][j]+((i>0?prefix[i-1][j]:0)+(j>0?prefix[i][j-1]:0)-(i>0&&j>0?prefix[i-1][j-1]:0));
                 if(prefix[i][j]<=k){
                    flag=true;
                    ans++;
                 }
                 else break;
            }
            if(!flag) break;
        }
        return ans;
    }
};