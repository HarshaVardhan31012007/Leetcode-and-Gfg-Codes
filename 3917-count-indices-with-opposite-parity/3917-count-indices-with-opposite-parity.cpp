class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n=nums.size();
        vector<int>score(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((nums[i]^nums[j])&1){
                    score[i]++;
                }
            }
        }
        return score;
    }
};