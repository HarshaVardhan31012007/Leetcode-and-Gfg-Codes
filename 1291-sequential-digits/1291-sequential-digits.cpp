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


    // vector<int> sequentialDigits(int low, int high) {
    //     vector<int>ans;
    //     queue<int>q;
    //     for(int i=1;i<10;i++){
    //        q.push(i);
    //     }
    //     while(!q.empty()){
    //         int size=q.size();
    //         for(int i=0;i<size;i++){
    //             int front=q.front();
    //             cout<<front<<endl;
    //             q.pop();
    //             if(i<size-1){
    //                 q.push(front*10+q.front()%10);
    //             }
    //             if(front>=low&&front<=high)
    //             ans.push_back(front);
    //         }
    //     }
    //     return ans;
    // }



    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        vector<int>answers={
            12,23,34,45,56,67,78,89,
            123,234,345,456,567,678,789,
            1234,2345,3456,4567,5678,6789,
            12345,23456,34567,45678,56789,
            123456,234567,345678,456789,
            1234567,2345678,3456789,
            12345678,23456789,
            123456789,
        };
        int n=answers.size();
        for(int i=0;i<n;i++){
            if(answers[i]<low) continue;
            if(answers[i]>high) break;
            ans.push_back(answers[i]);
        }
        return ans;
    }
};