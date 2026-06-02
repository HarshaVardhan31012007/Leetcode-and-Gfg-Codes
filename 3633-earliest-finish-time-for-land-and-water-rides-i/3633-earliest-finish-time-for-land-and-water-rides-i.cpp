class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int mini=INT_MAX;
        int n=landStartTime.size();
        for(int i=0;i<n;i++){
            mini=min(mini,landStartTime[i]+landDuration[i]);
        }
        int ans=INT_MAX;
        n=waterStartTime.size();
        for(int i=0;i<n;i++){
            if(waterStartTime[i]<=mini){
                ans=min(ans,mini+waterDuration[i]);
            }
            else{
               ans=min(ans,waterStartTime[i]+waterDuration[i]);
            }
        }
        mini=INT_MAX;
        n=waterStartTime.size();
        for(int i=0;i<n;i++){
            mini=min(mini,waterStartTime[i]+waterDuration[i]);
        }
        n=landStartTime.size();
        for(int i=0;i<n;i++){
            if(landStartTime[i]<=mini){
                ans=min(ans,mini+landDuration[i]);
            }
            else{
               ans=min(ans,landStartTime[i]+landDuration[i]);
            }
        }
        return ans;
    }
};