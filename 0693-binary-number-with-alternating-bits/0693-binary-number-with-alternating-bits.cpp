class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool check=true;
        int prev=-1;
        while(n){
            int bit=n%2;
            if(prev!=-1&&bit!=1-prev){
               check=false;
               break;
            }
            prev=bit;
            n=n/2;
        }
        return check;
    }
};