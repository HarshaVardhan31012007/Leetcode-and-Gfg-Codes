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



  int peopleAwareOfSecret(int n, int delay, int forget) {
        int day=1;
        int mod=1e9+7;
        deque<pair<int,int>>q;
        q.push_back({1,1});
        while(day<=n){
            while(!q.empty()&&day-q.front().first>=forget){
                q.pop_front();
            }
            int size=q.size();
            while(!q.empty()&&day-q.front().first>=delay&&size--){
                q.push_back(q.front());
                q.pop_front();
            }
            if(size==-1)
            size=q.size()-size-1;
            else
            size=q.size()-size;
            int count=0;
            for(int i=0;i<size;i++){
                q.push_front(q.back());
                count=(count+q.back().second)%mod;
                q.pop_back();
            }
            if(size>0)
            q.push_back({day,count});
            day++;
        }
        int ans=0;
        while(!q.empty()){
            ans=(ans+q.front().second)%mod;
            q.pop_front();
        }
        return ans;
    }
};