class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>temp;
        vector<string>ans;
        string temp1="";
        int size=0;
        for(int i=0;i<words.size();i++){
             if(size+words[i].length()<maxWidth){
                size+=words[i].length()+1;
                temp.push_back(words[i]);
             }
             else if(size+words[i].length()==maxWidth){
                 for(auto &each:temp)
                 temp1=temp1+each+" ";
                 temp1+=words[i];
                 ans.push_back(temp1);
                 size=0;
                 temp1="";
                 temp.clear();
             }
             else{
                size--;
                int extraspaces=maxWidth-size;
                int extra=0;
                if(temp.size()>1)
                extra=extraspaces/(temp.size()-1);
                else
                extra=extraspaces;
                int extraOne=0;
                if(temp.size()>1)
                extraOne=(extraspaces%(temp.size()-1));
                if(temp.size()!=1)
                temp1+=temp[0]+" ";
                else
                temp1+=temp[0];
                for(int i=0;i<extra;i++)
                temp1+=" ";
                if(extraOne>0){
                temp1+=" ";
                extraOne--;
                }
                for(int i=1;i<temp.size()-1;i++){
                    temp1+=temp[i]+" ";
                    for(int j=0;j<extra;j++)
                    temp1+=" ";
                    if(extraOne>0){
                    temp1+=" ";
                    extraOne--;
                    }
                }
                if(temp.size()>1)
                temp1+=temp[temp.size()-1];
                ans.push_back(temp1);
                size=words[i].length()+1;
                temp.clear();
                temp1="";
                temp.push_back(words[i]); 
             }
        }
        if(temp.size()==1)
        temp1+=temp[0];
        else{
        for(int i=0;i<temp.size();i++)
        temp1+=temp[i]+" ";
       // temp1+=temp[temp.size()-1];
        }
        if(temp1.length()>0){
        for(int i=temp1.length();i<maxWidth;i++)
        temp1+=" ";
        ans.push_back(temp1);
        }
        return ans;
    }
};