class Solution {
public:
    int getSum(int a, int b) {
        int ans=0;int carry=0;
        for(int i=0;i<32;i++){
            int a_one=((a>>i)&1);
            int b_one=((b>>i)&1);
            int carry_one=((carry)&1);
            carry=((a_one&&b_one)||(b_one&&carry_one)||(carry_one&&a_one));
            int curr_one=(a_one^b_one^carry_one);
            if(curr_one)
            ans=ans|(1<<i);
        }
        return ans;
    }
};