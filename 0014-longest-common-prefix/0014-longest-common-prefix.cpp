class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string output="";
         int i=0;
        while(true){
            char ch=0;
            for(int j=0;j<strs.size();j++){
                if(i>=strs[j].size()){
                    ch=0;break;
                }
                if(ch==0)
                ch=strs[j][i];
                if(ch!=strs[j][i]){
                    ch=0;
                    break;
                }
            }
            if(ch==0)
            break;
            output+=ch;
            i++;
        }
        return output;
    }
};