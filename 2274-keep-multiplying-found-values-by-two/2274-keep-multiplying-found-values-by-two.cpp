class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        // sort(nums.begin(),nums.end());
        // int s=0;
        // int e=nums.size()-1;
        // while(binary_search(begin(nums)+s,nums.begin()+e+1,original)){
        //     original=original*2;
        // }
        // return original;


        // sort(nums.begin(),nums.end());
        // int s=0;
        // int e=nums.size()-1;
        // auto it=lower_bound(nums.begin()+s,nums.end(),original);
        // while(it!=nums.end()){
        //     if(*it!=original) break;
        //     s=(it-nums.begin())+1;
        //     original=original*2;
        //     it=lower_bound(nums.begin()+s,nums.end(),original);
        // }
        // return original;



        unordered_map<int,bool>mpp;
        for(auto &num:nums){
            mpp[num]=1;
        }
        while(mpp.count(original)==1){
            original=2*original;
        }
        return original;
    }
};