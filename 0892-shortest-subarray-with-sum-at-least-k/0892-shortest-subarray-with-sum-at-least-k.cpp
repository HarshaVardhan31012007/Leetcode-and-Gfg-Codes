class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long>P(n,0);
        P[0]=nums[0];
        for(int i=1;i<n;i++){
            P[i]=P[i-1]+nums[i];
        }
        int minlength=INT_MAX;
        deque<int>dq;
        for(int j=0;j<n;j++){
            //sum from starting to that index
           if(P[j]>=k){
            minlength=min(minlength,j+1);
           }
           //finding minimum length in case between we get ans 
           while(!dq.empty()&&P[j]-P[dq.front()]>=k){
            minlength=min(minlength,j-dq.front());
            dq.pop_front();
           }
           //momotomic queue
           while(!dq.empty()&&P[j]<P[dq.back()]){
            dq.pop_back();
           }
           dq.push_back(j);
        }
        return minlength==INT_MAX?-1:minlength;
    }
};