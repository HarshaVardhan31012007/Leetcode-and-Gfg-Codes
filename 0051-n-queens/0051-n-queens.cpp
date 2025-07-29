// class Solution {
// public:
//     bool isSafe(int row,int col,vector<string>&temp,int n){
//         for(int i=0;i<n;i++){
//             if(temp[i][col]=='Q')
//             return false;
//         }
//         for(int i=row,j=col;i>=0&&j>=0;i--,j--){
//             if(temp[i][j]=='Q')
//             return false;
//         }
//         for(int i=row,j=col;i>=0&&j<n;i--,j++){
//             if(temp[i][j]=='Q')
//             return false;
//         }
//         return true;
//     }
//     void solve(int n,vector<vector<string>>&ans,vector<string>&temp,int row){
//         if(row==n){
//             ans.push_back(temp);
//             return;
//         }
//         for(int col=0;col<n;col++){
//             if(isSafe(row,col,temp,n)){
//                 temp[row][col]='Q';
//                 solve(n,ans,temp,row+1);
//                 temp[row][col]='.';
//             }
//         }
//     }
//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string>>ans;
//         vector<string>temp(n,string(n,'.'));
//         solve(n,ans,temp,0);
//         return ans;
//     }
// };



class Solution {
public:
    unordered_map<int,bool>colCheck;
    unordered_map<int,bool>udCheck;
    unordered_map<int,bool>ldCheck;
    void solve(int n,vector<vector<string>>&ans,vector<string>&temp,int row){
        if(row==n){
            ans.push_back(temp);
            return;
        }
        for(int col=0;col<n;col++){
            if(!colCheck[col]&&!udCheck[row+col]&&!ldCheck[row-col]){
                temp[row][col]='Q';
                colCheck[col]=true;
                udCheck[row+col]=true;
                ldCheck[row-col]=true;
                solve(n,ans,temp,row+1);
                colCheck[col]=false;
                udCheck[row+col]=false;
                ldCheck[row-col]=false;
                temp[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>temp(n,string(n,'.'));
        solve(n,ans,temp,0);
        return ans;
    }
};