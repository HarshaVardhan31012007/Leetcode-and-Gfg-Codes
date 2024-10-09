class Solution {
public:
    int singleNumber(vector<int>& nums) {

        unordered_map<int,int>freqmap;

        for(int i=0;i<nums.size();i++)
        {
            int num=nums[i];
            freqmap[num]=freqmap[num]+1;
        }
        int ans;
        for(int i=0;i<nums.size();i++)
        {   int num=nums[i];
            if(freqmap[num]==1){
                ans=num;
        }

        return ans;

    }

}; 
