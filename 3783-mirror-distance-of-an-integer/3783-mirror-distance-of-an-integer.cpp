class Solution {
public:
    long long rev(int n){
        long long ans=0;
        while(n){
            ans=ans*10+(n%10);
            n=n/10;
        }
        return ans;
    }
    int mirrorDistance(int n) {
        int num=(int)(rev(n));
        return abs(n-num);
    }
};