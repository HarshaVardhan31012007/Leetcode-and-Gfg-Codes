// class Solution {
// public:
//     int find(vector<vector<int>>&events,int e){
//         int ans=events.size();
//         int i=0;
//         int j=events.size()-1;
//         while(i<=j){
//             int mid=i+(j-i)/2;
//             if(events[mid][0]>e){
//                 ans=mid;
//                 j=mid-1;
//             }
//             else{
//                 i=mid+1;
//             }
//         }
//         return ans;
//     }
//     int maxTwoEvents(vector<vector<int>>& events) {
//         sort(events.begin(),events.end(),[](vector<int>&a,vector<int>&b){
//                return a[0]<b[0];
//         });
//         vector<int>ans(events.size(),0);
//         int res=0;
//         for(int i=0;i<events.size();i++){
//            int idx=find(events,events[i][1]);
//            if(idx!=events.size()){
//               ans[idx]=max(ans[idx],events[i][2]);
//            }
//            if(i>0){
//               ans[i]=max(ans[i],ans[i-1]);
//               ans[i-1]+=events[i-1][2];
//               res=max(res,ans[i-1]);
//            }
//         }  
//         ans[ans.size()-1]+=events[ans.size()-1][2];
//         res=max(res,ans[ans.size()-1]);
//         return res;
//     }
// };



// class Solution {
// public:
//     int find(vector<vector<int>>&events,int e){
//         int ans=events.size();
//         int i=0;
//         int j=events.size()-1;
//         while(i<=j){
//             int mid=i+(j-i)/2;
//             if(events[mid][0]>e){
//                 ans=mid;
//                 j=mid-1;
//             }
//             else{
//                 i=mid+1;
//             }
//         }
//         return ans;
//     }
//     int maxTwoEvents(vector<vector<int>>& events) {
//         sort(events.begin(),events.end(),[](vector<int>&a,vector<int>&b){
//                return a[0]<b[0];
//         });
//         vector<int>ans(events.size(),0);
//         int res=0;
//         for(int i=0;i<events.size();i++){
//            int idx=find(events,events[i][1]);
//            if(idx!=events.size()){
//               ans[idx]=max(ans[idx],events[i][2]);
//            }
//            if(i>0)
//               ans[i]=max(ans[i],ans[i-1]);
//             res=max(res,ans[i]+events[i][2]);
//         } 
//         return res;
//     }


class Solution {
public:
    int find(vector<vector<int>>&events,int e){
        int ans=events.size();
        int i=0;
        int j=events.size()-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(events[mid][0]>e){
                ans=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return ans;
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end(),[](vector<int>&a,vector<int>&b){
               return a[0]<b[0];
        });
        vector<int>suffix(events.size(),0);
        suffix[events.size()-1]=events[events.size()-1][2];
        for(int i=events.size()-2;i>=0;i--){
           suffix[i]=max(suffix[i+1],events[i][2]);
        }
        int res=0;
        for(int i=0;i<events.size();i++){
           int idx=find(events,events[i][1]);
           if(idx!=events.size()){
              res=max(res,events[i][2]+suffix[idx]);
           }
           else
           res=max(res,events[i][2]);
        } 
        return res;
    }
};