class Solution {
public:
     void nextGreater(vector<int>& nums2,vector<int>&nextg){
         stack<int>s;
         s.push(INT_MAX);
         for(int i=nums2.size()-1;i>=0;i--){
            while(s.top()<=nums2[i]){
                s.pop();
            }
            if(s.top()!=INT_MAX)
            nextg.push_back(s.top());
            else
            nextg.push_back(-1);
            s.push(nums2[i]);
         }
    }
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        nums.push_back(nums[i]);
        vector<int>nextg; 
        nextGreater(nums,nextg);
        return vector(nextg.rbegin(),nextg.rbegin()+n);
    }
};