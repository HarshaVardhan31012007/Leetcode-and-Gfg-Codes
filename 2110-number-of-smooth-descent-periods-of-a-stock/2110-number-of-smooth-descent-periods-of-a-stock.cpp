class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        // int i=0;
        // int j=1;
        // long long ans=0;
        // while(j<prices.size()){
        //     while(j<prices.size()&&prices[j-1]-prices[j]==1){
        //         j++;
        //     }
        //     int len=j-i;
        //     ans+=(len*(len-1))/2;
        //     i=j;
        //     j++;
        // }
        // return ans+prices.size();



        int i=0;
        int j=1;
        long long ans=0;
        while(j<prices.size()){
            long long len=0;
            int k=1;
            while(j<prices.size()&&prices[j-1]-prices[j]==1){
                len+=k;
                k++;
                j++;
            }
            ans+=len;
            i=j;
            j++;
        }
        return ans+prices.size();
    }
};