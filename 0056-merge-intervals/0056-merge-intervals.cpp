class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        if(a[0]!=b[0])
        return a[0]<b[0];
        return a[1]<b[1];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end(),comp);
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][1]<=ans.back()[1]){
                continue;
            }
            if(intervals[i][0]>ans.back()[1]){
                ans.push_back(intervals[i]);
            }
            else{
                ans.back()[1]=intervals[i][1];
            }
        }
        return ans;
    }
};