class Solution {
public:
    int find(int n){
        int p1=1;
        while(n){
            p1=p1*(n%10);
            n=n/10;
        }
        return p1;
    }
    int smallestNumber(int n, int t) {
        int last=n%10;
        int add=10-last;
        for(int i=0;i<=add;i++){
            int newn=n+i;
            int p=find(newn);
            if(p%t==0){
                return newn;
            }
        }
        return -1;
    }
};