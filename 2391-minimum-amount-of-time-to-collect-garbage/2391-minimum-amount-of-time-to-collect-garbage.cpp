class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int lastP=-1;
        int lastG=-1;
        int lastM=-1;
        int ans=0;
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
        for(int i=1;i<garbage.size();i++){
            if(lastP>=i) ans+=travel[i-1];
            if(lastM>=i) ans+=travel[i-1];
            if(lastG>=i) ans+=travel[i-1];
        }
        return ans;
    }
};