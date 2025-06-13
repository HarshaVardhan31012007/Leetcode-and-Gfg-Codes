class Solution {
public:
    int hammingWeight(int n) {
    //    int count=0;
    //    while(n){
    //     if(n%2==1) count++;
    //     n=n/2;
    //    } 
    //    return count;

     int count=0;
       while(n){
        if((n&1)==1) count++;
        n=n>>1;
       } 
       return count;
    }
};