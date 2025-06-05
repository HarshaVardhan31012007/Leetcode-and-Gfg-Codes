class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans="";
        int i=num1.length()-1;int j=num2.length()-1;
        int carry=0;
        while(i>=0&&j>=0){
            int sum=(num1[i--]-'0')+(num2[j--]-'0')+carry;
            ans+=(sum%10)+'0';
            carry=sum/10;
        }
        while(i>=0){
            int sum=(num1[i--]-'0')+carry;
            ans+=(sum%10)+'0';
            carry=sum/10;
        }
        while(j>=0){
            int sum=carry+(num2[j--]-'0');
            ans+=(sum%10)+'0';
            carry=sum/10;
        }
        if(carry)
        ans+=carry+'0';
        reverse(ans.begin(),ans.end());
        return ans;
    }
};