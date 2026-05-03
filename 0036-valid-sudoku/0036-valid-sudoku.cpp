class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_set<int>>rowMap;
        unordered_map<int,unordered_set<int>>colMap;
        unordered_map<int,unordered_set<int>>boxMap;
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!isdigit(board[i][j])) continue;
                if(rowMap[i].count(board[i][j]-'0')) return false;
                if(colMap[j].count(board[i][j]-'0')) return false;
                if(boxMap[(i/3)*3+j/3].count(board[i][j]-'0')) return false;
                rowMap[i].insert(board[i][j]-'0');
                colMap[j].insert(board[i][j]-'0');
                boxMap[(i/3)*3+j/3].insert(board[i][j]-'0');
            }
        }
        return true;
    }
};