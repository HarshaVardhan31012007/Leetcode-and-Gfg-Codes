class Solution {
public:
    int smallestNumber(int n) {
        int x=ceil(log2(n+1));
        return pow(2,x)-1;
    }
};