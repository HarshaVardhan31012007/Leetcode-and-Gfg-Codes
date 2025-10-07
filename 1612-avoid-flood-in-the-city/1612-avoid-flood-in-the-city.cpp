class Solution {
public:
    //in both approaches 
    //set is better than vector 
    //becuse erase O(logn) in set and O(n) in vector
    // vector<int> avoidFlood(vector<int>& rains) {
    //     unordered_map<int,int>mpp;
    //     set<int>zeros;
    //     vector<int>ans(rains.size(),-1);
    //     for(int i=0;i<rains.size();i++){
    //         if(rains[i]==0)
    //         zeros.insert(i);
    //         else{
    //             if(mpp.find(rains[i])!=mpp.end()){
    //                 if(zeros.empty()){
    //                     return {};
    //                 }
    //                 else{
    //                     auto it=zeros.upper_bound(mpp[rains[i]]);
    //                     if(it==zeros.end())
    //    return {};
    //                 ans[*it]=rains[i];
    //                zeros.erase(it);
    //                     mpp[rains[i]]=i;
    //                 }
    //             }
    //             else{
    //                 mpp[rains[i]]=i;
    //             }
    //         }
    //     }
    //     for(auto &each:zeros){
    //         ans[each]=2;//any number you can write
    //     }
    //     return ans;
    // }


    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int,int>mpp;
        vector<int>zeros;
        vector<int>ans(rains.size(),-1);
        for(int i=0;i<rains.size();i++){
            if(rains[i]==0)
            zeros.push_back(i);
            else{
                if(mpp.find(rains[i])!=mpp.end()){
                    if(zeros.empty()){
                        return {};
                    }
                    else{
                        auto it=upper_bound(zeros.begin(),zeros.end(),mpp[rains[i]]);
                        if(it==zeros.end())
       return {};
                    ans[*it]=rains[i];
                   zeros.erase(it);
                        mpp[rains[i]]=i;
                    }
                }
                else{
                    mpp[rains[i]]=i;
                }
            }
        }
        for(auto &each:zeros){
            ans[each]=1;
        }
        return ans;
    }
};