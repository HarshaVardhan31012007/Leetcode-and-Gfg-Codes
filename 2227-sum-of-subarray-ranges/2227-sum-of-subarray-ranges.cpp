class Solution {
public:
    void nextSmaller(vector<int>&nums,vector<long long int>&nexts){
        stack<long long int>s;
        s.push(nums.size());
        for(long long int i=nums.size()-1;i>=0;i--){
            while(s.top()!=nums.size()&&nums[s.top()]>nums[i]){
                s.pop();
            }
            nexts.push_back(s.top());
            s.push(i);
         }
    }
    void prevSmaller(vector<int>&nums,vector<long long int>&prevs){
           stack<int>s;
           s.push(-1);
           for(int i=0;i<nums.size();i++){
            while(s.top()!=-1&&nums[s.top()]>=nums[i]){
                s.pop();
            }
            prevs.push_back(s.top());
            s.push(i);
           }
    }
    void nextGreater(vector<int>&nums,vector<long long int>&nextg){
        stack<int>s;
        s.push(nums.size());
        for(int i=nums.size()-1;i>=0;i--){
            while(s.top()!=nums.size()&&nums[s.top()]<nums[i]){
                s.pop();
            }
            nextg.push_back(s.top());
            s.push(i);
        }
    }
    void prevGreater(vector<int>&nums,vector<long long int>&prevg){
        stack<int>s;
        s.push(-1);
        for(int i=0;i<nums.size();i++){
            while(s.top()!=-1&&nums[s.top()]<=nums[i]){
                s.pop();
            }
            prevg.push_back(s.top());
            s.push(i);
        }
    }
    long long subArrayRanges(vector<int>& nums) {
        vector<long long int>nexts;
        vector<long long int>prevs;
        vector<long long int>nextg;
        vector<long long int>prevg;
        nextSmaller(nums,nexts);
        reverse(nexts.begin(),nexts.end());
        prevSmaller(nums,prevs);
        nextGreater(nums,nextg);
        reverse(nextg.begin(),nextg.end());
        prevGreater(nums,prevg);
        long long int large=0;
        long long int small=0;
        for(long long int i=0;i<nums.size();i++){
            small+=((long long)nums[i])*(i-prevs[i])*(nexts[i]-i);
            large+=(long long)nums[i]*(i-prevg[i])*(nextg[i]-i);
        }
        return large-small;
    }
};