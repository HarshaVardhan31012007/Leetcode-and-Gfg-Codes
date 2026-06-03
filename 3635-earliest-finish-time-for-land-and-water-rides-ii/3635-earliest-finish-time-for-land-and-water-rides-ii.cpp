class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
          int n1=landStartTime.size();int n2=waterStartTime.size();
        int mini1=INT_MAX;int mini2=INT_MAX;
        for(int i=0;i<max(n1,n2);i++){
            if(i<n1)
            mini1=min(mini1,landStartTime[i]+landDuration[i]);
            if(i<n2)
            mini2=min(mini2,waterStartTime[i]+waterDuration[i]);
        }
        int ans=INT_MAX;
        for(int i=0;i<max(n1,n2);i++){
            if(i<n2){
                if(waterStartTime[i]<=mini1){
                    ans=min(ans,mini1+waterDuration[i]);
                }
                else{
                    ans=min(ans,waterStartTime[i]+waterDuration[i]);
                }
            }
            if(i<n1){
                if(landStartTime[i]<=mini2){
                    ans=min(ans,mini2+landDuration[i]);
                }
                else{
                    ans=min(ans,landStartTime[i]+landDuration[i]);
                }
            }
        }
        return ans;
    }
};