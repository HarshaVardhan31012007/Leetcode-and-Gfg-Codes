class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int c=0;int sum=0;
            for(int j=1;j<=sqrt(nums[i]);j++){
                if(nums[i]%j==0){
                    c++;
                    sum+=j;
                }
                int x=nums[i]/j;
                if(x!=j&&(nums[i]%x==0)){
                    c++;
                    sum+=x;
                }
            }
            if(c==4)
            ans+=sum;
        }
        return ans;
    }
};