class Solution {
public:
    //  void nextGreater(vector<int>& nums,vector<int>&nextg){
    //      stack<int>s;
    //      s.push(INT_MAX);
    //      for(int i=nums.size()-1;i>=0;i--){
    //         while(s.top()<=nums[i]){
    //             s.pop();
    //         }
    //         if(s.top()!=INT_MAX)
    //         nextg.push_back(s.top());
    //         else
    //         nextg.push_back(-1);
    //         s.push(nums[i]);
    //      }
    // }
    // vector<int> nextGreaterElements(vector<int>& nums) {
    //     int n=nums.size();
    //     for(int i=0;i<n;i++)
    //     nums.push_back(nums[i]);
    //     vector<int>nextg; 
    //     nextGreater(nums,nextg);
    //     return vector(nextg.rbegin(),nextg.rbegin()+n);
    // }



     void nextGreater(vector<int>& nums,vector<int>&nextg,int &n){
         stack<int>s;
         s.push(INT_MAX);
         for(int i=2*n-1;i>=0;i--){
            int val=nums[i%n];
            while(s.top()<=val){
                s.pop();
            }
            if(s.top()!=INT_MAX)
            nextg.push_back(s.top());
            else
            nextg.push_back(-1);
            s.push(val);
         }
    }
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>nextg; 
        int n=nums.size();
        nextGreater(nums,nextg,n);
        return vector(nextg.rbegin(),nextg.rbegin()+n);
    }
};