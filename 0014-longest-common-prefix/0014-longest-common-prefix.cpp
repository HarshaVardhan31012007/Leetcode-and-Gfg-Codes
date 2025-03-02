class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // string output="";int mini=INT_MAX;
        // for(int i=0;i<strs.size();i++){
        //     int p=strs[i].size();
        //     mini=min(mini,p);
        // }
        // if(mini==INT_MAX) mini=0;
        // for(int i=0;i<mini;i++){
        //     bool issame=true;
        //     char ch=strs[0][i];
        //     for(int j=1;j<strs.size();j++){
        //         if(strs[j][i]!=ch){
        //         issame=false;
        //         break;
        //         }
        //     }
        //     if(issame)
        //     output+=ch;
        //     else
        //     break;
        // }
        // return output;

        //not correct out of bound access karta hai
        // string output="";
        // for(int i=0;i<strs[0].size();i++){
        //     bool issame=true;
        //     char ch=strs[0][i];
        //     for(int j=1;j<strs.size();j++){
        //         if(strs[j][i]!=ch){
        //         issame=false;
        //         break;
        //         }
        //     }
        //     if(issame)
        //     output+=ch;
        //     else
        //     break;
        // }
        // return output;



        string output="";
        int i=0;
        while(true){
            char ch=0;
            for(int j=0;j<strs.size();j++){
                if(i>=strs[j].size()){
                    ch=0;
                    break;
                }
                if(ch==0){
                    ch=strs[j][i];
                }
                else if(strs[j][i]!=ch){
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