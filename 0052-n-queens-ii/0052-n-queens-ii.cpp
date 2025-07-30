class Solution {
public:
    unordered_map<int,bool>colCheck;
    unordered_map<int,bool>udCheck;
    unordered_map<int,bool>ldCheck;
    int solve(int n,vector<string>&temp,int row){
        if(row==n){
            return 1;
        }
        int ans=0;
        for(int col=0;col<n;col++){
            if(!colCheck[col]&&!udCheck[row+col]&&!ldCheck[row-col]){
                temp[row][col]='Q';
                colCheck[col]=true;
                udCheck[row+col]=true;
                ldCheck[row-col]=true;
                ans+=solve(n,temp,row+1);
                colCheck[col]=false;
                udCheck[row+col]=false;
                ldCheck[row-col]=false;
                temp[row][col]='.';
            }
        }
        return ans;
    }
    int totalNQueens(int n) {
        vector<string>temp(n,string(n,'.'));
        return solve(n,temp,0);
    }
};