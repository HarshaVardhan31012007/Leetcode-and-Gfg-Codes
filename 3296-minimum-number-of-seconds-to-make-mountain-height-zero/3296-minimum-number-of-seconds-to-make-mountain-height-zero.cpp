class Solution {
public:
    // bool possible(int mountainHeight,vector<int>&workerTimes,long long mid){
    //     long long noOfWorkers=workerTimes.size();
    //     long long contributedHeight=0;
    //     for(int i=0;i<noOfWorkers;i++){
    //         int currWorkerTime=workerTimes[i];
    //         long long low=1;
    //         long long high=mountainHeight;
    //         long long c=0;
    //         while(low<=high){
    //             long long mid1=low+(high-low)/2;
    //             if(1LL*((mid1*(mid1+1))/2)*currWorkerTime<=mid){
    //                 c=mid1;
    //                 low=mid1+1;
    //             }
    //             else{
    //                 high=mid1-1;
    //             }
    //         }
    //         contributedHeight+=c;
    //     }
    //     return contributedHeight>=mountainHeight;
    // }
    // long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
    //     long long noOfWorkers=workerTimes.size();
    //     long long s=1;
    //     long long maxWorkerTime=*max_element(workerTimes.begin(),workerTimes.end());
    //     long long e=(1LL*(maxWorkerTime)*mountainHeight*(mountainHeight+1))/2;
    //     long long ans=-1;
    //     while(s<=e){
    //         long long mid=s+(e-s)/2;
    //         if(possible(mountainHeight,workerTimes,mid)){
    //             ans=mid;
    //             e=mid-1;
    //         }
    //         else{
    //             s=mid+1;
    //         }
    //     }
    //     return ans;
    // }



    bool possible(int mountainHeight,vector<int>&workerTimes,long long mid){
        long long noOfWorkers=workerTimes.size();
        long long contributedHeight=0;
        for(int i=0;i<noOfWorkers;i++){
            int currWorkerTime=workerTimes[i];
            long long ans=(-1LL+sqrt(1LL+((8LL*mid)/currWorkerTime)))/2LL;
            if(ans<0) ans=0;
            contributedHeight+=ans;
        }
        return contributedHeight>=mountainHeight;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long noOfWorkers=workerTimes.size();
        long long s=1;
        long long maxWorkerTime=*max_element(workerTimes.begin(),workerTimes.end());
        long long e=(1LL*(maxWorkerTime)*mountainHeight*(mountainHeight+1))/2;
        long long ans=-1;
        while(s<=e){
            long long mid=s+(e-s)/2;
            if(possible(mountainHeight,workerTimes,mid)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};