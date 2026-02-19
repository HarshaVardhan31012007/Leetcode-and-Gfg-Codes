class Solution {
public:
    int countBinarySubstrings(string s) {
        // int c1=0;
        // int c2=0;
        // int ans=0;
        // for(int i=0;i<s.length();i++){
        //     int j=i;int c1=0;int c2=0;
        //     while(j<s.length()&&s[j]=='0') j++,c1++;
        //     while(j<s.length()&&s[j]=='1') j++,c2++;
        //     ans+=min(c1,c2);
        //     i=j-1;
        // }
        // for(int i=0;i<s.length();i++){
        //     int j=i;int c1=0;int c2=0;
        //     while(j<s.length()&&s[j]=='1') j++,c1++;
        //     while(j<s.length()&&s[j]=='0') j++,c2++;
        //     ans+=min(c1,c2);
        //     i=j-1;
        // }
        // return ans;


        int prevc=0;int currc=1;
        int ans=0;
        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1]){
                currc++;
            }
            else{
                ans+=min(prevc,currc);
                prevc=currc;
                currc=1;
            }
        }
        ans+=min(prevc,currc);
        return ans;
    }
};