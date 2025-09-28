class Solution {
public:
    // int peopleAwareOfSecret(int n, int delay, int forget) {
    //     int day=1;
    //     deque<int>q;
    //     q.push_back(1);
    //     while(day<=n){
    //         while(!q.empty()&&day-q.front()>=forget){
    //             q.pop_front();
    //         }
    //         int count=0;
    //         int size=q.size();
    //         while(!q.empty()&&day-q.front()>=delay&&size--){
    //             count++;
    //             q.push_back(q.front());
    //             q.pop_front();
    //         }
    //         for(int i=0;i<count;i++){
    //             q.push_front(q.back());
    //             q.pop_back();
    //         }
    //         while(count--){
    //             q.push_back(day);
    //         }
    //         day++;
    //     }
    //     int mod=1e9+7;
    //     return q.size()%mod;
    // }



//   int peopleAwareOfSecret(int n, int delay, int forget) {
//         int day=1;
//         int mod=1e9+7;
//         deque<pair<int,int>>q;
//         q.push_back({1,1});
//         while(day<=n){
//             while(!q.empty()&&day-q.front().first>=forget){
//                 q.pop_front();
//             }
//             int size=q.size();
//             while(!q.empty()&&day-q.front().first>=delay&&size--){
//                 q.push_back(q.front());
//                 q.pop_front();
//             }
//             if(size==-1)
//             size=q.size()-size-1;
//             else
//             size=q.size()-size;
//             int count=0;
//             for(int i=0;i<size;i++){
//                 q.push_front(q.back());
//                 count=(count+q.back().second)%mod;
//                 q.pop_back();
//             }
//             if(size>0)
//             q.push_back({day,count});
//             day++;
//         }
//         int ans=0;
//         while(!q.empty()){
//             ans=(ans+q.front().second)%mod;
//             q.pop_front();
//         }
//         return ans;
//     }


    int peopleAwareOfSecret(int n, int delay, int forget) {
            int day=1;
            int mod=1e9+7;
            deque<pair<int,int>>dq;
            deque<pair<int,int>>dq1;
            dq.push_back({1,1});
            int count=0;
            int count1=1;
            while(day<=n){
                if(!dq1.empty()&&day-dq1.front().first==forget){
                    count=(count-dq1.front().second+mod)%mod;
                    dq1.pop_front();
                }
                if(!dq.empty()&&day-dq.front().first==delay){
                   dq1.push_back(dq.front());
                   count=(count+dq.front().second)%mod;
                   count1=(count1-dq.front().second+mod)%mod;
                   dq.pop_front();
                }
                if(!dq1.empty()){
                    dq.push_back({day,count});
                    count1=(count1+count)%mod;
                }
                day++;
            }
            return (count+count1)%mod;
        }
};