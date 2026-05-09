// class Solution {
// public:
//     int minJumps(vector<int>& nums) {
//         int maxi=INT_MIN;
//         unordered_map<int,vector<int>>mpp;
//         for(int i=0;i<(int)nums.size();i++){
//             mpp[nums[i]].push_back(i);
//             maxi=max(maxi,nums[i]);
//         }
//         vector<int>isprime(maxi+1,1);
//         isprime[0]=isprime[1]=0;
//         for(int i=2;i*i<=maxi;i++){
//             for(int j=i*i;j<=maxi;j+=i){
//                 isprime[j]=0;
//             }
//         }
//         queue<int>q;
//         q.push(0);
//         vector<int>jumps((int)nums.size(),-1);
//         jumps[0]=0;
//         unordered_set<int>visited;
//         while(!q.empty()){
//            int i=q.front();
//            q.pop();
//            if(i==((int)nums.size()-1)) return jumps[i];
//            if(i>0){
//              if(jumps[i-1]==-1){
//                 q.push(i-1);
//                 jumps[i-1]=jumps[i]+1;
//              }
//            }
//            if(i+1<(int)nums.size()){
//              if(jumps[i+1]==-1){
//                 q.push(i+1);
//                 jumps[i+1]=jumps[i]+1;
//              }
//            }
//            if(!isprime[nums[i]]||visited.count(nums[i])) continue;
//            for(int k=nums[i];k<=maxi;k+=nums[i]){
//                if(visited.count(k)) continue;
//                for(auto &idx:mpp[k]){
//                    if(jumps[idx]==-1){
//                      q.push(idx);
//                      jumps[idx]=jumps[i]+1;
//                    }
//                }
//            }
//            visited.insert(nums[i]);
//         }
//         return -1;
//     }
// };



const int maxi=1000001;
vector<int>factors[maxi];
bool initilized=[](){
    for(int i=2;i<maxi;i++){
        if(factors[i].empty()){
            for(int j=i;j<maxi;j+=i){
                factors[j].push_back(i);
            }
        }
    }
    return true;
}();
class Solution {
public:
    int minJumps(vector<int>& nums) {
        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<(int)nums.size();i++){
                for(auto &p:factors[nums[i]]){
                    mpp[p].push_back(i);
                }
        }
        queue<int>q;
        q.push(0);
        vector<int>jumps((int)nums.size(),-1);
        jumps[0]=0;
        while(!q.empty()){
            auto i=q.front();
            q.pop();
            if(i==((int)nums.size()-1)) return jumps[i];
            if(i>0){
                if(jumps[i-1]==-1){
                    jumps[i-1]=jumps[i]+1;
                    q.push(i-1);
                }
            }
            if(i+1<(int)nums.size()){
                if(jumps[i+1]==-1){
                    jumps[i+1]=jumps[i]+1;
                    q.push(i+1);
                }
            }
            if(mpp.count(nums[i])){
                for(auto &idx:mpp[nums[i]]){
                    if(jumps[idx]==-1){
                        jumps[idx]=jumps[i]+1;
                        q.push(idx);
                    }
                }
                mpp[nums[i]].clear();
                mpp.erase(nums[i]);
            }
        }
        return -1;
    }
};




