class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int m=target.size();
        int n=target[0].size();
        if(m!=n) return false;
        bool flag=true;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                 if(mat[i][j]!=target[i][j]){
                    flag=false;
                    break;
                 }
            }
        }
        if(flag) return true;
        int count=3;
        while(count--){
            vector<vector<int>>temp(m,vector<int>(n));
            bool flag=true;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    int curr=mat[i][j];
                    int rotated=target[j][n-i-1];
                    if(curr!=rotated){
                        flag=false;
                    }
                    temp[j][n-i-1]=mat[i][j];
                }
            } 
            if(flag) return true;
            mat=temp;
        }
        return false;
    }
};