class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>mpp;
        sort(arr.rbegin(),arr.rend());
        for(auto &each:arr)
        mpp[each]++;
        for(auto &each:arr){
            if(each==mpp[each])
            return each;
        }
        return -1;
    }
};