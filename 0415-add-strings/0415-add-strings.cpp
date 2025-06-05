class Solution {
public:
    string solve(string &num1,string &num2,int i,int j,int carry){
        if(i<0&&j<0&&!carry) return "";
        int n1=i>=0?num1[i]-'0':0;
        int n2=j>=0?num2[j]-'0':0;
        int sum=n1+n2+carry;
        carry=sum/10;
        char ch=sum%10+'0';
        return solve(num1,num2,i-1,j-1,carry)+ch;
    }
    string addStrings(string num1, string num2) {
        // string ans="";
        // int i=num1.length()-1;int j=num2.length()-1;
        // int carry=0;
        // while(i>=0&&j>=0){
        //     int sum=(num1[i--]-'0')+(num2[j--]-'0')+carry;
        //     ans+=(sum%10)+'0';
        //     carry=sum/10;
        // }
        // while(i>=0){
        //     int sum=(num1[i--]-'0')+carry;
        //     ans+=(sum%10)+'0';
        //     carry=sum/10;
        // }
        // while(j>=0){
        //     int sum=carry+(num2[j--]-'0');
        //     ans+=(sum%10)+'0';
        //     carry=sum/10;
        // }
        // if(carry)
        // ans+=carry+'0';
        // reverse(ans.begin(),ans.end());
        // return ans;


        // string ans="";
        // int i=num1.length()-1;int j=num2.length()-1;
        // int carry=0;
        // while(i>=0||j>=0||carry){
        //     int a=i>=0?num1[i--]-'0':0;
        //     int b=j>=0?num2[j--]-'0':0;
        //     int sum=a+b+carry;
        //     ans+=sum%10+'0';
        //     carry=sum/10;
        // }
        // reverse(ans.begin(),ans.end());
        // return ans;

        
        return solve(num1,num2,num1.size()-1,num2.size()-1,0);
    }
};