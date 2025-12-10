class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i=0;
        string ans="";
        while(1){
            char ch=0;
            for(int j=0;j<strs.size();j++){
                if(i>=strs[j].length()) return ans;
                if(ch==0)
                ch=strs[j][i];
                else{
                    if(ch!=strs[j][i]) return ans;
                }
            }
            ans+=strs[0][i];
            i++;
        }
        return "";
    }
};