class Solution {
public:
    int totalMoney(int n) {
        int num=n/7;
        int rem=n%7;
        long long sum=28;
        long long prev=sum;
        for(int i=0;i<num-1;i++){
            sum+=prev+7;
            prev=prev+7;
        }
        if(num==0) sum=0;
        int day=num+1;
        while(rem--){
            sum+=day;
            day++;
        }
        return sum;
    }
};