class Solution {
public:
    int maxOperations(string s) {
       int ans=0;int temp=0;
       for(int i=0;i<s.length()-1;i++){
        if(s[i]=='1') temp++;
        if(s[i]=='1'&&s[i+1]=='0')
        ans+=temp;
       }
       return ans;
    }
};