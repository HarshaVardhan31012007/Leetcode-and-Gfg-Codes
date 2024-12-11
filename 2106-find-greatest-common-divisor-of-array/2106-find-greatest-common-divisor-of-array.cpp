class Solution {
public:
    int findGCD(vector<int>&nums) {
        int a=INT_MAX;
        int b=INT_MIN;
        for(int i=0;i<nums.size();i++){
            a=min(a,nums[i]);
            b=max(b,nums[i]);
        }
        if(a==0) return b;
        if(b==0) return a;
        while(a>0&&b>0){
            if(a>b)
            a=a-b;
            else
            b=b-a;
        }
        return (a==0)?b:a;
            }
};