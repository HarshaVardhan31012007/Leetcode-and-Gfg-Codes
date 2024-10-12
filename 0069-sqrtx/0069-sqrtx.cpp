class Solution {
public:
    int mySqrt(int x) {
        int ans;
           int s=0;
           int e=x;
           long long  mid=s+(e-s)/2;//lonhg lonhg int
            while(s<=e){
               //long long int product=mid*mid;
                if(mid*mid==x)
                return mid;

                if(mid*mid<x){
                //ans=abs(mid);
                ans=mid;
                s=mid+1;
                }
                
                else
                e=mid-1;

                mid=s+(e-s)/2;
            }
        
        return ans;
    }
};