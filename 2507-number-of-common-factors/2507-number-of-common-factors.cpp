class Solution {
public:
    int commonFactors(int a, int b) {
        // int c=min(a,b);int count=0;
        // for(int i=1;i<=c;i++){
        //     if(a%i==0&&b%i==0){
        //         count++;
        //     }
        // }
        // return count;

        // if(a>b){
        //     a=a^b;
        //     b=a^b;
        //     a=a^b;
        // }
        int count=0;
        for(int i=1;i<=sqrt(a);i++){
            if(a%i==0){
                if(b%i==0)
                count++;
                int d=a/i;
                if(d!=i&&a%d==0&&b%d==0)
                count++;
            }
        }
        return count;
    }
};