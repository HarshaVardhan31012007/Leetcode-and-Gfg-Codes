class Solution {
public:
    // vector<int> sortByBits(vector<int>& arr) {
    //     sort(arr.begin(),arr.end(),[&](int a,int b){
    //         int c1=__builtin_popcount(a);
    //         int c2=__builtin_popcount(b);
    //         if(c1!=c2)
    //         return c1<c2;
    //         return a<b;
    //     });
    //     return arr;
    // }

     int calculateSetBits(int num){
        int setbits=0;
        while(num>0){
            setbits++;
            num=(num&(num-1));
        }
        return setbits;
     }
     vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),[&](int a,int b){
            int c1=calculateSetBits(a);
            int c2=calculateSetBits(b);
            if(c1!=c2)
            return c1<c2;
            return a<b;
        });
        return arr;
    }
};