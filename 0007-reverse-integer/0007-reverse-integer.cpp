class Solution {
public:
    int reverse(int x) {
        // int ans=0;
        // while(x){
        //    if(ans>INT_MAX/10||ans<INT_MIN/10)
        //    return 0;
        //    ans=ans*10+x%10;
        //    x=x/10;
        // }
        // return ans;


        int ans=0;
        while(x){
            int digit=x%10;
           if(ans>INT_MAX/10||ans==INT_MAX/10&&digit>7)
           return 0;
           if(ans<INT_MIN/10||ans==INT_MIN/10&&digit<-8)
           return 0;
           ans=ans*10+digit;
           x=x/10;
        }
        return ans;


        // int ans=0;
        // bool flag=0;
        // if(x<0){
        // flag=1;
        // if(x==INT_MIN)
        // return 0;
        // x=-x;
        // }
        // while(x){
        //    if(ans>INT_MAX/10)
        //    return 0;
        //    ans=ans*10+x%10;
        //    x=x/10;
        // }
        // return flag==1?-ans:ans;
    }
};