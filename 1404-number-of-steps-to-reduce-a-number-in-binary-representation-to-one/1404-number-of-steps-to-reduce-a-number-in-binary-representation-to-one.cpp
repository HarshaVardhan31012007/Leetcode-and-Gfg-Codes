class Solution {
public:
    int numSteps(string s) {
        //very big binary may 500 len 2 power 500 also possible cant repreasent in int,longlong int etc.,
        
        // long long int num=0;
        // int n=s.length();
        // for(int i=0;i<n;i++){
        //     num=(num<<1LL);
        //     if(s[i]=='1')
        //     num++;
        // }
        // int ans=0;
        // while(num>1){
        //     if(num&1){
        //        num++;
        //     }
        //     else{
        //         num=num/2;
        //     }
        //     ans++;
        // }
        // return ans;




        
        
        // int ans=0;
        // string temp=s;
        // while(temp!="1"){
        //     int size=temp.size();
        //     bool iseven=(temp[size-1]=='0');
        //     if(iseven){
        //        temp.pop_back();
        //     }
        //     else{
        //         bool entered=false;
        //         for(int i=size-1;i>=0;i--){
        //             if(temp[i]=='0'){
        //                 temp[i]='1';
        //                 entered=true;
        //                 break;
        //             }
        //             else{
        //                 temp[i]='0';
        //             }
        //         }
        //         if(!entered){
        //             temp="1"+temp;
        //         }
        //     }
        //     ans++;
        // }
        // return ans;


       
        int ans=0;
        int n=s.length();
        int carry=0;
        for(int i=n-1;i>=1;i--){
            int curr=((s[i]-'0')+carry)%2;
            carry=((s[i]-'0')+carry)/2;
            if(curr==0){
                ans++;
            }
            else{
                carry=1;
                ans+=2;
            }
        }
        if(carry){
            ans+=1;
        }
        return ans;
    }
};