class Solution {
public:
    // int digits(int x){
    //     if(x==0) return 1;
    //     return (int)log10(x)+1;
    // }
    // vector<int> sequentialDigits(int low, int high) {
    //     int l=digits(low);
    //     int r=digits(high);
    //     vector<int>ans;
    //     for(int i=l;i<=r;i++){
    //         int start=1;
    //         while(start<=9){
    //             int times=i;
    //             int digit=start;
    //             int num=0;
    //             bool flag=true;
    //             while(times--){
    //                 if(digit>9||num>INT_MAX/10){
    //                     flag=false;
    //                     break;
    //                 }
    //                 num=num*10+digit;
    //                 digit++;
    //             }
    //             if(flag&&num>=low&&num<=high)
    //             ans.push_back(num);
    //             start++;
    //         }
    //     }
    //     return ans;
    // }



    
    // vector<int> sequentialDigits(int low, int high) {
    //     vector<int>ans;
    //     for(int length=2;length<=9;length++){
    //         for(int first=1;first+length<=10;first++){
    //             int val=0;
    //             for(int digit=first;digit<first+length;digit++){
    //                 val=val*10+digit;
    //             }
    //             if(val>=low&&val<=high)
    //             ans.push_back(val);
    //         }
    //     }
    //     return ans;
    // }


    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        queue<int>q;
        for(int i=1;i<10;i++){
           q.push(i);
        }
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int front=q.front();
                cout<<front<<endl;
                q.pop();
                if(i<size-1){
                    q.push(front*10+q.front()%10);
                }
                if(front>=low&&front<=high)
                ans.push_back(front);
            }
        }
        return ans;
    }
};