class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
         sort(towers.begin(),towers.end());
         int ans=INT_MIN;
         int ansx=-1;int ansy=-1;
         for(int i=0;i<towers.size();i++){
            int x=towers[i][0];int y=towers[i][1];
            int dist=abs(x-center[0])+abs(y-center[1]);
            if(dist<=radius&&towers[i][2]>ans){
                ans=towers[i][2];
                ansx=x;ansy=y;
            }
         }
         return {ansx,ansy};
    }
};