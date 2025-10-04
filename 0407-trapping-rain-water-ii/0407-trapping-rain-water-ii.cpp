class Solution {
public:
   //  typedef pair<int,pair<int,int>>PP;
     int trapRainWater(vector<vector<int>>& heightMap) {
         typedef pair<int,pair<int,int>>PP;
    //     vector<vector<int>>left(heightMap);
    //     vector<vector<int>>right(heightMap);
    //     vector<vector<int>>down(heightMap);
    //      vector<vector<int>>up(heightMap);
    //      for(int i=0;i<heightMap.size();i++){
    //             left[i][0]=heightMap[i][0];
    //         for(int j=1;j<heightMap[i].size();j++){
    //             left[i][j]=max(heightMap[i][j],left[i][j-1]);
    //         }
    //      }
    //      for(int i=0;i<heightMap.size();i++){
    //             right[i][heightMap[i].size()-1]=heightMap[i][heightMap[i].size()-1];
    //         for(int j=heightMap[i].size()-2;j>=0;j--){
    //             right[i][j]=max(heightMap[i][j],right[i][j+1]);
    //         }
    //      }
    //     for(int j=0;j<heightMap[0].size();j++){
    //         up[0][j]=heightMap[0][j];
    //         for(int i=1;i<heightMap.size();i++){
    //            up[i][j]=max(heightMap[i][j],up[i-1][j]);
    //         }
    //     }
    //     for(int j=0;j<heightMap[0].size();j++){
    //         down[heightMap.size()-1][j]=heightMap[heightMap.size()-1][j];
    //         for(int i=heightMap.size()-2;i>=0;i--){
    //             down[i][j]=max(heightMap[i][j],down[i+1][j]);
    //         }
    //     }
    //     int watertrapped=0;
    //     for(int i=0;i<heightMap.size();i++){
    //         for(int j=0;j<heightMap[0].size();j++){
    //             watertrapped+=min({left[i][j],right[i][j],up[i][j],down[i][j]})-heightMap[i][j];
    //             cout<<watertrapped<<" ";
    //         }
    //         cout<<endl;
    //     }
    //     return watertrapped;



        // priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>pq;//no need to define again in greater<>
        priority_queue<PP,vector<PP>,greater<>>pq;//no need to define again in greater<>
        vector<vector<int>>visited(heightMap.size(),vector<int>(heightMap[0].size(),0));
        for(int row=0;row<heightMap.size();row++){
            for(int col:{0,(int)(heightMap[0].size()-1)}){
                pq.push({heightMap[row][col],{row,col}});
                visited[row][col]=true;
            }
        }

        for(int col=1;col<heightMap[0].size()-1;col++){
            for(int row:{0,(int)(heightMap.size()-1)}){
               pq.push({heightMap[row][col],{row,col}});
               visited[row][col]=true;
            }
        }
        int watertrapped=0;
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            int height=top.first;
            int x=top.second.first;int y=top.second.second;
            int dx[]={1,-1,0,0};
            int dy[]={0,0,1,-1};
            for(int i=0;i<4;i++){
                int newx=x+dx[i];
                int newy=y+dy[i];
                if(newx>=0&&newx<heightMap.size()&&newy>=0&&newy<=heightMap[0].size()-1&&!visited[newx][newy]){
                    watertrapped+=max(height-heightMap[newx][newy],0);
                    pq.push({max(height,heightMap[newx][newy]),{newx,newy}});
                    visited[newx][newy]=true;
                }
            }
        }
        return watertrapped;
    }
};