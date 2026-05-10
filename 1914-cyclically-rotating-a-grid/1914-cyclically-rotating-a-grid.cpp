class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int dx=0;int dy=0;
        while(m>=2&&n>=2){
            vector<int>elements;
            int r=0;int c=0;
            while(c<n){
                elements.push_back(grid[r+dx][c+dy]);
                c++;
            }
            r=1;c=(n-1);
            while(r<m){
                elements.push_back(grid[r+dx][c+dy]);
                r++;
            }
            r=(m-1);c=(n-2);
            while(c>=0){
                elements.push_back(grid[r+dx][c+dy]);
                c--;
            }
            r=(m-2);c=0;
            while(r>=1){
                elements.push_back(grid[r+dx][c+dy]);
                r--;
            }
            int index=k%elements.size();
            r=0;c=0;
            while(c<n){
                grid[r+dx][c+dy]=elements[index];
                index++;
                if(index==elements.size())
                index=0;
                c++;
            }
            r=1;c=(n-1);
            while(r<m){
                grid[r+dx][c+dy]=elements[index];
                index++;
                if(index==elements.size())
                index=0;
                r++;
            }
            r=(m-1);c=(n-2);
            while(c>=0){
                grid[r+dx][c+dy]=elements[index];
                index++;
                if(index==elements.size())
                index=0;
                c--;
            }
            r=(m-2);c=0;
            while(r>=1){
                grid[r+dx][c+dy]=elements[index];
                index++;
                if(index==elements.size())
                index=0;
                r--;
            }
            dx++;dy++;
            m-=2;n-=2;
        }
        return grid;
    }
};