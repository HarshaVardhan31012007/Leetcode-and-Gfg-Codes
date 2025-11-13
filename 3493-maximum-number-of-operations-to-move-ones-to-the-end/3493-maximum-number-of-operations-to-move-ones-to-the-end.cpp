class Solution {
public:
    int maxOperations(string s) {
        int ans=0;
        int i=0;
        int prev=0;
        while(i<s.length()){
            int c=0;
            if(s[i]=='1'){
                while(i<s.length()&&s[i]=='1'){
                    c++;i++;
                }
                if(i<s.length()&&s[i]=='0'){
                    ans+=prev+c;
                    prev=prev+c;
                }
            }
            i++;
        }
        return ans;
    }
};