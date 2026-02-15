class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int i=a.length()-1;int j=b.length()-1;int carry=0;
        while(i>=0||j>=0||carry){
            int one=i>=0?(a[i]-'0'):0;
            int two=j>=0?(b[j]-'0'):0;
            int sum=one+two+carry;
            int digit=sum%2;
            carry=sum/2;
            ans+=(digit+'0');
            i--;j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};