class Solution {
public:
    // string addHelp(string &ans,string &temp){
    //     int n=ans.length();
    //     int m=temp.length();
    //     string temp1="";
    //     int carry=0;
    //     n--;
    //     m--;
    //     while(n>=0&&m>=0){
    //         int digit=((ans[n]-'0')+(temp[m]-'0')+carry)%10;
    //         carry=((ans[n]-'0')+(temp[m]-'0')+carry)/10;
    //         temp1+=(digit+'0');
    //         n--;
    //         m--;
    //     }
    //     while(n>=0){
    //         int digit=((ans[n]-'0')+carry)%10;
    //         carry=((ans[n]-'0')+carry)/10;
    //         temp1+=(digit+'0');
    //         n--;
    //     }
    //     while(m>=0){
    //         int digit=((temp[m]-'0')+carry)%10;
    //         carry=((temp[m]-'0')+carry)/10;
    //         temp1+=(digit+'0');
    //         m--;
    //     }
    //     if(carry)  temp1+=(carry+'0');
    //     reverse(temp1.begin(),temp1.end());
    //     return temp1;
    // }
    // string multiply(string num1, string num2) {
    //     if(num1=="0"||num2=="0") return "0";
    //     string ans="";
    //     int n1=num1.length();int n2=num2.length();
    //     string zeros="";
    //     for(int i=n2-1;i>=0;i--){
    //        string temp="";
    //        int carry=0;
    //        for(int j=n1-1;j>=0;j--){
    //             int p=(num2[i]-'0')*(num1[j]-'0');
    //             int cdigit=(p+carry)%10;
    //             carry=(p+carry)/10;
    //             temp+=(cdigit+'0');
    //        }
    //        if(carry) temp+=(carry+'0');
    //        reverse(temp.begin(),temp.end());
    //        if(ans.empty()) ans=temp;
    //        else{
    //          temp+=zeros;
    //          ans=addHelp(ans,temp); 
    //        }
    //        zeros+="0";
    //     }
    //     return ans;
    // }



    
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0") return "0";
        if(num1=="1") return num2;
        if(num2=="1") return num1;
        int n=num1.length();int m=num2.length();
        vector<int>result(n+m,0);
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                  int curr=((num1[i]-'0')*(num2[j]-'0')+result[i+j+1])%10;
                  int carry=((num1[i]-'0')*(num2[j]-'0')+result[i+j+1])/10;
                  result[i+j+1]=curr;
                  result[i+j]+=carry;
            }
        }
        string ans="";
        int i=0;
        while(i<n+m&&result[i]==0) i++;
        while(i<n+m){
            ans+=(result[i]+'0');
            i++;
        }
        return ans;
    }
};