class Solution {
public:
    void find(string &s,int i,int j,int &st,int &e,int &l){
        while(i>=0&&j<s.length()&&s[i]==s[j]){
            i--;j++;
        }
        if((j-i-1)>l){
            l=(j-i-1);
            st=i+1;
            e=j-1;
        }
    }
    string longestPalindrome(string s) {
        int n=s.length();
        int start=-1;int end=-1;int len=INT_MIN;
        for(int i=0;i<n;i++){
             find(s,i,i,start,end,len);
             find(s,i,i+1,start,end,len);
        }
        return s.substr(start,end-start+1);
    }
};