class Solution {
public:
    void sortColors(vector<int>& nums) {
       // sort(nums.begin(),nums.end());


       int zc=0;int oc=0;int tc=0;
       for(auto &num:nums){
        if(num==0)
        zc++;
        else if(num==1)
        oc++;
        else
        tc++;
       }
       fill(nums.begin(),nums.begin()+zc,0);
       fill(nums.begin()+zc,nums.begin()+zc+oc,1);
       fill(nums.begin()+zc+oc,nums.end(),2);
    }
};