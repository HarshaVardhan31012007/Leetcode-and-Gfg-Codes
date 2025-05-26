class Solution {
public:
    int divide(long dividend, long divisor) {
     if(divisor==dividend) return 1;//no need
     if(dividend==INT_MIN && divisor==-1) return INT_MAX;
        if(dividend==INT_MIN && divisor==1) return INT_MIN;

      long ans;
      long a=abs(dividend);
      long b=abs(divisor);
      long s=0;
      long e=a;
      long mid=s+((e-s)>>1);
    while(s<=e){

      if(mid*b==a){
      ans=mid;
     break;
      }
      if(mid*b<a){
        ans=mid;
        s=mid+1;
      }

     if(mid*b>a){
      e=mid-1;
     }

     mid=s+((e-s)>>1);

    
   }
   
   bool x=true;

   if(dividend>=0 && divisor<0) x=false;
   else if(dividend<=0 && divisor>0) x=false;
    
   
  return (x==0)?-ans:ans;
 
    }
};