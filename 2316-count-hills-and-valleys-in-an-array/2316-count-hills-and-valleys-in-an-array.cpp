class Solution {
public:
    int countHillValley(vector<int>& nums) {
        if(nums.size()<3) return 0;
        int count=0;
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]==nums[i-1])
            continue;

            int left=0;int right=0;
            // for(int j=i-1;j>=0;j--){
            //     if(nums[j]>nums[i]){
            //     left=-1;
            //     break;
            //     }
            //     else if(nums[j]<nums[i]){
            //         left=1;
            //         break;
            //     }
            // }
            // for(int j=i+1;j<nums.size();j++){
            //     if(nums[j]>nums[i]){
            //         right=-1;
            //         break;
            //     }
            //     else if(nums[j]<nums[i]){
            //         right=1;
            //         break;
            //     }
            // }
            int j=i-1;int k=i+1;
            while(1){
                 if(j>=0&&nums[j]>nums[i]){
                    left=-1;
                    j=-1;
                 }
                 else if(j>=0&&nums[j]<nums[i]){
                    left=1;
                    j=-1;
                 }
                 if(k<nums.size()&&nums[k]>nums[i]){
                    right=-1;
                    k=nums.size();
                 }
                 else if(k<nums.size()&&nums[k]<nums[i]){
                    right=1;
                    k=nums.size();
                 }
                 if(j==-1&&k==nums.size()) break;
                 if(j!=-1)
                 j--;
                 if(k!=nums.size())
                 k++;
            }

            if(left==right&&left!=0)
            count++;
        }
        return count;
    }
};