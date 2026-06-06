class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int lastP=0;
        int lastG=0;
        int lastM=0;
        int ans=0;
        for(int i=1;i<travel.size();i++)
        travel[i]+=travel[i-1];
        for(int i=0;i<garbage.size();i++){
            ans+=garbage[i].length();
            for(int j=0;j<garbage[i].length();j++){
                if(garbage[i][j]=='P'&&lastP!=i){
                    lastP=i;
                }
                else if(garbage[i][j]=='G'&&lastG!=i){
                    lastG=i;
                }
                else if(garbage[i][j]=='M'&&lastM!=i){
                    lastM=i;
                }
            }
        }
        if(lastP) ans+=travel[lastP-1];
        if(lastG) ans+=travel[lastG-1];
        if(lastM) ans+=travel[lastM-1];
        return ans;
    }
};