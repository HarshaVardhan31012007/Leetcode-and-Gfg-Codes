class Solution {
public:
    bool solve(vector<int>&nums,vector<int>&quantity,int i){
    if(i==quantity.size()) return true;
        for(auto &num:nums){
            if(num>=quantity[i]){
                num-=quantity[i];
                if(solve(nums,quantity,i+1))
                return true;
                else
                num+=quantity[i];
            }
        }
        return false;
    }
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        sort(quantity.rbegin(),quantity.rend());
        map<int,int>mpp;
        for(auto &num:nums){
            mpp[num]++;
        }
        vector<int>freq;
        for(auto &mp:mpp){
            freq.push_back(mp.second);
        }
        return solve(freq,quantity,0);
    }
};