class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
    //    sort(nums.begin(),nums.end());
    //    unordered_map<int,int>mpp;int ans=0;
    //    for(int i=0;i<nums.size();i++){
    //     int t=nums[i]-k;
    //     if((mpp.count(nums[i])==0||k==0)&&mpp.find(t)!=mpp.end()){
    //         if(k==0){
    //             if(mpp[t]==1)
    //             ans++;
    //         }
    //         else
    //         ans++;
    //     }
    //     mpp[nums[i]]++;
    //    } 
    //    return ans;


        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(abs(nums[j]-nums[i])==k){
                    if((i-1>=0&&nums[i-1]==nums[i])||(j-1>=0&&j!=i+1&&nums[j]==nums[j-1]))
                    continue;
                    else
                    ans++;
                }
            }
        }
        return ans;
    }
};