class Solution {
public:
    int maxProduct(int n) {
        int maxi=INT_MIN;
        int secondmaxi=INT_MIN;
        int x=n;
        while(x){
            int digit=x%10;
            if(maxi<=digit){
                secondmaxi=maxi;
                maxi=digit;
            }
            else if(digit>secondmaxi){
                secondmaxi=digit;
            }
            x/=10;
        }
        return maxi*secondmaxi;
    }
};