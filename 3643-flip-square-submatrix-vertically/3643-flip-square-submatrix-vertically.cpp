class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {

        int p=0;
        int q=k-1;
        while(p<q){
            for(int j=0;j<k;j++){
                swap(grid[x+p][y+j],grid[x+q][y+j]);
            }
            p++;q--;
        }
        return grid;
    }
};