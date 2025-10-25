class Solution {
public:
    int totalMoney(int n) {
        // int start=1;
        // int ans=0;
        // while(n>0){
        //     int money=start;
        //     for(int i=1;i<=min(n,7);i++){
        //           ans+=money;
        //           money++;
        //     }
        //     n=n-7;
        //     start++;
        // }
        // return ans;

    
        // int num=n/7;
        // int rem=n%7;
        // long long sum=28;
        // long long prev=sum;
        // for(int i=0;i<num-1;i++){
        //     sum+=prev+7;
        //     prev=prev+7;
        // }
        // if(num==0) sum=0;
        // int day=num+1;
        // while(rem--){
        //     sum+=day;
        //     day++;
        // }
        // return sum;



        // int rem=n%7;
        // n=n/7;
        // long long int num=28*n+(n*(n-1)*7)/2;
        // int day=n+1;
        // while(rem--){
        //     num+=day;
        //     day++;
        // }
        // return num;


        // int rem=n%7;
        // n=n/7;
        // int first=28;
        // int last=(28+(n-1)*7);
        // int num=(n*(first+last))/2;
        // int day=n+1;
        // while(rem--){
        //     num+=day;
        //     day++;
        // }
        // return num;




        // int rem=n%7;
        // n=n/7;
        // int num=28*n+(n*(n-1)*7)/2;
        // int day=n+1;
        // num+=(rem*(rem+1))/2+(day-1)*rem;
        // return num;



        int rem=n%7;
        n=n/7;
        int first=28;
        int last=(28+(n-1)*7);
        int num=(n*(first+last))/2;
        first=n+1;
        last=first+rem-1;
        num+=rem*(first+last)/2;
        return num;
    }
};