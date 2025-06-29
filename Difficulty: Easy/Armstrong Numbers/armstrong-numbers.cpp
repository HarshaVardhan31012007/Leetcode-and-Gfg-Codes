// User function Template for C++
class Solution {
  public:
    bool armstrongNumber(int n) {
        int ans=n;
         while(n>0){
             int digit=n%10;
             ans=ans-(digit*digit*digit);
             if(ans<0)
             return false;
             n=n/10;
         }
         return ans==0;
    }
};