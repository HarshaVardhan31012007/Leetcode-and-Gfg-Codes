class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_map<string,bool>mpp;
        for(auto &each:dictionary){
            mpp[each]=1;
        }
        string ans="";
        for(int i=0;i<sentence.length();i++){
            string temp="";
            bool flag=1;
            while(i<sentence.length()&&sentence[i]!=' '){
                temp+=sentence[i++];
                if(flag&&mpp.count(temp)){
                    if(ans.empty())
                    ans+=temp;
                    else
                    ans+=" "+temp;
                    flag=0;
                }
            }
            if(flag){
                if(ans.empty())
                ans+=temp;
                else
                ans+=" "+temp;
            }
        }
        return ans;
    }
};