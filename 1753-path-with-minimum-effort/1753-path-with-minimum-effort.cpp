class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // int m=heights.size();
        // int n=heights[0].size();
        // set<pair<int,pair<int,int>>>st;
        // map<pair<int,int>,pair<int,int>>parent;
        // vector<vector<int>>effort(m,vector<int>(n,INT_MAX));
        // st.insert({0,{0,0}});
        // parent[{0,0}]={-1,-1};
        // effort[0][0]=0;
        // while(!st.empty()){
        //     auto front=*st.begin();
        //     st.erase(st.begin());
        //     vector<pair<int,int>>dir={{0,-1},{0,1},{1,0},{-1,0}};
        //     for(auto &d:dir){
        //         int oldX=front.second.first;
        //         int oldY=front.second.second;
        //         int newX=front.second.first+d.first;
        //         int newY=front.second.second+d.second;
        //         if(newX>=0 && newX<m && newY>=0 && newY<n && parent[{oldX,oldY}]!= make_pair(newX,newY) && (abs(heights[newX][newY]-heights[oldX][oldY])<effort[newX][newY])){
        //             if(st.find({effort[newX][newY],{newX,newY}})!=st.end()){
        //                 st.erase({effort[newX][newY],{newX,newY}});
        //             }
        //             effort[newX][newY]=abs(heights[newX][newY]-heights[oldX][oldY]);
        //             parent[{newX,newY}]={oldX,oldY};
        //             st.insert({effort[newX][newY],{newX,newY}});
        //         }
        //     }
        // }
        //     pair<int,int>node={m-1,n-1};
        //     int maxi=INT_MIN;
        //     while(node!=make_pair(-1,-1)){
        //       maxi=max(maxi,effort[node.first][node.second]);
        //       node=parent[node];
        //     }
        //     return maxi;







        int m=heights.size();
        int n=heights[0].size();
        set<pair<int,pair<int,int>>>st;
        vector<vector<int>>effort(m,vector<int>(n,INT_MAX));
        st.insert({0,{0,0}});
        effort[0][0]=0;
        while(!st.empty()){
            auto front=*st.begin();
            st.erase(st.begin());
            vector<pair<int,int>>dir={{0,-1},{0,1},{1,0},{-1,0}};
            for(auto &d:dir){
                int oldX=front.second.first;
                int oldY=front.second.second;
                int newX=front.second.first+d.first;
                int newY=front.second.second+d.second;
                if(newX>=0 && newX<m && newY>=0 && newY<n ){
                    int maxdiff=max(effort[oldX][oldY],abs(heights[newX][newY]-heights[oldX][oldY]));
                    if(maxdiff<effort[newX][newY]){
                    if(st.find({effort[newX][newY],{newX,newY}})!=st.end()){
                        st.erase({effort[newX][newY],{newX,newY}});
                    }
                    effort[newX][newY]=maxdiff;
                    st.insert({effort[newX][newY],{newX,newY}});
                    }
                }
            }
        }
          return effort[m-1][n-1];
    }
};