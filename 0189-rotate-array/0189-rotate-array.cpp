class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        vector<int>temp(n);
        int index=0;
        for(int i=n-k;i<n;i++){
            temp[index]=nums[i];
            index++;
        }
        for(int i=n-1;i>=k;i--){
            nums[i]=nums[i-k];
        }
        for(int i=0;i<k;i++){
            nums[i]=temp[i];
        }
    }
};