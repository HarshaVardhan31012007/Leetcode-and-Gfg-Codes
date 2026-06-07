/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    struct gridnode{
        int r;
        int c;
    };
    Node* solve(gridnode tl,gridnode tr,gridnode bl,gridnode br,vector<vector<int>>&prefix){
        int rows=tr.c-tl.c+1;
        int cols=bl.r-tl.r+1;
        int sum=prefix[br.r+1][br.c+1]-prefix[tr.r][tr.c+1]-prefix[bl.r+1][bl.c]+prefix[tl.r][tl.c];
        if(sum==rows*cols) return new Node(1,1);
        if(sum==0) return new Node(0,1);
        Node* root=new Node(1,0);
        root->topLeft=solve(tl,{tl.r,(tl.c+tr.c)/2},{(tl.r+bl.r)/2,tl.c},{(tl.r+br.r)/2,(tl.c+br.c)/2},prefix);
        root->topRight=solve({tl.r,(tl.c+tr.c)/2+1},tr,{(tl.r+br.r)/2,(tl.c+br.c)/2+1},{(tr.r+br.r)/2,tr.c},prefix);
        root->bottomLeft=solve({(tl.r+bl.r)/2+1,tl.c},{(tl.r+br.r)/2+1,(tl.c+br.c)/2},bl,{bl.r,(bl.c+br.c)/2},prefix);
        root->bottomRight=solve({(tl.r+br.r)/2+1,(tl.c+br.c)/2+1},{(tr.r+br.r)/2+1,tr.c},{bl.r,(bl.c+br.c)/2+1},br,prefix);
        return root;
    }
    Node* construct(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>prefix(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                prefix[i][j]=(prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]+grid[i-1][j-1]);
            }
        }
        gridnode tl={0,0};gridnode tr={0,n-1};
        gridnode bl={m-1,0};gridnode br={m-1,n-1};
        return solve(tl,tr,bl,br,prefix);
    }
};