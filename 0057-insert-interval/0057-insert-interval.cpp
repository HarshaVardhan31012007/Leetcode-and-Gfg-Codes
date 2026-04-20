class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
         int n=intervals.size();
         int i=0;
         int newS=newInterval[0];
         int newE=newInterval[1];
         vector<vector<int>>ans;
         while(i<n){
            if(intervals[i][0]>=newS){
                break;
            }
            ans.push_back(intervals[i]);
            i++;
         }
        if(!ans.empty()){
            if(ans.back()[1]<newS)
            ans.push_back({newS,newE});
            else
            ans.back()[1]=max(ans.back()[1],newE);
        }
        else{
            ans.push_back(newInterval);
        }
        for(int j=i;j<n;j++){
            if(ans.back()[1]<intervals[j][0])
            ans.push_back(intervals[j]);
            else
            ans.back()[1]=max(ans.back()[1],intervals[j][1]);
        }
        return ans;
    }
};