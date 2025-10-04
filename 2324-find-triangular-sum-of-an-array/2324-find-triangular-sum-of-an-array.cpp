class Solution {
public:
    int triangularSum(vector<int>& nums) {

        // queue<int>q;
        // for(int i=0;i<nums.size();i++){
        //     q.push(nums[i]);
        // }
        // while(q.size()>1){
        //     int size=q.size();
        //     for(int i=0;i<size-1;i++){
        //         int front=q.front();
        //         q.pop();
        //         q.push((front+q.front())%10);
        //     }
        //     q.pop();
        // }
        // return q.front();
          
        // vector<int>temp;
        // while(nums.size()>1){
        //     for(int i=0;i<nums.size()-1;i++){
        //         temp.push_back((nums[i]+nums[i+1])%10);
        //     }
        //     nums=move(temp);
        // }
        // return nums[0];

         // while(nums.size()>1){
        //     for(int i=0;i<nums.size()-1;i++){
        //         nums[i]=(nums[i]+nums[i+1])%10;
        //     }
        //     nums.pop_back();
        // }
        // return nums[0];
   
          int size=nums.size();
          while(size>1){
            for(int i=0;i<size-1;i++){
                nums[i]=(nums[i]+nums[i+1])%10;
            }
            size--;
        }
        return nums[0];

            // int n=nums.size();
            // int ans=nums[0];
            // int i=n-1;
            // long long int c=1;
            // for(int j=1;j<=i;j++){
            //     c=c*(i-j+1)/j;
            //     ans+=c*nums[j];
            // }
            // return ans%10;
    }
};