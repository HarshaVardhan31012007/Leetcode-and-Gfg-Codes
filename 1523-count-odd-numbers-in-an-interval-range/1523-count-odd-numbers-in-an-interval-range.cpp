class Solution {
public:
    int countOdds(int low, int high) {
        int i=low;
        int j=high;
        int ans=0;
        while(i<=j){
            if(i&1)
            ans++;
            i++;
        }
        return ans;
    }
};