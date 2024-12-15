class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // vector<int>ans;
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     int product=1;
        //    for(int j=0;j<n;j++){
        //     if(i!=j)
        //     product=product*nums[j];
        //    }
        //    ans.push_back(product);
        // }
        // return ans;

        //method 2
        //find product of total numbers and then divide with nums[i]
        //method 3
        // vector<int>ans;
        // int n=nums.size();
        // vector<int>prefix(n,1);
        // vector<int>suffix(n,1);
        // for(int i=1;i<n;i++){
        //     prefix[i]=prefix[i-1]*nums[i-1];
        // }
        // for(int i=n-2;i>=0;i--){
        //     suffix[i]=suffix[i+1]*nums[i+1];
        // }
        // for(int i=0;i<n;i++){
        //    ans[i]=prefix[i]*suffix[i];
        // }
        // return ans;
        //method 4
        int n=nums.size();
        vector<int>ans(n,1);
        for(int i=1;i<n;i++){
            ans[i]=ans[i-1]*nums[i-1];
        }
        int suffix=1;
        for(int i=n-2;i>=0;i--){
            suffix*=nums[i+1];
            ans[i]*=suffix;
        }
        return ans;
    }
};