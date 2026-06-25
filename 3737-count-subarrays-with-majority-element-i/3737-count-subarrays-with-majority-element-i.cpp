class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<int,int>freq;
            int f=0;int el=-1;
            for(int j=i;j<n;j++){
                freq[nums[j]]++;
                if(f==0){
                    el=nums[j];
                }
                if(el==nums[j]){
                    f++;
                }
                else{
                    f--;
                }
                int len=(j-i+1);
                if(freq[el]>len/2){
                    if(el==target){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};