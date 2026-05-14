class Solution {
public:
    bool isGood(vector<int>& nums) {
        int arr[201]={0};
        int n=nums.size();
        n--;
        for(auto &each:nums){
            if(each>n) return false;
            if(arr[each]==0) arr[each]--;
            else if(each==n&&arr[each]==-1) arr[each]--;
            else return false;
        }
        return true;
    }
};