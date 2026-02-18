class Solution {
public:
    // bool hasAlternatingBits(int n) {
    //     bool check=true;
    //     int prev=-1;
    //     while(n){
    //         int bit=n%2;
    //         if(prev!=-1&&bit!=1-prev){
    //            check=false;
    //            break;
    //         }
    //         prev=bit;
    //         n=n/2;
    //     }
    //     return check;
    // }


    bool hasAlternatingBits(int n) {
        if(n%2==1){
            double k=log2(n*3LL+1)/2.0;
            if(k==(int)k) return true;
        }
        else{
           double k=log2((n*3LL+2)/2.0)/2.0;
           if(k==(int)k) return true;
        }
        return false;
    }
};