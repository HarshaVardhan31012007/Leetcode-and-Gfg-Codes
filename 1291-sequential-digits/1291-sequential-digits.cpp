class Solution {
public:
    int digits(int x){
        if(x==0) return 1;
        return (int)log10(x)+1;
    }
    vector<int> sequentialDigits(int low, int high) {
        int l=digits(low);
        int r=digits(high);
        vector<int>ans;
        for(int i=l;i<=r;i++){
            int start=1;
            while(start<=9){
                int times=i;
                int digit=start;
                int num=0;
                bool flag=true;
                while(times--){
                    if(digit>9||num>INT_MAX/10){
                        flag=false;
                        break;
                    }
                    num=num*10+digit;
                    digit++;
                }
                if(flag&&num>=low&&num<=high)
                ans.push_back(num);
                start++;
            }
        }
        return ans;
    }
};