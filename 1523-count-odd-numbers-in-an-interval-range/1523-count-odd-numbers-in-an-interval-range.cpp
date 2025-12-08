class Solution {
public:
    int countOdds(int low, int high) {
        // int i=low;
        // int j=high;
        // int ans=0;
        // while(i<=j){
        //     if(i&1)
        //     ans++;
        //     i++;
        // }
        // return ans;


        // int i=low;
        // int j=high;
        // int ans=0;
        // while(i<=j){
        //     if(i%2==1)
        //     ans++;
        //     i++;
        // }
        // return ans;


        // bool olow=(low&1);
        // bool ohigh=(high&1);
        // if(olow&&!ohigh||!olow&&ohigh)
        // return (high-low+1)/2;
        // if(olow&&ohigh) return (high-low+1)/2+1;
        // else
        // return (high-low+1)/2;


        bool olow=(low&1);
        bool ohigh=(high&1);
        
        if(olow&&ohigh) return (high-low+1)/2+1;
        
        return (high-low+1)/2;
    }
};