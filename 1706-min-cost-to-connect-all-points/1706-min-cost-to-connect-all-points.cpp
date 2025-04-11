class Solution {
public:
    int findmin(vector<int>&key,vector<int>&mst){
          int mini=INT_MAX;
          int index=-1;
          for(int i=0;i<key.size();i++){
             if(!mst[i]&&key[i]<mini){
                mini=key[i];
                index=i;
             }
          }
          return index;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<int>mst(n,false);
        vector<int>parent(n,-1);
        vector<int>key(n,INT_MAX);
        key[0]=0;
        while(true){
            int index=findmin(key,mst);
            if(index==-1) break;
            mst[index]=true;
            for(int j=0;j<points.size();j++){
                if(j!=index){
                    int w=abs(points[index][0]-points[j][0])+abs(points[index][1]-points[j][1]);
                    if(!mst[j]&&w<key[j]){
                        key[j]=w;
                        parent[j]=index;
                    }
                }
            }
        }
        int ans=0;
        for(int p=0;p<parent.size();p++){
            if(parent[p]!=-1){
                ans+=key[p];
            }
        }
        return ans;
    }
};