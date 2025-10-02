class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        //         int a,b,c;
        //         int count=0;
        //         for(int i=0;i<nums.size();i++){
        //             a=nums[i];
        //             for(int j=i+1;j<nums.size();j++){
        //                   b=nums[j];
        //                  for(int k=j+1;k<nums.size();k++){
        //                   c=nums[k];
        //                      if(a+b>c&&b+c>a&&c+a>b)
        // count++;
        //                  }
        //                 }
        //         }
        //         return count;



        //  sort(nums.begin(),nums.end());
        //  int i=0;
        //  int count=0;
        //  while(i<nums.size()){
        //     int j=nums.size()-1;
        //     while(j>i+1){
        //     for(int k=i+1;k<j;k++){
        //         if(nums[i]+nums[k]>nums[j]){
        //               count+=j-k;
        //               break;
        //         }
        //     }
        //     j--;
        //     }
        //     i++;
        //  }
        //  return count;

         
        //  if(nums.size()<3) return 0;
        //  sort(nums.begin(),nums.end());
        //  int count=0;
        //  for(int i=0;i<=nums.size()-3;i++){//int unsigned int if -ve it goes to +ve value (circle ) // so handle base case
        //     for(int j=nums.size()-1;j>=i+2;j--){
        //         if(nums[i]==0) continue;
        //         auto it=upper_bound(nums.begin()+i+1,nums.begin()+j,nums[j]-nums[i]);
        //         if(it!=nums.begin()+j){
        //             count+=nums.begin()+j-it;
        //         }
        //     }
        //  }
        //  return count;

        sort(nums.begin(),nums.end());
        if(nums.size()<3) return 0;
         int count=0;
        for(int k=2;k<=nums.size()-1;k++){
            int j=k-1;
            int i=0;
            while(i<j){
                if(nums[i]+nums[j]>nums[k]){
                    count+=j-i;
                    j--;
                }
                else
                i++;
            }
        }
        return count;
    }
};