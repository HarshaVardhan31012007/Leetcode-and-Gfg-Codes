class Solution {
public:
    bool isBalanced(int n){
        vector<int>digits(10,0);
        int k=n;
        while(k){
            digits[k%10]++;
            k=k/10;
        }
        for(int i=0;i<10;i++){
            if(digits[i]!=0&&digits[i]!=i)
            return 0;
        }
        return 1;
    }
    int nextBeautifulNumber(int n) {
        for(int i=n+1;i<=1224444;i++){
             if(isBalanced(i))
             return i;
        }
        return -1;
    }
};