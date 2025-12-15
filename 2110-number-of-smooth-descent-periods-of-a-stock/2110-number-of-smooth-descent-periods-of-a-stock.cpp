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
        //     long long len=j-i;
        //     ans+=(len*(len-1))/2;
        //     i=j;
        //     j++;
        // }
        // return ans+prices.size();



        // int i=0;
        // int j=1;
        // long long ans=0;
        // while(j<prices.size()){
        //     long long len=0;
        //     int k=1;
        //     while(j<prices.size()&&prices[j-1]-prices[j]==1){
        //         len+=k;
        //         k++;
        //         j++;
        //     }
        //     ans+=len;
        //     i=j;
        //     j++;
        // }
        // return ans+prices.size();


        long long count=1;
        long long ans=1;
        for(int i=1;i<prices.size();i++){
            if(prices[i-1]-prices[i]==1)
            count++;
            else
            count=1;
            ans+=count;
        }
        return ans;
    }
};