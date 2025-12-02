class Solution {
public:
    // const long long mod=1e9+7;
    // long long countTrapezoids(vector<vector<long long>>& polong longs) {
    //     unordered_map<long long,long long>mpp;
    //     for(auto &polong long:polong longs){
    //         mpp[polong long[1]]++;
    //     }
    //     long long sum=0;
    //     for(auto it=mpp.begin();it!=mpp.end();it++){
    //        if(it->second>=2)
    //        sum=(sum%mod+(((it->second)*(it->second-1))/2)%mod)%mod;
    //     }
    //     long long ans=0;
    //     for(auto it=mpp.begin();it!=mpp.end();it++){
    //           long long temp=(sum-(((it->second)*(it->second-1))/2)%mod+mod)%mod;
    //           ans=(ans+(temp*(((it->second)*(it->second-1))/2)%mod)%mod)%mod;
    //     }
    //     return ans/2;
    // }



    const long long mod=1e9+7;
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<long long,long long>mpp;
        for(auto &point:points){
            mpp[point[1]]++;
        }
        long long sum=0;
        long long ans=0;
        for(auto it=mpp.begin();it!=mpp.end();it++){
           if(it->second>=2){
               ans=(ans+(sum%mod*(((it->second)*(it->second-1))/2)%mod)%mod)%mod;
               sum=(sum%mod+(((it->second)*(it->second-1))/2)%mod)%mod;
           }
        }
        return (int)ans;
    }
};