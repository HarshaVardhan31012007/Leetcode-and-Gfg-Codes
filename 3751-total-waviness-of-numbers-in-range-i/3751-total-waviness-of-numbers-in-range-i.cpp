class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans=0;
        for(int num=num1;num<=num2;num++){
             int prev1=-1;int prev2=-1;
             int temp=num;
             while(temp){
                int curr=temp%10;
                if(prev1!=-1&&prev2!=-1&&prev1>prev2&&prev1>curr) ans++;
                if(prev1!=-1&&prev2!=-1&&prev1<prev2&&prev1<curr) ans++;
                temp=temp/10;
                prev2=prev1;
                prev1=curr;
             }
        }
        return ans;
    }
};