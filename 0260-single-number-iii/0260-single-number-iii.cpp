class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int val=0;
        for(auto &each:nums){
            val=(val^each);
        }
        int bit=-1;
        for(int i=0;i<32;i++){
            if((val>>i)&1){
               bit=i;
               break;
            }
        }
        int a=0;
        int b=0;
        for(auto &each:nums){
            if((each>>bit)&1){
                a=(a^each);
            }
            else{
                b=(b^each);
            }
        }
        return {a,b};
    }
};