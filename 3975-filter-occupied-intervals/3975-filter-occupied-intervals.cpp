class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        sort(occupiedIntervals.begin(),occupiedIntervals.end());
        vector<vector<int>>ans;
        int n=occupiedIntervals.size();
        for(int i=0;i<n;i++){
             if(ans.empty()||ans.back()[1]+1<occupiedIntervals[i][0]){
                 ans.push_back(occupiedIntervals[i]);
             }
             else{
                 ans.back()[1]=max(ans.back()[1],occupiedIntervals[i][1]);
             }
        }
        int size=ans.size();
        vector<vector<int>>temp;
        int i=0;
        while(i<size&&ans[i][1]<freeStart){
            temp.push_back(ans[i]);
            i++;
        }
        if(i==size) return temp;
        int currS=ans[i][0];
        int currE=(freeStart-1);
        if(currS<=currE){
            temp.push_back({currS,currE});
        }
        while(i<size&&ans[i][0]<=freeEnd){
            currE=ans[i][1];
            i++;
        }
        currS=freeEnd+1;
        if(currS<=currE){
            temp.push_back({currS,currE});
        }
        while(i<size){
            temp.push_back(ans[i]);
            i++;
        }
        return temp;
    }
};