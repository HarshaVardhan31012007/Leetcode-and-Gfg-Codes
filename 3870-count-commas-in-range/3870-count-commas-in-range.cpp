class Solution {
public:
    int find(int n){
        int c=0;
        while(n>0){
            c++;
            n=n/10;
        }
        return c;
    }
    int countCommas(int n) {
        int sum=0;
        for(int i=1000;i<=n;i++){
            int digits=find(i);
            sum+=(digits-1)/3;
        }
        return sum;
    }
};