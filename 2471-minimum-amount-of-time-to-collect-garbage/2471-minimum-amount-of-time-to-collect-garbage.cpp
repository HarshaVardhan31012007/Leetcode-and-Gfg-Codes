class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        // int countP=0;int countG=0;int countM=0;
        // for(int i=0;i<garbage.size();i++){
        //     for(auto &each:garbage[i]){
        //         if(each=='P') countP++;
        //         else if(each=='G') countG++;
        //         else countM++;
        //      }
        // }
        // int ans=0;
        // for(int i=0;i<3;i++){
        //     for(int j=0;j<garbage.size();j++){
        //         for(auto &each:garbage[j]){
        //              if(each=='P'){
        //                if(i==0){
        //                countP--;
        //                ans++;
        //                }
        //              }
        //              else if(each=='G'){
        //                if(i==1){
        //                countG--;
        //                ans++;
        //              }
        //              }
        //              else{
        //                 if(i==2){
        //                 countM--;
        //                 ans++;
        //                 }
        //              }
        //         }
        //         if(i==0&&countP==0) break;
        //         if(i==1&&countG==0) break;
        //         if(i==2&&countM==0) break;
        //          ans+=travel[j];
        //     }
        // }
        // return ans;


        // int ans=0;
        // int lastP=0;
        // int lastG=0;
        // int lastM=0;
        // for(int i=0;i<garbage.size();i++){
        //     for(auto &each:garbage[i]){
        //         if(each=='P') lastP=i;
        //         else if(each=='G') lastG=i;
        //         else lastM=i;
        //         ans++;
        //     }
        // }
        // // vector<int>prefix(travel.size()+1,0);
        // // for(int i=1;i<travel.size()+1;i++){
        // //     prefix[i]=travel[i-1]+prefix[i-1];
        // // }
        // // ans+=prefix[lastP]+prefix[lastG]+prefix[lastM];


        // for(int i=0;i<lastP;i++)
        // ans+=travel[i];
        // for(int i=0;i<lastM;i++)
        // ans+=travel[i];
        // for(int i=0;i<lastG;i++)
        // ans+=travel[i];
        // return ans;



        // int ans=0;
        // int lastP=0;
        // int lastG=0;
        // int lastM=0;
        // for(int i=0;i<garbage.size();i++){
        //     for(auto &each:garbage[i]){
        //         if(each=='P') lastP=i;
        //         else if(each=='G') lastG=i;
        //         else lastM=i;
        //         ans++;
        //     }
        // }
        // // vector<int>prefix(travel.size()+1,0);
        // // for(int i=1;i<travel.size()+1;i++){
        // //     prefix[i]=travel[i-1]+prefix[i-1];
        // // }
        // // ans+=prefix[lastP]+prefix[lastG]+prefix[lastM];


        // for(int i=0;i<lastP;i++)
        // ans+=travel[i];
        // for(int i=0;i<lastM;i++)
        // ans+=travel[i];
        // for(int i=0;i<lastG;i++)
        // ans+=travel[i];
        // return ans;


        int ans=0;
        int lastP=0;
        int lastG=0;
        int lastM=0;
        for(int i=garbage.size()-1;i>=0;i--){
            if(lastP==0||lastG==0||lastM==0){
                for(auto &each:garbage[i]){
                    if(each=='P'&&lastP==0)
                    lastP=i;
                    if(each=='M'&&lastM==0)
                    lastM=i;
                    if(each=='G'&&lastG==0)
                    lastG=i;
                }
            }
            ans+=garbage[i].size();
        }
        for(int i=0;i<lastP;i++)
        ans+=travel[i];
        for(int i=0;i<lastM;i++)
        ans+=travel[i];
        for(int i=0;i<lastG;i++)
        ans+=travel[i];
        return ans;
    }
};