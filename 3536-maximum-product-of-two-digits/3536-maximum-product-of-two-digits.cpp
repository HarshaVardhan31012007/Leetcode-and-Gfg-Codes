class Solution {
public:
    int maxProduct(int n) {
        int maxi=INT_MIN;
        int secondmaxi=INT_MIN;
        int c=0;
        int x=n;
        while(x){
            int digit=x%10;
            if(maxi<digit){
                secondmaxi=maxi;
                maxi=digit;
                c=0;
            }
            if(maxi==digit) c++;
            if(digit!=maxi&&secondmaxi<digit){
                secondmaxi=digit;
            }
            x/=10;
        }
        if(c>1) return maxi*maxi;
        return maxi*secondmaxi;
    }
};