class Solution {
public:
    // int mostBooked(int n, vector<vector<int>>& meetings) {
    //     vector<long long>ans(n,0);
    //     sort(meetings.begin(),meetings.end());
    //     vector<long long>end(n,0);
    //     for(int i=0;i<meetings.size();i++){
    //         long long int s=meetings[i][0];long long int e=meetings[i][1];
    //         bool flag=1;long long int mini=LLONG_MAX;long long int idx=-1;
    //         for(int j=0;j<n;j++){
    //             if(end[j]<=s){
    //                 end[j]=e;
    //                 ans[j]++;
    //                 flag=0;
    //                 break;
    //             }
    //             if(end[j]<mini){
    //                 mini=end[j];
    //                 idx=j;
    //             }
    //         }
    //         if(flag){
    //             ans[idx]++;
    //             end[idx]=end[idx]+1LL*(e-s);
    //         }
    //     }
    //     int num=-1;long long int maxi=INT_MIN;
    //     for(int i=0;i<n;i++){
    //         if(ans[i]>maxi){
    //             maxi=ans[i];
    //             num=i;
    //         }
    //     }
    //     return num;
    // }




     int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<long long>ans(n,0);
        sort(meetings.begin(),meetings.end());
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>>pq;
        priority_queue<int,vector<int>,greater<>>pq1;
        for(int i=0;i<n;i++)
        pq1.push(i);
        for(int i=0;i<meetings.size();i++){
            long long int s=meetings[i][0];long long int e=meetings[i][1];
            while(!pq.empty()&&pq.top().first<=s){
                pq1.push(pq.top().second);
                pq.pop();
            }
            if(!pq1.empty()){
                int room=pq1.top();
                pq1.pop();
                ans[room]++;
                pq.push({e,room});
            }
            else{
                auto top=pq.top();
                pq.pop();
                top.first+=e-s;
                ans[top.second]++;
                pq.push(top);
            }
        }
        int num=-1;long long int maxi=LLONG_MIN;
        for(int i=0;i<n;i++){
            if(ans[i]>maxi){
                maxi=ans[i];
                num=i;
            }
        }
        return num;
    }
};