class Solution {
public:
    int triangularSum(vector<int>& nums) {
        // while(nums.size()>1){
        //     for(int i=0;i<nums.size()-1;i++){
        //         nums[i]=(nums[i]+nums[i+1])%10;
        //     }
        //     nums.pop_back();
        // }
        // return nums[0];

        queue<int>q;
        for(int i=0;i<nums.size();i++){
            q.push(nums[i]);
        }
        while(q.size()>1){
            int size=q.size();
            for(int i=0;i<size-1;i++){
                int front=q.front();
                q.pop();
                q.push((front+q.front())%10);
            }
            q.pop();
        }
        return q.front();
    }
};