class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        // int mini=INT_MAX;
        // int n=landStartTime.size();
        // for(int i=0;i<n;i++){
        //     mini=min(mini,landStartTime[i]+landDuration[i]);
        // }
        // int ans=INT_MAX;
        // n=waterStartTime.size();
        // for(int i=0;i<n;i++){
        //     if(waterStartTime[i]<=mini){
        //         ans=min(ans,mini+waterDuration[i]);
        //     }
        //     else{
        //        ans=min(ans,waterStartTime[i]+waterDuration[i]);
        //     }
        // }
        // mini=INT_MAX;
        // n=waterStartTime.size();
        // for(int i=0;i<n;i++){
        //     mini=min(mini,waterStartTime[i]+waterDuration[i]);
        // }
        // n=landStartTime.size();
        // for(int i=0;i<n;i++){
        //     if(landStartTime[i]<=mini){
        //         ans=min(ans,mini+landDuration[i]);
        //     }
        //     else{
        //        ans=min(ans,landStartTime[i]+landDuration[i]);
        //     }
        // }
        // return ans;



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