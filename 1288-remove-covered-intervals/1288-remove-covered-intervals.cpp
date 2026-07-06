class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[&](vector<int>&a,vector<int>&b){
            if(a[0]!=b[0]) return a[0]<b[0];
            return a[1]>b[1];
        });
        int n=intervals.size();
        int prev=0;
        int ans=0;
        for(int i=1;i<n;i++){
            if(intervals[prev][1]>=intervals[i][1]){
                ans++;
            }
            else
            prev=i;
        }
        return n-ans;
    }
};