class Solution {
public:
    void sortColors(vector<int>& nums) {
       // sort(nums.begin(),nums.end());


    //    int zc=0;int oc=0;int tc=0;
    //    for(auto &num:nums){
    //     if(num==0)
    //     zc++;
    //     else if(num==1)
    //     oc++;
    //     else
    //     tc++;
    //    }
    //    fill(nums.begin(),nums.begin()+zc,0);
    //    fill(nums.begin()+zc,nums.begin()+zc+oc,1);
    //    fill(nums.begin()+zc+oc,nums.end(),2);

      int l=0;
      int m=0;
      int h=nums.size()-1;
      while(m<=h){
        if(nums[m]==0){
            swap(nums[m],nums[l]);
            l++;m++;
        }
        else if(nums[m]==1)
        m++;
        else 
        swap(nums[m],nums[h--]);
      }
    }
};