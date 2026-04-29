class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int j=n/2;
        if(n&1) j++;
        int init=j;
        int i=init-1;
        j=n-1;
        vector<int>arr;
        while(i>=0&&j>=init){
            arr.push_back(nums[i]);
            arr.push_back(nums[j]);
            i--;
            j--;
        }
        if(i>=0){
            arr.push_back(nums[i]);
            i--;
        }
        for(int i=0;i<n;i++)
        nums[i]=arr[i];
    }
};