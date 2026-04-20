class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
         int n=intervals.size();
        //  int i=0;
        //  int newS=newInterval[0];
        //  int newE=newInterval[1];
        //  vector<vector<int>>ans;
        //  while(i<n){
        //     if(intervals[i][0]>=newS){
        //         break;
        //     }
        //     ans.push_back(intervals[i]);
        //     i++;
        //  }
        // if(!ans.empty()){
        //     if(ans.back()[1]<newS)
        //     ans.push_back({newS,newE});
        //     else
        //     ans.back()[1]=max(ans.back()[1],newE);
        // }
        // else{
        //     ans.push_back(newInterval);
        // }
        // for(int j=i;j<n;j++){
        //     if(ans.back()[1]<intervals[j][0])
        //     ans.push_back(intervals[j]);
        //     else
        //     ans.back()[1]=max(ans.back()[1],intervals[j][1]);
        // }
        // return ans;




        int i=0;
        vector<vector<int>>ans;
        while(i<n&&intervals[i][1]<newInterval[0]){
             ans.push_back(intervals[i]);
             i++;
        }
        while(i<n&&intervals[i][0]<=newInterval[1]){
            newInterval[0]=min(newInterval[0],intervals[i][0]);
            newInterval[1]=max(newInterval[1],intervals[i][1]);
            i++;  
        }
        ans.push_back(newInterval);
        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};