class Solution {
  public:
     static bool comp(vector<int>&a,vector<int>&b){
         return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int count=1;
        int prevS=intervals[0][0];
        int prevE=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>prevE){
              count++;
              prevS=intervals[i][0];
              prevE=intervals[i][1];
            }
        }
        return count;
    }
    int activitySelection(vector<int> &start, vector<int> &finish) {
        vector<vector<int>>ans;
        for(int i=0;i<start.size();i++){
            ans.push_back({start[i],finish[i]});
        }
        return eraseOverlapIntervals(ans);
    }
};