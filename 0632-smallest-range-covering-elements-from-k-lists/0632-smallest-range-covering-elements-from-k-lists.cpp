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
     vector<int> smallestRange(vector<vector<int>>& mat) {
        priority_queue<var,vector<var>,comp>pq;
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int i=0;i<mat.size();i++){
            maxi=max(maxi,mat[i][0]);
            mini=min(mini,mat[i][0]);
            pq.push({mat[i][0],i,0});
        }
        int amini=mini;
        int amaxi=maxi;
        while(!pq.empty()){
            var top=pq.top();
            pq.pop();
            mini=top.data;
            if(maxi-mini<amaxi-amini){
                amaxi=maxi;
                amini=mini;
            }
            if(top.col+1<mat[top.row].size()){
                maxi=max(maxi,mat[top.row][top.col+1]);
                pq.push({mat[top.row][top.col+1],top.row,top.col+1});
            }
            else
            break;
        }
        return {amini,amaxi};
    }
};