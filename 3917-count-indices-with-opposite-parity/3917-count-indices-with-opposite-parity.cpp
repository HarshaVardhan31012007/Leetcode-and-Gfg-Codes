class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n=nums.size();
        vector<int>score(n);
        int odd=0;
        int even=0;
        for(int i=n-1;i>=0;i--){
           if(nums[i]&1){
              score[i]=even;
           }
           else
           score[i]=odd;
           if(nums[i]&1) odd++;
           else even++;
        }
        return score;
    }
};