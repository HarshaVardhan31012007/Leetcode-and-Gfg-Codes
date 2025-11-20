class Solution {
  public:
    class var{
        public:
        int data;
        int row;
        int col;
    };
    class comp{
        public:
        bool operator()(var &a,var &b){
           return a.data>b.data;
        }
    };
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        priority_queue<var,vector<var>,comp>pq;
        for(int i=0;i<mat.size();i++){
            pq.push({mat[i][0],i,0});
        }
        vector<int>ans;
        while(!pq.empty()){
            var top=pq.top();
            pq.pop();
            ans.push_back(top.data);
            if(top.col+1<mat[top.row].size()){
                pq.push({mat[top.row][top.col+1],top.row,top.col+1});
            }
        }
        return ans;
    }
};