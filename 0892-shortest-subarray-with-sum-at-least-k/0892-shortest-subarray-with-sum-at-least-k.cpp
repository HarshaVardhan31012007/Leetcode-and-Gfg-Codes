class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
          deque<int>dq;

          vector<long int>prefix(nums.size());
          prefix[0]=nums[0];
          for(int i=1;i<nums.size();i++){
              prefix[i]=nums[i]+prefix[i-1];
          }
          int minLength=INT_MAX;
          for(int j=0;j<nums.size();j++){
              if(prefix[j]>=k) minLength=min(minLength,j+1);
              while(!dq.empty()&&(prefix[j]-prefix[dq.front()]>=k)){
                minLength=min(minLength,j-dq.front());
                dq.pop_front();
              }
              while(!dq.empty()&&prefix[j]<=prefix[dq.back()])
              dq.pop_back();
              dq.push_back(j);
          }
          return minLength==INT_MAX?-1:minLength;
    } 
};