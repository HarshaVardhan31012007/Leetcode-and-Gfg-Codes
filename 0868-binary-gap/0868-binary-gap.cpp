class Solution {
public:
    // int binaryGap(int n) {
    //       int num=n;
    //       int prev=-1;
    //       int ans=0;int c=0;
    //       while(num>0){
    //         int bit=num%2;
    //         if(bit==1){
    //             if(prev!=-1)
    //                ans=max(ans,c-prev);
    //             prev=c;
    //         }
    //         c++;
    //         num=num/2;
    //       }
    //       return ans;
    // }


    // int binaryGap(int n) {
    //       int num=n;
    //       int prev=-1;
    //       int ans=0;int c=0;
    //       while(num>0){
    //         int bit=(num&1);
    //         if(bit==1){
    //             if(prev!=-1)
    //                ans=max(ans,c-prev);
    //             prev=c;
    //         }
    //         c++;
    //         num=num>>1;
    //       }
    //       return ans;
    // }



     int binaryGap(int n) {
         int ans=0;
         int prev=-1;
         for(int i=0;i<32;i++){
            if(((n>>i)&1)==1){
            if(prev!=-1)
               ans=max(ans,i-prev);
               prev=i;
            }
         }
         return ans;
    }
};