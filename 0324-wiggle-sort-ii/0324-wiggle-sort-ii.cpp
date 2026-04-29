class Solution {
public:
    //void wiggleSort(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // int n=nums.size();
        // int j=n/2;
        // if(n&1) j++;
        // int init=j;
        // int i=init-1;
        // j=n-1;
        // vector<int>arr;
        // while(i>=0&&j>=init){
        //     arr.push_back(nums[i]);
        //     arr.push_back(nums[j]);
        //     i--;
        //     j--;
        // }
        // if(i>=0){
        //     arr.push_back(nums[i]);
        //     i--;
        // }
        // for(int i=0;i<n;i++)
        // nums[i]=arr[i];
    //}



    int A(int i, int n) {
        return (2 * i + 1) % (n | 1);
    }

    void wiggleSort(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Find median
        auto midPtr = nums.begin() + n / 2;
        nth_element(nums.begin(), midPtr, nums.end());
        int median = *midPtr;

        // Step 2: 3-way partition (Dutch National Flag)
        int i = 0, j = 0, k = n - 1;

        while (j <= k) {
            if (nums[A(j, n)] > median) {
                swap(nums[A(i, n)], nums[A(j, n)]);
                i++;
                j++;
            } 
            else if (nums[A(j, n)] < median) {
                swap(nums[A(j, n)], nums[A(k, n)]);
                k--;
            } 
            else {
                j++;
            }
        }
    }
};