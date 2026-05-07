class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
       int m=box.size();
       int n=box[0].size();
       vector<vector<char>>res(n,vector<char>(m,'.'));
       for(int j=0;j<m;j++){
         int k=n-1;
         for(int i=n-1;i>=0;i--){
            int curr=box[m-j-1][i];
            if(curr=='#'){
                res[k][j]='#';
                k--;
            }
            else if(curr=='*'){
                res[i][j]='*';
                k=i-1;
            }
         }
       }
       return res;
    }
};