class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int countP=0;int countG=0;int countM=0;
        for(int i=0;i<garbage.size();i++){
            for(auto &each:garbage[i]){
                if(each=='P') countP++;
                else if(each=='G') countG++;
                else countM++;
             }
        }
        int ans=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<garbage.size();j++){
                for(auto &each:garbage[j]){
                     if(each=='P'){
                       if(i==0){
                       countP--;
                       ans++;
                       }
                     }
                     else if(each=='G'){
                       if(i==1){
                       countG--;
                       ans++;
                     }
                     }
                     else{
                        if(i==2){
                        countM--;
                        ans++;
                        }
                     }
                }
                if(i==0&&countP==0) break;
                if(i==1&&countG==0) break;
                if(i==2&&countM==0) break;
                 ans+=travel[j];
            }
        }
        return ans;
    }
};