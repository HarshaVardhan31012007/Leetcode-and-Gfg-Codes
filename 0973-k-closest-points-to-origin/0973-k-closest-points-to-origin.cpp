class Solution {
public:
    class var{
        public:
        double dist;
        int x;
        int y;
    };
    class comp{
        public:
        bool operator()(var &a,var &b){
            return a.dist<b.dist;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<var,vector<var>,comp>pq;
        for(int i=0;i<k;i++){
            pq.push({hypot(points[i][0],points[i][1]),points[i][0],points[i][1]});
        }
        for(int i=k;i<points.size();i++){
             pq.push({hypot(points[i][0],points[i][1]),points[i][0],points[i][1]});
             pq.pop();
        }
        vector<vector<int>>ans;
        while(!pq.empty()){
            ans.push_back({pq.top().x,pq.top().y});
            pq.pop();
        }
        return ans;
    }
};