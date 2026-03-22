class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        // set<int>even;
        // set<int>odd;
        // unordered_map<int,int>mpp;
        // for(auto &each:nums1){
        //     if(each&1){
        //         odd.insert(each);
        //     }
        //     else{
        //         even.insert(each);
        //     }
        //     mpp[each]++;
        // }
        // bool iseven=true;
        // for(int i=0;i<nums1.size();i++){
        //     if(nums1[i]&1){
        //         auto it=odd.lower_bound(nums1[i]);
        //         if(it==odd.begin()){
        //             iseven=false;
        //             break;
        //         }
        //     }
        // }
        // bool isodd=true;
        // for(int i=0;i<nums1.size();i++){
        //     if(nums1[i]%2==0){
        //         auto it=odd.lower_bound(nums1[i]);
        //         if(it==odd.begin()){
        //            isodd=false;
        //             break;
        //         }
        //     }
        // }
        // return iseven||isodd;


        int minEven=INT_MAX;int minOdd=INT_MAX;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]&1) minOdd=min(minOdd,nums1[i]);
            else minEven=min(minEven,nums1[i]);
        }
        if(minEven==INT_MAX||minOdd==INT_MAX) return true;
        if(minEven>minOdd) return true;
        return false;
    }
};