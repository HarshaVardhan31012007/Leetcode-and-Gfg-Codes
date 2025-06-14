class Solution {
public:
    int findComplement(int num) {
        int ans=0;long c=1;
        while(num!=0){
            int digit=num%2;
            if(digit==0)
            ans+=c;
            c=c*2;
            num=num/2;
        }
        return ans;
    }
};