class Solution {
public:
    // int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
    //     unordered_map<int,set<int>>horizontal;
    //     unordered_map<int,set<int>>vertical;
    //     for(auto &building:buildings){
    //          horizontal[building[0]].insert(building[1]);
    //          vertical[building[1]].insert(building[0]);
    //     }
    //     int ans=0;
    //     for(auto &building:buildings){
    //         bool one=false;bool two=false;
    //         auto st=horizontal[building[0]];
    //         if(st.size()>=3){
    //             if((*st.begin())==building[1]) continue;
    //             auto it=st.end();
    //             it--;
    //             if((*it)==building[1]) continue;
    //             one=true;
    //         }
    //         st=vertical[building[1]];
    //         if(st.size()>=3){
    //             if((*st.begin())==building[0]) continue;
    //             auto it=st.end();
    //             it--;
    //             if((*it)==building[0]) continue;
    //             two=true;
    //         }
    //         if(one&&two)
    //         ans++;
    //     }
    //     return ans;
    // }





    // int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
    //     unordered_map<int,vector<int>>horizontal;
    //     unordered_map<int,vector<int>>vertical;
    //     for(auto &building:buildings){
    //          horizontal[building[0]].push_back(building[1]);
    //          vertical[building[1]].push_back(building[0]);
    //     }
    //     for(auto &each:horizontal){
    //         sort(each.second.begin(),each.second.end());
    //     }
    //     for(auto &each:vertical){
    //         sort(each.second.begin(),each.second.end());
    //     }
    //     int ans=0;
    //     for(auto &building:buildings){
    //         int x=building[0];int y=building[1];
    //         vector<int>h=horizontal[x];
    //         vector<int>v=vertical[y];
    //         if(h.size()>=3&&v.size()>=3&&h[0]!=y&&h[h.size()-1]!=y&&v[0]!=x&&v[v.size()-1]!=x)
    //         ans++;
    //     }
    //     return ans;
    // }




    //  int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
    //     vector<vector<int>>horizontal(n);
    //     vector<vector<int>>vertical(n);
    //     for(auto &building:buildings){
    //          horizontal[building[0]-1].push_back(building[1]-1);
    //          vertical[building[1]-1].push_back(building[0]-1);
    //     }
    //     for(auto &each:horizontal){
    //         sort(each.begin(),each.end());
    //     }
    //     for(auto &each:vertical){
    //         sort(each.begin(),each.end());
    //     }
    //     int ans=0;
    //     for(auto &building:buildings){
    //         int x=building[0];int y=building[1];
    //         vector<int>h=horizontal[x-1];
    //         vector<int>v=vertical[y-1];
    //         if(h.size()>=3&&v.size()>=3&&h[0]!=y-1&&h[h.size()-1]!=y-1&&v[0]!=x-1&&v[v.size()-1]!=x-1)
    //         ans++;
    //     }
    //     return ans;
    // }




     int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<vector<int>>horizontal(n,{INT_MAX,INT_MIN});
        vector<vector<int>>vertical(n,{INT_MAX,INT_MIN});
        for(auto &building:buildings){
            int x=building[0];int y=building[1];
            x--;y--;
            horizontal[x][0]=min(horizontal[x][0],y);
            vertical[y][0]=min(vertical[y][0],x);
            horizontal[x][1]=max(horizontal[x][1],y);
            vertical[y][1]=max(vertical[y][1],x);
        }
        int ans=0;
        for(auto &building:buildings){
            int x=building[0];int y=building[1];
            x--;y--;
            vector<int>h=horizontal[x];
            vector<int>v=vertical[y];
            if(h[0]!=y&&h[1]!=y&&v[0]!=x&&v[1]!=x)
            ans++;
        }
        return ans;
    }
};