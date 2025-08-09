class Solution {
public:
    unordered_map<int,unordered_map<int,double>>mpp;
    double solve(int n,int k,int row,int col){
        if(row<0||col<0||row>=n||col>=n) return 0;
        if(k==0) {
            return 1;
        }
        if(mpp[k][n*row+col]) return mpp[k][n*row+col];
        return mpp[k][n*row+col]=(solve(n,k-1,row+1,col-2)+solve(n,k-1,row-1,col-2)+solve(n,k-1,row-2,col-1)+solve(n,k-1,row+2,col-1)+solve(n,k-1,row-2,col+1)+solve(n,k-1,row+2,col+1)+solve(n,k-1,row+1,col+2)+solve(n,k-1,row-1,col+2))/8.0;
    }
    double knightProbability(int n, int k, int row, int col) {
        double ans=solve(n,k,row,col);
        return ans;
    }
};